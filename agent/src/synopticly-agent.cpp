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
	read_os_version();
	read_config_file();
	APP_NAME        = read_app_name();
	HOSTNAME        = url_encode(read_hostname());
	RUBY_VERSION    = url_encode(read_ruby_version());
	WILDFLY_VERSION = url_encode(read_wildfly_version());
	OS_VERSION      = url_encode(NE_OS_VERSION);
	OS_RELEASE      = url_encode(NE_OS_RELEASE);
	while (true) {
		if (!APP_NAME.empty()) {
			UPTIME    = url_encode(exec("uptime"));
			PROCESSES = url_encode(exec("top -b -c -n1 | awk '{ if (NR == 2) { print $0 }  }' | base64"));
			send_data_to_api();
		}
		sleep_for(5000);
	}
	return 0;
} // main
