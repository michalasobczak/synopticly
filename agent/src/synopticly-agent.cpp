//============================================================================
// Name        : synapticaly-agent.cpp
// Author      : Michal Sobczak
// Version     : r0
// Copyright   : 
// Description : Synapticaly agent, sending data to API
//============================================================================

// ***** standard libraries *****
#include <iostream>
#include <cstdlib>
// ***** other *****
#include "config.h"
#include "utils.h"
#include "api.h"

// ***** using *****
using namespace std;

// ***** configuration *****
// - config.h,

// ***** functions *****
// - utils.h,
// - api.h

// ***** main *****
int main() {
	freopen("synopticly.info.log", "w", stdout);
	freopen("synopticly.err.log", "w", stderr);
	print_init_msg();
	read_config_file();
	std::string app_name        = read_app_name();
	std::string hostname        = read_hostname();
	std::string ruby_version    = read_ruby_version();
	std::string wildfly_version = read_wildfly_version();
	while (true) {
		if (!app_name.empty()) {
			send_data_to_api(app_name, hostname, ruby_version, wildfly_version);
		}
		sleep_for(5000);
	}
	return 0;
} // main
