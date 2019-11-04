class CretateFlows < ActiveRecord::Migration[6.0]
  def self.up
    create_table :flows do |t|
      t.string :input
      t.string :output
      t.text   :comments
      t.timestamps
    end
  end
end
