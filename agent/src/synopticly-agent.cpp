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
	print_init_msg();
	read_config_file();
	std::string app_name = read_env();
	while(1) {
		if (!app_name.empty()) {
			send_data_to_api(app_name);
		}
		sleep_for(1000);
	}
	return 0;
} // main
