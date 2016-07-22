class LoginPage
  include PageObject

  text_field(:username, :name => 'admin_username')
  text_field(:password, :id => 'admin_password')
  link(:login, :id => 'apply_btn')

  # Foo...
  # Params:
  # +username+::
  # +password+::

  def login_to_system(username='admin', password='abc')
    self.username = username
    self.password = password

    # Hack to work-around issue with the login_page page object
    # where the password control is not available unless we 
    # resize the browser.

    @browser.window.resize_to(1280, 1024)

    login
  end

end
