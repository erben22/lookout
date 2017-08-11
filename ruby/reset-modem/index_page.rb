class IndexPage
  include PageObject

  link(:modem_status, :text => 'Modem Status')
  link(:utilities, :text => 'Utilities')

  def view_modem_status
    modem_status
  end

  def view_utilities
    utilities
  end
end
