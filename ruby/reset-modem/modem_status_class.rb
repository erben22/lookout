class ModemStatusClass
  include PageObject

  link(:dsl_status, :text => 'DSL Status')
  link(:internet_status, :text => 'Internet Status')

  def view_dsl_status
    dsl_status
  end

  def view_internet_status
    internet_status
  end

  def get_modem_status
    @modem_status = {}
    @browser.table(:index => 1).hashes.each do |key, value|
      @modem_status[key['Modem Parameter']] = key['Status']
    end

    #puts "Modem status: #{@modem_status}"
    @modem_status
  end

  def get_dsl_status
    # Now get some DSL status details
    view_dsl_status

    @dsl_status = {}
    @browser.table(:index => 0).hashes.each do |key, value|
      @dsl_status[key['Connection']] = key['Status']
    end

    @browser.table(:index => 1).hashes.each do |key, value|
      @dsl_status[key['Link Statistic']] = key['Status']
    end

    @browser.table(:index => 2).hashes.each do |key, value|
      @dsl_status["#{key['Levels']}-Downstream"] = key['Downstream']
      @dsl_status["#{key['Levels']}-Upstream"] = key['Upstream']
    end

    @browser.table(:index => 3).hashes.each do |key, value|
      @dsl_status["#{key['Transport']}-Downstream"] = key['Downstream']
      @dsl_status["#{key['Transport']}-Upstream"] = key['Upstream']
    end

    @browser.table(:index => 4).hashes.each do |key, value|
      @dsl_status["#{key['Levels']}-NearEnd"] = key['Near End']
      @dsl_status["#{key['Levels']}-FarEnd"] = key['Far End']
    end

    #puts "DSL status: #{@dsl_status}"
    @dsl_status
  end

  def get_internet_status
    # Now get some internet status details
    view_internet_status

    @internet_status = {}

    @browser.table(:index => 1).hashes.each do |key, value|
      @internet_status[key['Internet Setting']] = key['Status']
    end

    @browser.table(:index => 2).hashes.each do |key, value|
      @internet_status[key['PPP Parameter']] = key['Status']
    end

    @browser.table(:index => 3).hashes.each do |key, value|
      @internet_status[key['PPP Parameter']] = key['Status']
    end

    #puts "Internet status: #{@internet_status}"
    @internet_status
  end

end
