/*
 * Commandline.cpp
 *
 *  Created on: 19.08.2018
 *      Author: daniel
 */

#include "Commandline.h"

namespace programm {
std::string cmd::showValue(bool value)
{
	if (value) return "true";
	if (!value) return "false";
}

std::string cmd::endl()
{
	return "\n";
}

} /* namespace programm */

namespace debug {

std::string debug::verboseShowValue(bool value)
{
	if (value) return "true";
	if (!value) return "false";
	return "";
}
std::string debug::endl()
{
	return "\n";
}


}
