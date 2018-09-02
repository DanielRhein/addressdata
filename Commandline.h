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

class cmd : public std::streambuf {
public:
	static std::string showValue(bool value);
	static std::string endl();
	friend std::ostream &operator<<(std::ostream &output,const int &val)
	{
		output << val;
		return output;
	}

	std::ostream& operator<<(std::ostream& os)
	{
		    // write obj to stream
		    return os;
	}
	std::ostream& operator<<(std::string val)
	{
			    // write obj to stream
			    return std::cout << val;
	}
	friend std::ostream &operator<<(std::ostream &output,const std::string &val)
	{
			output << val;
			return output;
	}
	friend std::ostream &operator<<(std::ostream &output,const bool &val)
	{
		output << showValue(val);
		return output;
	}
};

}/* namespace programm */


namespace debug {

class debug : public std::streambuf
{
public:
	static bool active;
	static std::string endl();
	static std::string verboseShowValue(bool value);
	static void showVerbose(bool value);
	static bool verbose();
	friend std::ostream &operator<<(std::ostream &output,const int &val)
	{
		if (active)
		{
		output << val;
		}
		return output;
	}
	friend std::ostream &operator<<(std::ostream &output,const std::string &val)
	{
		if (active)
				{
			output << val;
				}
			return output;
	}
	friend std::ostream &operator<<(std::ostream &output,const bool &val)
	{
		if (active)
				{
				output << verboseShowValue(val);
				}
				return output;
	}
};

} /* namespace debug */

#endif /* COMMANDLINE_H_ */
