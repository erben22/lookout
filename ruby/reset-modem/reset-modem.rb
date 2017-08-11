# This program resets a CenturyLink/ZyXEL C1000Z
# DSL modem when it detects a period of internet
# deconnectivity.
#
# Author::    R. Cody Erben  (mailto:erben22@gmail.com)
# Copyright:: Copyright (c) 2017 Codebets
# License::   TBD

require 'watir-webdriver'
require 'page-object'
require 'rubygems'
require 'time'
require 'fileutils'

require_relative 'login_page'
require_relative 'index_page'
require_relative 'utilities_class'

begin
  @main_url = 'http://192.168.2.1'

  #@browser = Watir::Browser.new :firefox
  @browser = Watir::Browser.new :phantomjs

  @browser.goto(@main_url)

  login_page = LoginPage.new(@browser)
  login_page.login_to_system

  index_page = IndexPage.new(@browser)
  index_page.view_utilities

  utilities_page = UtilitiesClass.new(@browser)
  utilities_status = utilities_page.reboot_modem

  utilities_status = utilities_page.confirm_reboot

rescue => exception
  puts "Error during processing: #{$!}"
  puts "Backtrace:\n\t#{exception.backtrace.join("\n\t")}"
end

@browser.close
