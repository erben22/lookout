class IndexPage
  include PageObject

  link(:modem_status, :text => 'Modem Status')
  link(:quick_setup, :text => 'Quick Setup')
  link(:wireless_setup, :text => 'Wireless Setup')
  link(:utilities, :text => 'Utilities')
  link(:advanced_setup, :text => 'Advanced Setup')

  def view_modem_status
    modem_status
  end

  def view_quick_setup
    quick_setup
  end

  def view_wireless_setup
    wireless_setup
  end

  def view_utilities
    utilities
  end

  def view_advanced_setup
    advanced_setup
  end
end
