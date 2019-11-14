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
// #include "HTTPRequest.hpp"
// #include "httplib.h"
#include <lua5.1/lua.hpp>
#include "json.hpp"
// ***** other *****
#include "config.h"

// ***** using *****
using json = nlohmann::json;
using namespace std;

#ifndef SRC_API_H_
#define SRC_API_H_
	void print_error(lua_State* state) {
	  const char* message = lua_tostring(state, -1);
	  puts(message);
	  lua_pop(state, 1);
	}
	void execute(std::string lua_code) {
	  lua_State *state = luaL_newstate();
	  luaL_openlibs(state);
      luaL_loadstring(state, lua_code.c_str());
      lua_pcall(state, 0, LUA_MULTRET, 0);
      lua_close(state);
	}

	void send_data_to_api() {
		try {
			std::cout << "send_data_to_api" << std::endl;
			//std::time_t result = std::time(nullptr);
			//std::cout << std::asctime(std::localtime(&result));
			std::string host(URL);
			std::string port = std::to_string(PORT);
			if (APP_NAME == APP_NONE) {
				APP_NAME = HOSTNAME;
			}
			std::string parameters = "http://"+host+":"+port
					+"/?app_name="+APP_NAME
					+"&h="+HOSTNAME
					+"&rv="+RUBY_VERSION
					+"&wv="+WILDFLY_VERSION
					+"&ov="+OS_VERSION
					+"&or="+OS_RELEASE
					+"&up="+UPTIME;
			std::string tmp = std::string("local http=require('socket.http');local body,code,headers,status=http.request('")+parameters+std::string("');print(code,status,#body);");
			std::cout << tmp << std::endl;
			execute(tmp);
		}
		catch (const std::exception& e) {
			std::cerr << "send_data_to_api: failed, error: " << e.what() << std::endl;
		}
	} // send_data_to_api
	void sleep_for(int millis) {
		std::cout << " sleep_for: " << millis << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(millis));
	} // sleep_for
#endif /* SRC_API_H_ */
