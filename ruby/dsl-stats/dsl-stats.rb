# This program reads data from a CenturyLink/ZyXEL C1000Z
# DSL modem, and will eventually post it to Google Docs.
#
# Author::    R. Cody Erben  (mailto:erben22@gmail.com)
# Copyright:: Copyright (c) 2015 Codebets
# License::   TBD

require 'watir-webdriver'
require 'page-object'
require 'rubygems'
require 'google/api_client'
require 'google_drive'

require_relative 'login_page'
require_relative 'index_page'
require_relative 'modem_status_class'

begin
  @main_url = 'http://192.168.2.1'

  #@browser = Watir::Browser.new :firefox
  #@browser = Watir::Browser.new :phantomjs

  #@browser.goto(@main_url)

  #login_page = LoginPage.new(@browser)
  #login_page.login_to_system

  #index_page = IndexPage.new(@browser)
  #index_page.view_modem_status

  #modem_status_page = ModemStatusClass.new(@browser)

  #modem_status = modem_status_page.get_modem_status
  #modem_status = modem_status.merge(modem_status_page.get_dsl_status)
  #modem_status = modem_status.merge(modem_status_page.get_internet_status)

  #puts "Complete modem status: #{modem_status}"

rescue => exception
  puts "Error during processing: #{$!}"
  puts "Backtrace:\n\t#{exception.backtrace.join("\n\t")}"
end

#@browser.close

# Now that we have status of the modem in it's current state, let's publish our data...

#client = Google::APIClient.new
#auth = client.authorization
# Follow "Create a client ID and client secret" in
# https://developers.google.com/drive/web/auth/web-server] to get a client ID and client secret.

#auth.scope =
#  "https://www.googleapis.com/auth/drive " +
#    "https://spreadsheets.google.com/feeds/"
#auth.redirect_uri = "urn:ietf:wg:oauth:2.0:oob"
#print("1. Open this page:\n%s\n\n" % auth.authorization_uri)
#print("2. Enter the authorization code shown in the page: ")
#auth.code = $stdin.gets.chomp
#auth.fetch_access_token!
#session = GoogleDrive.login_with_oauth(auth.access_token)

session = GoogleDrive.saved_session(

# Gets list of remote files.
#session.files do |file|
#  puts file.title
#end

# First worksheet of
# https://docs.google.com/spreadsheets/d/13cxyJLCs_Ynd7MCbmmawaA7lgIIXufnMXmIfOACBdIA/edit#gid=0
ws = session.spreadsheet_by_key("13cxyJLCs_Ynd7MCbmmawaA7lgIIXufnMXmIfOACBdIA").worksheets[0]

# Gets content of A1 cell.
puts "Last updated: #{ws.updated}"
puts "Contents of cell A1: #{ws[1, 1]}"

ws[2, 1] = "foo"
ws[2, 2] = "bar"
#ws.save
ws.synchronize

# Dumps all cells.
(1..ws.num_rows).each do |row|
  (1..ws.num_cols).each do |col|
    p ws[row, col]
  end
end


puts 'All done with the spreadsheet'
