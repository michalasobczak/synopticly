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
	const char* REV      = "20191110";
	// k8s/okd docker pod data
	const char* OBN      = "OPENSHIFT_BUILD_NAMESPACE";
	const char* HSN      = "HOSTNAME";
	const char* RUV      = "RUBY_VERSION";
	const char* WFV      = "WILDFLY_VERSION";
	// pod data mapping for API server
	std::string APP_NONE          = "n/a"; // OBN
	std::string APP_NAME          = "n/a";
	std::string HOSTNAME          = "n/a"; // HSN
	std::string RUBY_VERSION      = "n/a"; // RUV
	std::string WILDFLY_VERSION   = "n/a"; // WFV
	std::string OS_VERSION        = "n/a"; // encoded
	std::string OS_RELEASE        = "n/a"; // encoded
	std::string NE_OS_VERSION     = "n/a"; // non-encoded
	std::string NE_OS_RELEASE     = "n/a"; // non-encoded
	std::string UPTIME            = "n/a"; // system command: uptime
	std::string PROCESSES         = "n/a"; // system command: top -c -n1 | awk '{ if (NR >= 8) { print $0 }  }'
	//
	std::string URL      = "http://127.0.0.1:9292";
	int         PORT     = 9292;
	const char* CONFIG   = "./synopticly_config.json";
#endif /* SRC_CONFIG_H_ */
