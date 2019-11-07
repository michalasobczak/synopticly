class AddHostnameToEntries < ActiveRecord::Migration[6.0]
  def change
    add_column :entries, :hostname,     :string
    add_column :entries, :ruby_version, :string
  end
end
