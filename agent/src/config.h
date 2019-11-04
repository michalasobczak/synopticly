/*
 * config.h
 *
 *  Created on: Nov 2, 2019
 *      Author: sobczam
 */

// ***** standard libraries *****
#include <iostream>

#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_
	const char* INIT_MSG = "synopticly-agent, rev: ";
	const char* REV      = "20191102_01";
	// k8s/okd docker pod data
	const char* OBN      = "OPENSHIFT_BUILD_NAMESPACE";
	const char* HSN      = "HOSTNAME";
	const char* RUV      = "RUBY_VERSION";
	// pod data mapping for API server
	const char* APP_NONE = "n/a"; // OBN
	const char* HOSTNAME = "n/a"; // HSN
	const char* RUBY_VER = "n/a"; // RUV
	//
	const char* HEADER   = "Content-Type: application/x-www-form-urlencoded";
	std::string URL      = "http://127.0.0.1:9292";
	int         PORT     = 9292;
	const char* CONFIG   = "./synopticly_config.json";
#endif /* SRC_CONFIG_H_ */
