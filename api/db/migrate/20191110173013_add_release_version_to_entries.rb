class AddReleaseVersionToEntries < ActiveRecord::Migration[6.0]
  def change
    add_column :entries, :os_release, :string
    add_column :entries, :os_version, :string
  end
end
