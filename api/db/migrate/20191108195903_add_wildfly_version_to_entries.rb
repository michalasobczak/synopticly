class AddWildflyVersionToEntries < ActiveRecord::Migration[6.0]
  def change
    add_column :entries, :wildfly_version, :string
    add_column :entries, :java_version,    :string
  end
end
