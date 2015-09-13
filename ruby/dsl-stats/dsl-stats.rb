# This program reads data from a CenturyLink/ZyXEL C1000Z
# DSL modem, and will eventually post it to Google Docs.
#
# Author::    R. Cody Erben  (mailto:erben22@gmail.com)
# Copyright:: Copyright (c) 2015 Codebets
# License::   TBD

require 'watir-webdriver'
require 'page-object'

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
  modem_status_page.get_modem_status
  modem_status_page.get_dsl_status


rescue => exception
  puts "Error during processing: #{$!}"
  puts "Backtrace:\n\t#{exception.backtrace.join("\n\t")}"
end

@browser.close
