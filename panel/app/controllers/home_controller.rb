class HomeController < ApplicationController

  def main
    # ********* entries counter ********* 
    sql = "SELECT e.app_name, 
             (SELECT COUNT(distinct hostname) FROM entries 
           WHERE hostname IS NOT NULL
             AND app_name = e.app_name
             AND created_at >= now()-interval '15 seconds') 
           FROM entries e
           GROUP BY e.app_name"
    res = Entry.connection.execute(sql)
    @sub_entries = {}
    res.each do |e|   
      @sub_entries[e['app_name']] = e['count']
    end
    # ********* all entries for all application  ********* 
    res = Entry.where("hostname IS NOT NULL AND created_at >= now()-interval '15 seconds'")
    @entries = {}
    res.each do |e|
      if @entries[e['app_name']].blank? then
        @entries[e['app_name']] = [e]
      else
        @entries[e['app_name']] << e
      end
    end
    # ********* extended info ********* 
    @app_info = {}
    Application.where("app_name <> 'n/a' AND app_name is not null").each do |app|
      entry = @entries[app.app_name][-1]
      host      = ""
      platforms = ""
      processes = ""
      p1_p2     = ""
      begin
        platforms = "# #{@sub_entries[app.app_name]} \n "
        if params["basic"] == "true"
          # nop
        else 
          #  ********* processes ********* 
          processes = entry.processes.split("Tasks:")[1][1..-1] rescue ""
          p_splitted = processes.split(",")
          p1_p2 = p_splitted[0] + "\n" + p_splitted[1] + "\n" + p_splitted[2] + "\n" + p_splitted[4] + "\n"         
          # *********  Ruby interpreter version ********* 
          if !entry.ruby_version.blank? && entry.ruby_version != 'n/a' then
            platforms = platforms + "ru: #{entry.ruby_version rescue '?'}"
          end
          # *********  Wildfly version ********* 
          if !entry.wildfly_version.blank? && entry.wildfly_version != 'n/a' then
            platforms = platforms + "\nwf: #{entry.wildfly_version rescue '?'}" 
          end
          # *********  OS vesion info ********* 
          if !entry.os_version.blank? && entry.os_version != 'n/a' then
            platforms = platforms + "\nos: #{entry.os_version rescue '?'}" 
          end
          # *********  uptime command output info ********* 
          if entry.app_name == entry.hostname then 
            uptime_load = "hl: " +  entry.uptime.split("load average")[1][2..-1].gsub(", ", " ").gsub(",", ".") rescue nil
            uptime_info = "hi: " +  entry.uptime.split("load average")[0][0..-4].split("up")[1][1..-1] rescue nil
            host = uptime_load + "\n" + uptime_info + "\n"
          else
            host  = ""
            p1_p2 = ""
          end
        end
        @app_info[app.app_name] = { :host=>host, :platforms=>platforms, :processes=>processes, :p1_p2=>p1_p2  }
      rescue 
      end 
    end # apps
  end # main

end
