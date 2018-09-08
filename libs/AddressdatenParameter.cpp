/*
 * AddressdatenParameter.cpp
 *
 *  Created on: 05.09.2018
 *      Author: daniel
 */

#include "AddressdatenParameter.h"

namespace programm {
using namespace std;

 const std::string AddressdatenParameter::ADD = "a";
const std::string AddressdatenParameter::SEARCH = "s";
const std::string AddressdatenParameter::EDIT = "e";
const std::string AddressdatenParameter::INTERACTIVE = "i";
const std::string AddressdatenParameter::REMOVE = "r";
const std::string AddressdatenParameter::COUNT = "c";
const std::string AddressdatenParameter::KOELNERPHONETIC = "k";
const std::string AddressdatenParameter::OPTIONENTRY = "-";

AddressdatenParameter::~AddressdatenParameter() {
	// TODO Auto-generated destructor stub
}

AddressdatenParameter::AddressdatenParameter() {
	interactive = false;
	add = false;
	remove = false;
	edit = false;
	koelnerphonetic = false;
	search = false;
	count = false;
}

void AddressdatenParameter::analyseparams(std::string param) {
	interactive = hasInteractiveToken(param);
	add = hasAddToken(param);
	remove = hasRemoveToken(param);
	edit = hasEditToken(param);
	koelnerphonetic = hasKoelnerphoneticToken(param);
	search = hasSearchToken(param);
	count = hasCountToken(param);
}

bool AddressdatenParameter::isCount() {
	return count;
}

bool AddressdatenParameter::isEdit() {
	return edit;
}

bool AddressdatenParameter::isInteractive() {
	return interactive;
}

bool AddressdatenParameter::isKoelnerPhonetic() {
	return koelnerphonetic;
}

bool AddressdatenParameter::isRemove() {
	return remove;
}

bool AddressdatenParameter::isSearch() {
	return search;
}

bool AddressdatenParameter::isAdd() {
	return add;
}

bool AddressdatenParameter::hastoken(string param, string value) {
	size_t found = param.find(value);
	if (found != string::npos) {
		return true;
	} else {
		return false;
	}
}

bool AddressdatenParameter::hasSearchToken(std::string param) {
	return hastoken(param, OPTIONENTRY + SEARCH);
}

bool AddressdatenParameter::hasAddToken(std::string param) {
	return hastoken(param, OPTIONENTRY + ADD);
}
bool AddressdatenParameter::hasInteractiveToken(std::string param) {
	return hastoken(param, OPTIONENTRY + INTERACTIVE);
}

bool AddressdatenParameter::hasRemoveToken(std::string param) {
	return hastoken(param, OPTIONENTRY + REMOVE);
}
bool AddressdatenParameter::hasCountToken(std::string param) {
	return hastoken(param, OPTIONENTRY + COUNT);
}
bool AddressdatenParameter::hasKoelnerphoneticToken(std::string param) {
	return hastoken(param, OPTIONENTRY + KOELNERPHONETIC);
}
bool AddressdatenParameter::hasEditToken(std::string param) {
	return hastoken(param, OPTIONENTRY + EDIT);
}

std::vector<AddressdatenParameter::PARAMETER> AddressdatenParameter::getStatus() {
	std::vector<PARAMETER> parameters;
	if (isCount()) {
		parameters.push_back(P_COUNT);
	}
	if (isInteractive() && isAdd()) {
		parameters.push_back(P_ADDINTERACTIVE);
	}
	if (!isInteractive() && isAdd()) {
		parameters.push_back(P_ADD);
	}
	if (isInteractive() && isEdit()) {
		parameters.push_back(P_EDITINTERACTIVE);
	}
	if (!isInteractive() && isEdit()) {
		parameters.push_back(P_EDIT);
	}
	if (isInteractive() && isSearch()) {
		parameters.push_back(P_SEARCHINTERACTIVE);
	}
	if (!isInteractive() && isSearch()) {
		parameters.push_back(P_SEARCH);
	}
	if (!isInteractive() && isSearch() && isKoelnerPhonetic()) {
		parameters.push_back(P_KOELNERPHONETIC);
	}
	if (isInteractive() && isSearch() && isKoelnerPhonetic()) {
		parameters.push_back(P_KOELNERPHONETICINTERACTIVE);
	}
	if (!isInteractive() && isRemove()) {
		parameters.push_back(P_REMOVE);
	}
	if (isInteractive() && isRemove()) {
		parameters.push_back(P_REMOVEINTERACTIVE);
	}
	return parameters;
}

} /* namespace programm */
