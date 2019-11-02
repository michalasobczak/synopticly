require 'sinatra'
require 'active_record'
require 'rake'
require 'sinatra/activerecord'
require 'sinatra/activerecord/rake'
require './models'

set :bind, "0.0.0.0"

get '/' do
  logger.info("  Params: #{params.inspect}")
  e = Entry.new
  e.app_name = params["app_name"] rescue "n/a"
  e.hostname = params["h"] rescue "n/a"
  e.ruby_version = params["rv"] rescue "n/a";
  app = Application.where("app_name = ?", e.app_name).first
  if app.blank? then
    app = Application.new
    app.app_name = e.app_name
    app.save!
    e.application_id = app.id
  end
  e.application_id = app.id
  e.save! 
  #logger.info("  Entries.size: #{Entry.count.to_s}")
  return "{}"
end

