class AddUptimeToEntries < ActiveRecord::Migration[6.0]
  def change
    add_column :entries, :uptime, :string
  end
end
