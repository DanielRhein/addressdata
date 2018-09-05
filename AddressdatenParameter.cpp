/*
 * AddressdatenParameter.cpp
 *
 *  Created on: 05.09.2018
 *      Author: daniel
 */

#include "AddressdatenParameter.h"

namespace programm {
using namespace std;
AddressdatenParameter::AddressdatenParameter() {
	// TODO Auto-generated constructor stub

}

AddressdatenParameter::~AddressdatenParameter() {
	// TODO Auto-generated destructor stub
}

AddressdatenParameter::AddressdatenParameter()
{
	interactive=false;
	add=false;
	remove=false;
	edit=false;
	koelnerphonetic=false;
	search=false;
	count=false;
}

bool AddressdatenParameter::hastoken(string param, string value) {
	size_t found = param.find(value);
	if (found != string::npos) {
		return true;
	} else {
		return false;
	}
}

bool AddressdatenParameter::hasSearchToken(std::string param);
bool AddressdatenParameter::hasAddToken(std::string param);
bool AddressdatenParameter::hasInteractiveToken(std::string param);
bool AddressdatenParameter::hasRemoveToken(std::string param);
bool AddressdatenParameter::hasCountToken(std::string param);
bool AddressdatenParameter::hasKoelnerphoneticToken(std::string param);
bool AddressdatenParameter::hasEditToken(std::string param);
} /* namespace programm */
