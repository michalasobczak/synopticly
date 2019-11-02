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
	std::string read_env() {
		if(const char* env_p = std::getenv(OBN)) {
		  std::cout << OBN << " is: " << env_p << std::endl;
		  return env_p;
		}
		else {
		  std::cout << "There is no " << OBN << std::endl;
		  return APP_NONE;
		}
	} // read_env
	void read_config_file() {
		try {
			std::ifstream file(CONFIG);
			nlohmann::json config;
			file >> config;
			std::cout << "API URL: " << config["api_url"] << std::endl;
			URL = config["api_url"].get<std::string>();
		} catch (std::exception& e) {
			std::cerr << "read_config_file: failed, error: " << e.what() << std::endl;
		}
	} // read_config_file
#endif /* SRC_UTILS_CPP_ */
