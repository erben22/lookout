class IndexPage
  include PageObject

  link(:modem_status, :text => 'Modem Status')

  def view_modem_status
    modem_status
  end
end