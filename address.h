/*
 * address.h
 *
 *  Created on: 28.07.2018
 *      Author: daniel
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;
class address {
private:
	static const char* TIMESTRING;
	string name;
	string vorname;
	string strasse;
	string hausnummer;
	string postleitzahl;
	string ort;
	tm geburtstag;
public:
	static const string DELIMITER;
	address();
	string getName();
	string getVorname();
	string getStrasse();
	string getPostleitzahl();
	string getHausnummer();
	string getOrt();
	string getFormattedGeburtstag();
	string getSaveString();
	static address parseAddress(string address,string delimiter);
	static tm parseDateTime(string datetime);
	tm getGeburtstag();
	void setName(string name);
	void setVorname(string vorname);
	void setStrasse(string strasse);
	void setHausnummer(string hausummer);
	void setPostleitzahl(string postleitzahl);
	void setOrt(string ort);
	void setGeburtstag(tm geburtstag);
	virtual ~address();
};

#endif /* ADDRESS_H_ */

