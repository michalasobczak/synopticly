/*
 * api.h
 *
 *  Created on: Nov 2, 2019
 *      Author: Michał Sobczak
 */

// ***** standard libraries *****
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>
#include <thread>
#include <ctime>
// ***** 3rd party libraries *****
#include "HTTPRequest.hpp"
#include "json.hpp"
// ***** other *****
#include "config.h"

// ***** using *****
using json = nlohmann::json;

#ifndef SRC_API_H_
#define SRC_API_H_
	void send_data_to_api(std::string app_name, std::string hostname, std::string ruby_version) {
		try {
			//std::time_t result = std::time(nullptr);
			//std::cout << std::asctime(std::localtime(&result));
			http::Request request(URL);
			std::string parameters = "app_name="+app_name+"&h="+hostname+"&rv="+ruby_version;
			const http::Response postResponse = request.send("GET", parameters, { HEADER });
			//std::cout << std::string(postResponse.body.begin(), postResponse.body.end()) << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "send_data_to_api: failed, error: " << e.what() << std::endl;
		}
	} // send_data_to_api
	void sleep_for(int millis) {
		std::this_thread::sleep_for(std::chrono::milliseconds(millis));
	} // sleep_for
#endif /* SRC_API_H_ */
