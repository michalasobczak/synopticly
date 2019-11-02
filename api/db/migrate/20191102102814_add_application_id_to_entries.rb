class AddApplicationIdToEntries < ActiveRecord::Migration[6.0]
  def change
    add_column :entries, :application_id, :bigint
  end
end
