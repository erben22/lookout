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

def log_message(msg)
  current_time = Time.now.strftime("%Y-%m-%d %H:%M:%S")
  puts "#{current_time}: #{msg}"
end

# Main program.

begin
  @main_url = 'http://192.168.2.1'

  log_message "Launching browser..."

  #@browser = Watir::Browser.new :chrome
  @browser = Watir::Browser.new :phantomjs

  log_message "Browser launched, going to C1000z EWS..."

  @browser.goto(@main_url)

  log_message "Time to login..."
  login_page = LoginPage.new(@browser)
  login_page.login_to_system

  log_message "Navigating to the wireless setup page..."
  index_page = IndexPage.new(@browser)
  index_page.view_wireless_setup

  log_message "On the wireless setup page...now we disable wireless...divs and such"
  wireless_setup_page = WirelessSetupPage.new(@browser)
  wireless_setup_page.disable_wireless

  log_message "Now things are disabled, see if we can apply the settings..."

  #log_message "link[0]: #{wireless_setup_page.apply_wireless_settings_elements[0].text}"
  #log_message "link[1]: #{wireless_setup_page.apply_wireless_settings_elements[1].text}"

  wireless_setup_page.apply_wireless_settings_elements[1].click

  wireless_setup_page.wait_until(10, 'Could not get the wireless settings page back.') do
    wireless_setup_page.text.include? 'Basic Settings'
  end

  log_message "Wireless is disabled...re-enable it now!"
  
  wireless_setup_page.enable_wireless
  wireless_setup_page.wait_until(10, 'Failed to get the page back after enabling.') do
    wireless_setup_page.text.include? 'Change the network name'
  end

  #log_message "link[0]: #{wireless_setup_page.apply_wireless_settings_elements[0].text}"
  #log_message "link[1]: #{wireless_setup_page.apply_wireless_settings_elements[1].text}"

  wireless_setup_page.apply_wireless_settings_elements[0].click

  wireless_setup_page.wait_until(10, 'Could not get the wireless settings page back.') do
    wireless_setup_page.text.include? 'Basic Settings'
  end

  log_message "Wireless is enabled, we out!"

rescue => exception
  log_message "Error during processing: #{$!}"
  log_message "Backtrace:\n\t#{exception.backtrace.join("\n\t")}"
end

@browser.close
