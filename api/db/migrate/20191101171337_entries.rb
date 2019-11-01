class Entries < ActiveRecord::Migration[6.0]
  def self.up
    create_table :entries do |t|
      t.string :app_name
      t.text :body
      t.timestamps
    end
  end
end
