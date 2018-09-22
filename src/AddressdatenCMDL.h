/*
 * AddressdatenCMDL.h
 *
 *  Created on: 31.08.2018
 *      Author: daniel
 */

#ifndef ADDRESSDATENCMDL_H_
#define ADDRESSDATENCMDL_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Address.h"
#include "AddressdatenParameter.h"
#include "Commandline.h"
#include "Banner.h"
#include "RunInfo.h"
#include <vector>
#include <fstream>
#include <limits>
namespace programm {

class AddressdatenCMDL {
private:
	cmd mycmd;
	debug::debug dbg;
	error::error err;
	bool verbose;
	AddressdatenParameter addressdatenParameter;
	std::fstream gotoLine(string filename,int num);
	static const string CMDL_DELIMITER;
public:
	AddressdatenCMDL();
	void showFileContent(string filename);
	bool question(string question, string positive, string negative,
			string default_value);
	void removeData(string filename, u_int32_t &ULL_id);

	void removeDataInteractively(string filename);
	u_int32_t countFileContent(string filename);
	void writeAddress(string filename, Address addresse);
	void split(const string& s, char delim, vector<string>& v);
	string getAddress(char argv[]);
	string getInput(string bez);
	Address getAddressInteractivelyFromInput();
	void searchAddressInFileContent(Address searchAddress, string filename);
	void searchAddressInteractively(string filename);
	void addAddress(string argv, string filename);
	void editAddress(string id,string address,string filename);
	string toString(char **args, int argc);
	void showvalue(string value, bool b);
	void runProgramm(int argc, char **argv);
	virtual ~AddressdatenCMDL();
private:
};

} /* namespace programm */

#endif /* ADDRESSDATENCMDL_H_ */
