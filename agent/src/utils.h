/*
 * utils.cpp
 *
 *  Created on: Nov 2, 2019
 *      Author: Michał Sobczak
 */

// ***** standard libraries *****
#include <cstdlib>
#include <iostream>
#include <fstream>
// ***** 3rd party libraries *****
#include "json.hpp"
// ***** other *****
#include "config.h"

#ifndef SRC_UTILS_CPP_
#define SRC_UTILS_CPP_
	void print_init_msg() {
		std::cout << "*** " << INIT_MSG << REV << " ***" << std::endl;
	}
	std::string read_app_name() {
		if(const char* env_p = std::getenv(OBN)) { return env_p; }
		else { return APP_NONE; }
	} // read_app_name
	std::string read_hostname() {
		if(const char* tmp = std::getenv(HSN)) { return tmp; }
		else { return APP_NONE; }
	} // read_hostname
	std::string read_ruby_version() {
		if(const char* tmp = std::getenv(RUV)) { return tmp; }
		else { return APP_NONE; }
	} // read_ruby_version
	void read_config_file() {
		try {
			std::ifstream file(CONFIG);
			nlohmann::json config;
			file >> config;
			std::cout << "API URL: " << config["api_url"] << std::endl << std::endl;
			URL = config["api_url"].get<std::string>();
		} catch (std::exception& e) {
			std::cerr << "read_config_file: failed, error: " << e.what() << std::endl;
		}
	} // read_config_file
#endif /* SRC_UTILS_CPP_ */
