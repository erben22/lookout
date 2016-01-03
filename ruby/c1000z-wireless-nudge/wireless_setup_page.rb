class WirelessSetupPage
  include PageObject

  button(:enable_wireless, :id => 'enabled')
  button(:disable_wireless, :id => 'disabled')

  links(:apply_wireless_settings, :text => 'Apply')

  #div(:enabled_wireless_div, :id => 'enabled')
  #div(:disabled_wireless_div, :id => 'disabled')

  #def disable_the_wireless
  #  link(:apply_wireless_settings, :id => 'apply_btn')
  #  disabled_wireless_div.apply_wireless_settings.text
  #end

end
