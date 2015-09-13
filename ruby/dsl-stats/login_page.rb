class LoginPage
  include PageObject

  text_field(:username, :name => 'admin_username')
  text_field(:password, :name => 'admin_password')
  link(:login, :id => 'apply_btn')

  # Foo...
  # Params:
  # +username+::
  # +password+::

  def login_to_system(username='admin', password='blah')
    self.username = username
    self.password = password
    login
  end

end