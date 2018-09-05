/*
 * AddressdatenParameter.h
 *
 *  Created on: 05.09.2018
 *      Author: daniel
 */

#ifndef ADDRESSDATENPARAMETER_H_
#define ADDRESSDATENPARAMETER_H_
#include <iostream>
namespace programm {

class AddressdatenParameter {
private:
private:
	bool add,search,edit,interactive,remove,count,koelnerphonetic;
	static const std::string ADD="a";
	static const std::string SEARCH="s";
	static const std::string EDIT="e";
	static const std::string INTERACTIVE="i";
	static const std::string REMOVE="r";
	static const std::string COUNT="c";
	static const std::string KOELNERPHONETIC="k";
	static const std::string OPTIONENTRY="-";
	bool hasSearchToken(std::string param);
	bool hasAddToken(std::string param);
	bool hasInteractiveToken(std::string param);
	bool hasRemoveToken(std::string param);
	bool hasCountToken(std::string param);
	bool hasKoelnerphoneticToken(std::string param);
	bool hasEditToken(std::string param);
	bool hastoken(std::string param, std::string value);
public:
	AddressdatenParameter();
	virtual ~AddressdatenParameter();
	bool analyseparams(std::string param);
	bool isInteractvie();
	bool isRemove();
	bool isCount();
	bool isSearch();
	bool isKoelnerPhonetic();
	bool isEdit();
};

} /* namespace programm */

#endif /* ADDRESSDATENPARAMETER_H_ */
