# myapp.rb
require 'sinatra'

get '/' do
  puts params.inspect
end
