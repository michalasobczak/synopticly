require 'sinatra'
require 'active_record'
require 'rake'
require 'sinatra/activerecord'
require 'sinatra/activerecord/rake'
require 'base64'
require './models'

set :bind, "0.0.0.0"

get '/' do
  logger.info("-- params: #{params.inspect}")
  e = Entry.new
  e.app_name        = params["app_name"] rescue "n/a"
  e.hostname        = params["h"]        rescue "n/a"
  e.ruby_version    = params["rv"]       rescue "n/a"
  e.wildfly_version = params["wv"]       rescue "n/a"
  e.java_version    = params["jv"]       rescue "n/a"
  e.os_release      = params["or"]       rescue "n/a"
  e.os_version      = params["ov"]       rescue "n/a"
  e.uptime          = params["up"]       rescue "n/a"
  e.processes       = Base64.decode64(params["pr"]) rescue "n/a"
  app = Application.where("app_name = ?", e.app_name).first
  if app.blank? then
    app = Application.new
    app.app_name = e.app_name
    app.save!
    e.application_id = app.id
  end
  e.application_id = app.id
  e.save! 
  Entry.where("created_at <= now() - interval '1 minutes'").delete_all
  if app.body.blank?
    return "{}"
  else
    return app.body
  end
end # /

