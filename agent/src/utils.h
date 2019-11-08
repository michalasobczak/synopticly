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
#include <boost/algorithm/string.hpp>
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
	std::string read_wildfly_version() {
		if(const char* tmp = std::getenv(WFV)) { return tmp; }
		else { return APP_NONE; }
	} // read_wildfly_version
	void read_config_file() {
		try {
			std::ifstream file(CONFIG);
			nlohmann::json config;
			file >> config;
			std::cout << "API URL: " << config["api_url"] << std::endl;
			std::string full_url = config["api_url"].get<std::string>();
			std::vector<std::string> strs;
			boost::split(strs, full_url, boost::is_any_of(":"));
			URL  = strs[0];
			PORT = std::stoi(strs[1]);
			std::cout << "HOST: " << URL << ", PORT:" << PORT << std::endl << std::endl;
		} catch (std::exception& e) {
			std::cerr << "read_config_file: failed, error: " << e.what() << std::endl;
		}
	} // read_config_file
#endif /* SRC_UTILS_CPP_ */
