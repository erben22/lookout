# This program reads data from a CenturyLink/ZyXEL C1000Z
# DSL modem, and toggles the wireless status from on to off
# and back again to fix issues where the bridging between
# the wlan and lan goes out to lunch.
#
# Author::    R. Cody Erben  (mailto:erben22@gmail.com)
# Copyright:: Copyright (c) 2016 Codebets
# License::   TBD

require 'watir-webdriver'
require 'page-object'
require 'rubygems'
require 'time'

require_relative 'login_page'
require_relative 'index_page'
require_relative 'wireless_setup_page'

begin
  @main_url = 'http://192.168.2.1'

  puts "Launching browser..."

  @browser = Watir::Browser.new :chrome
  #@browser = Watir::Browser.new :phantomjs

  puts "Browser launched, going to C1000z EWS..."

  @browser.goto(@main_url)

  puts "Time to login..."
  login_page = LoginPage.new(@browser)
  login_page.login_to_system

  puts "Navigating to the wireless setup page..."
  index_page = IndexPage.new(@browser)
  index_page.view_wireless_setup

  puts "On the wireless setup page...now we disable wireless...divs and such"
  wireless_setup_page = WirelessSetupPage.new(@browser)
  wireless_setup_page.disable_wireless

  puts "Now things are disabled, see if we can apply the settings..."

  #puts "link[0]: #{wireless_setup_page.apply_wireless_settings_elements[0].text}"
  #puts "link[1]: #{wireless_setup_page.apply_wireless_settings_elements[1].text}"

  wireless_setup_page.apply_wireless_settings_elements[1].click

  wireless_setup_page.wait_until(20, 'Could not get the wireless settings page back.') do
    wireless_setup_page.text.include? 'Basic Settings'
  end
  puts "Wireless is disabled...guess we re-enable it now!"
  
  wireless_setup_page.enable_wireless

  #puts "link[0]: #{wireless_setup_page.apply_wireless_settings_elements[0].text}"
  #puts "link[1]: #{wireless_setup_page.apply_wireless_settings_elements[1].text}"

  wireless_setup_page.apply_wireless_settings_elements[0].click

  wireless_setup_page.wait_until(20, 'Could not get the wireless settings page back.') do
    wireless_setup_page.text.include? 'Basic Settings'
  end
  puts "Wireless is enabled, we out!"

rescue => exception
  puts "Error during processing: #{$!}"
  puts "Backtrace:\n\t#{exception.backtrace.join("\n\t")}"
end

#@browser.close
