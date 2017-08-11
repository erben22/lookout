class UtilitiesClass
  include PageObject

  link(:reboot, :class => 'reboot_btn')
  #link(:confirm, :id => 'confirm_btn')
  link(:confirm, :text => 'Ok')

  #def reboot_modem
  #  puts "Rebooting modem..."
  #  confirm(true){ reboot }
  #end

  def reboot_modem
    puts "Rebooting modem..."
    reboot
    sleep(1)
    puts "Done sleeping"
  end

  def confirm_reboot
    #puts confirm.exists?
    #confirm
    #puts confirm.exists?
    
    #element(:text => 'Ok').click

    #link_element(text: 'Ok')
    #puts link_element.exists?
    #link_element.click
    #puts "Clicked it..."

    @browser.execute_script <<-JS
      goSubmit();
    JS

    #@browser.a(:id => "confirm_btn").fire_event :click

  end
end
