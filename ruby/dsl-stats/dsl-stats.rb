# This program reads data from a CenturyLink/ZyXEL C1000Z
# DSL modem, and will eventually post it to Google Docs.
#
# Author::    R. Cody Erben  (mailto:erben22@gmail.com)
# Copyright:: Copyright (c) 2015 Codebets
# License::   TBD

require 'watir-webdriver'
require 'page-object'
require 'rubygems'
require 'time'
require 'fileutils'
require 'google/apis/drive_v3'
require 'google/apis/sheets_v4'
require 'googleauth'
require 'googleauth/stores/file_token_store'

require_relative 'login_page'
require_relative 'index_page'
require_relative 'modem_status_class'

begin
  @main_url = 'http://192.168.2.1'

  #@browser = Watir::Browser.new :firefox
  @browser = Watir::Browser.new :phantomjs

  @browser.goto(@main_url)

  login_page = LoginPage.new(@browser)
  login_page.login_to_system

  index_page = IndexPage.new(@browser)
  index_page.view_modem_status

  modem_status_page = ModemStatusClass.new(@browser)

  modem_status = modem_status_page.get_modem_status
  modem_status = modem_status.merge(modem_status_page.get_dsl_status)
  modem_status = modem_status.merge(modem_status_page.get_internet_status)


  #puts "Complete modem status: #{modem_status}"

  #puts "Hash iteration:"
  #modem_status.each do |key, value|
  #  puts "Key #{key}: #{value}"
  #end

rescue => exception
  puts "Error during processing: #{$!}"
  puts "Backtrace:\n\t#{exception.backtrace.join("\n\t")}"
end

# Now that we have status of the modem in it's current state, let's publish our data...

OOB_URI = 'urn:ietf:wg:oauth:2.0:oob'
APPLICATION_NAME = 'dsl-stats'
CLIENT_SECRETS_PATH = File.join(Dir.home, '.credentials', '.client_secret.json')
CREDENTIALS_PATH = File.join(Dir.home, '.credentials',
                             "drive-dsl-stats.yaml")
@SCOPE = [Google::Apis::DriveV3::AUTH_DRIVE, Google::Apis::SheetsV4::AUTH_SPREADSHEETS]

##
# Ensure valid credentials, either by restoring from the saved credentials
# files or intitiating an OAuth2 authorization. If authorization is required,
# the user's default browser will be launched to approve the request.
#
# @return [Google::Auth::UserRefreshCredentials] OAuth2 credentials
def authorize
  FileUtils.mkdir_p(File.dirname(CREDENTIALS_PATH))

  client_id = Google::Auth::ClientId.from_file(CLIENT_SECRETS_PATH)
  token_store = Google::Auth::Stores::FileTokenStore.new(file: CREDENTIALS_PATH)
  authorizer = Google::Auth::UserAuthorizer.new(
    client_id, @SCOPE, token_store)
  user_id = 'default'
  credentials = authorizer.get_credentials(user_id)
  if credentials.nil?
    url = authorizer.get_authorization_url(
      base_url: OOB_URI)
    puts "Open the following URL in the browser and enter the " +
         "resulting code after authorization"
    puts url
    code = gets
    credentials = authorizer.get_and_store_credentials_from_code(
      user_id: user_id, code: code, base_url: OOB_URI)
  end
  credentials
end

# Initialize the API
service = Google::Apis::SheetsV4::SheetsService.new
service.client_options.application_name = APPLICATION_NAME
service.authorization = authorize

# First worksheet of
# https://docs.google.com/spreadsheets/d/13cxyJLCs_Ynd7MCbmmawaA7lgIIXufnMXmIfOACBdIA/edit#gid=0

spreadsheet_id = '13cxyJLCs_Ynd7MCbmmawaA7lgIIXufnMXmIfOACBdIA'
range = 'Sheet1!A1:ZZ10000'

result = service.get_spreadsheet_values(spreadsheet_id, range)

# Gets content of A1 cell.
puts "Contents of cell A1: #{result.values[0][0]}"

result.values[0][0] = "Time"

# Process the column headers in row 0.
column_index = 1
modem_status.each_key do |key|
  result.values[0][column_index] = key

  # Maybe compare and output info if there is not a match?

  column_index += 1
end

row_index = result.values.length
current_time = Time.now
current_time = current_time.strftime("%Y-%m-%d %H:%M:%S")

result.values.push(Array.new)
result.values[row_index].push(current_time)

modem_status.each do |key, value|
  #puts "Storing value: #{value} in row #{column_index}:#{row_index}"
  result.values[row_index].push(value)
end

result_object = {
  major_dimension: "ROWS",
  values: []
}

result.values.each do |row|
  result_object[:values].push(row)
end

update_result = service.update_spreadsheet_value(spreadsheet_id, range, result_object, value_input_option: 'USER_ENTERED')

puts ">>>>>>>>>> update_result: #{update_result.inspect}"

puts 'All done with the spreadsheet'
@browser.close
