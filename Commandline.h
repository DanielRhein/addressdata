/*
 * Commandline.h
 *
 *  Created on: 19.08.2018
 *      Author: daniel
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
namespace programm {

class Commandline {
public:
	Commandline();
	Commandline(bool verbose);
	Commandline(bool verbose,bool newline);
	int getIntInput(std::string question,bool retry=false);
	std::string getStrInput(std::string question,bool retry=false);
	void writeOutput(std::string output);
	void verboseOutput(std::string output);
	void setVerbose(bool value);
	void setUseEndline(bool newline);
	void verboseShowValue(bool value);
	void verboseShowValue(int value);
	void verboseShowValue(std::string value);
	void verboseShowValue(std::string value,bool boolValue);
	void verboseShowValue(std::string value,int intValue);
	void verboseShowValue(std::string value,std::string strValue);
	virtual ~Commandline();
private:
	bool verbose;
	bool newline;
	std::string verboseGetValue(bool value);
};

} /* namespace programm */

#endif /* COMMANDLINE_H_ */
