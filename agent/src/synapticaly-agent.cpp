//============================================================================
// Name        : synapticaly-agent.cpp
// Author      : Michal Sobczak
// Version     : r0
// Copyright   : 
// Description : Synapticaly agent
//============================================================================

#include <iostream>
#include <cstdlib>
#include <memory>
#include "HTTPRequest.hpp"
using namespace std;

const char* OBN      = "OPENSHIFT_BUILD_NAMESPACE";
const char* HEADER   = "Content-Type: application/x-www-form-urlencoded";
const char* URL      = "http://127.0.0.1:4567";
const char* APP_NONE = "n/a";

std::string read_env() {
	if(const char* env_p = std::getenv(OBN)) {
	  cout << OBN << " is: " << env_p << std::endl;
	  return env_p;
	}
	else {
	  cout << "There is no " << OBN << std::endl;
	  return APP_NONE;
	}
} // read_env

void send_data_to_api(std::string app_name) {
	try {
		http::Request request(URL);
		std::string parameters = "app_name=" + app_name;
		const http::Response postResponse = request.send("GET", parameters, { HEADER });
	    std::cout << std::string(postResponse.body.begin(), postResponse.body.end()) << std::endl;
	}
	catch (const std::exception& e) {
	    std::cerr << "Request failed, error: " << e.what() << std::endl;
	}
} // send_data_to_api

int main() {
	std::string app_name = read_env();
    if (!app_name.empty()) {
    	send_data_to_api(app_name);
    }
	return 0;
}
