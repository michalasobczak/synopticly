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
	const char* OBN      = "OPENSHIFT_BUILD_NAMESPACE";
	const char* HEADER   = "Content-Type: application/x-www-form-urlencoded";
	std::string URL      = "http://127.0.0.1:4567";
	const char* APP_NONE = "n/a";
	const char* CONFIG   = "./synopticly_config.json";
#endif /* SRC_CONFIG_H_ */
