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
  e.save!
  logger.info("  Entries.size: #{Entry.count.to_s}")
  return "{}"
end

