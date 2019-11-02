class Applications < ActiveRecord::Migration[6.0]
  def self.up
    create_table :applications do |t|
      t.string :app_name
      t.text :body
      t.timestamps
    end
  end
end
