/*
 * Commandline.cpp
 *
 *  Created on: 19.08.2018
 *      Author: daniel
 */

#include "Commandline.h"

namespace programm {

Commandline::Commandline() {
	verbose = false;
	newline = true;
}

Commandline::Commandline(bool verbose) {
	this->verbose = verbose;
	this->newline = true;
}

Commandline::Commandline(bool verbose, bool newline) {
	this->verbose = verbose;
	this->newline = newline;
}

int Commandline::getIntInput(std::string question, bool retry) {
	int returnvalue=0;
	if (retry) {
		do {
			writeOutput(question);
			std::cin >> returnvalue;
		} while (returnvalue<=0);
	} else {
		writeOutput(question);
		std::cin >> returnvalue;
	}
	return returnvalue;
}

std::string Commandline::getStrInput(std::string question, bool retry) {
	std::string returnvalue;
	if (retry) {
		do {
			writeOutput(question);
			std::cin >> returnvalue;
		} while (returnvalue.empty());
	} else {
		writeOutput(question);
		std::cin >> returnvalue;
	}
	return returnvalue;
}

void Commandline::writeOutput(std::string output) {
	if (newline) {
		std::cout << output << std::endl;
	} else {
		std::cout << output;
	}
}

void Commandline::verboseOutput(std::string output) {
	if (verbose) {
		std::cout << output << std::endl;
	}
}

void Commandline::setVerbose(bool verbose) {
	this->verbose = verbose;
}

void Commandline::setUseEndline(bool newline) {
	this->newline = newline;

}

void Commandline::verboseShowValue(bool value) {
	if (value) {
		verboseOutput("true");
	} else {
		verboseOutput("false");
	}
}
void Commandline::verboseShowValue(int value) {
	std::cout << value << std::endl;
}

void Commandline::verboseShowValue(std::string value) {
	std::cout << value << std::endl;
}

void Commandline::verboseShowValue(std::string value, bool boolValue) {
	std::cout << value << " " << verboseGetValue(boolValue) << std::endl;
}

void Commandline::verboseShowValue(std::string value, int intValue) {
	std::cout << value << " " << intValue << std::endl;
}
void Commandline::verboseShowValue(std::string value, std::string strValue) {
	std::cout << value << " " << strValue << std::endl;
}

std::string Commandline::verboseGetValue(bool value)
{
	if (value) return "true";
	if (!value) return "false";
}
Commandline::~Commandline() {
}

} /* namespace programm */
