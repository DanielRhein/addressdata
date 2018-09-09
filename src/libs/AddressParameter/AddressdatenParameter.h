/*
 * AddressdatenParameter.h
 *
 *  Created on: 05.09.2018
 *      Author: daniel
 */

#ifndef ADDRESSDATENPARAMETER_H_
#define ADDRESSDATENPARAMETER_H_
#include <iostream>
#include <vector>
namespace programm {

class AddressdatenParameter : public std::streambuf
{
private:
	bool add,search,edit,interactive,remove,count,koelnerphonetic;
	static const std::string ADD;
	static const std::string SEARCH;
	static const std::string EDIT;
	static const std::string INTERACTIVE;
	static const std::string REMOVE;
	static const std::string COUNT;
	static const std::string KOELNERPHONETIC;
	static const std::string OPTIONENTRY;
	bool hasSearchToken(std::string param);
	bool hasAddToken(std::string param);
	bool hasInteractiveToken(std::string param);
	bool hasRemoveToken(std::string param);
	bool hasCountToken(std::string param);
	bool hasKoelnerphoneticToken(std::string param);
	bool hasEditToken(std::string param);
	bool hastoken(std::string param, std::string value);
public:
	enum PARAMETER{
		P_ADD,P_ADDINTERACTIVE,
		P_SEARCH,P_SEARCHINTERACTIVE,
		P_EDIT,P_EDITINTERACTIVE,
		P_REMOVE,P_REMOVEINTERACTIVE,
		P_COUNT,P_COUNTINTERACTIVE,
		P_KOELNERPHONETIC,P_KOELNERPHONETICINTERACTIVE
	};
	AddressdatenParameter();
	virtual ~AddressdatenParameter();
	void analyseparams(std::string param);
	bool isInteractive();
	bool isRemove();
	bool isCount();
	bool isSearch();
	bool isKoelnerPhonetic();
	bool isAdd();
	bool isEdit();
	std::vector<AddressdatenParameter::PARAMETER> getStatus();

	/*friend std::ostream &operator<<(std::ostream &output,
				const AddressdatenParameter &parameter) {
			output << "Add: "<< parameter.add << "\n";
			output	   << "Search:" << parameter.search << "\n";
					output	   << "Edit: "<< parameter.edit << "\n";
					output<< "Interactive:" << parameter.interactive <<"\n";
					output<< "Remove:" << parameter.remove << "\n";
					output<< "Count:" << parameter.count << "\n";
					output<< "Koelnerphonetic:" << parameter.koelnerphonetic << "\n";
			return output;
		}*/
};

} /* namespace programm */

#endif /* ADDRESSDATENPARAMETER_H_ */
