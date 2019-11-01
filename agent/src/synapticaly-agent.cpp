//============================================================================
// Name        : synapticaly-agent.cpp
// Author      : Michal Sobczak
// Version     : r0
// Copyright   : 
// Description : Synapticaly agent, sending data to API
//============================================================================

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <memory>
#include "HTTPRequest.hpp"
#include "json.hpp"
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;
using json = nlohmann::json;

const char* OBN      = "OPENSHIFT_BUILD_NAMESPACE";
const char* HEADER   = "Content-Type: application/x-www-form-urlencoded";
std::string URL      = "http://127.0.0.1:4567";
const char* APP_NONE = "n/a";
const char* CONFIG   = "./synapticaly_config.json";

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

void read_config_file() {
	std::ifstream file(CONFIG);
	json config;
	file >> config;
    cout << "API URL: " << config["api_url"] << std::endl;
    URL = config["api_url"].get<std::string>();
} // read_config_file

void send_data_to_api(std::string app_name) {
	try {
		std::time_t result = std::time(nullptr);
		cout << std::asctime(std::localtime(&result));
		http::Request request(URL);
		std::string parameters = "app_name=" + app_name;
		const http::Response postResponse = request.send("GET", parameters, { HEADER });
        //std::cout << std::string(postResponse.body.begin(), postResponse.body.end()) << std::endl;
	}
	catch (const std::exception& e) {
	    std::cerr << "Request failed, error: " << e.what() << std::endl;
	}
} // send_data_to_api

int main() {
	read_config_file();
	std::string app_name = read_env();
	while(1) {
		if (!app_name.empty()) {
			send_data_to_api(app_name);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	return 0;
} // main
