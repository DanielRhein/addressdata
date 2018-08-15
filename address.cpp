/*
 * address.cpp
 *
 *  Created on: 28.07.2018
 *      Author: daniel
 */

#include "address.h"
#include <sstream>

const string address::DELIMITER=";";
const char* address::TIMESTRING="%d.%m.%Y %H:%M:%S";

address::address() {
	name="";
	vorname="";
	strasse="";
	hausnummer="";
	postleitzahl="";
	ort="";
	struct tm t;
	geburtstag=t;
}

address::~address() {

}

string address::getFormattedGeburtstag(void)
{
	tm * geburtstagptr = &geburtstag;
	char returnval[80] = "";
	strftime(returnval,80,TIMESTRING,geburtstagptr);
	return returnval;
}

tm address::getGeburtstag(void)
{
	return geburtstag;
}

string address::getHausnummer(void)
{
	return hausnummer;
}

string address::getName(void)
{
	return name;
}


string address::getVorname(void)
{
	return vorname;
}

string address::getOrt()
{
	return ort;
}

string address::getPostleitzahl()
{
	return postleitzahl;
}

string address::getSaveString()
{
	stringstream stream;
	stream << name
		   << DELIMITER << vorname
		   << DELIMITER << strasse
		   << DELIMITER << hausnummer
		   << DELIMITER << postleitzahl
		   << DELIMITER << ort
		   << DELIMITER << this->getFormattedGeburtstag();
	return stream.str();
}


string address::getStrasse()
{
	return strasse;
}

void address::setGeburtstag(tm geburtstag)
{
	this->geburtstag = geburtstag;
}

void address::setName(string name)
{
	this->name = name;
}

void address::setOrt(string ort)
{
	this->ort = ort;
}

void address::setPostleitzahl(string postleitzahl)
{
	this->postleitzahl = postleitzahl;
}

void address::setStrasse(string strasse)
{
	this->strasse = strasse;
}


void address::setVorname(string vorname)
{
	this->vorname = vorname;
}

void address::setHausnummer(string hausnummer)
{
	this->hausnummer = hausnummer;
}


address address::parseAddress(string strAddress)
{
	address result;
	if (strAddress.empty()) {
		return result;
	}
	size_t pos;
	string token;
	int i=0;
	while((pos=strAddress.find(DELIMITER,pos)) != string::npos)
	{
		token = strAddress.substr(0,pos);
		cout<<"read token" << token << endl;
		pos = pos + token.size();
		switch(i)
		{
		case 0://Name
			result.setName(token);
		break;
		case 1://Vorname
			result.setVorname(token);
		break;
		case 2://Hausnummer
			result.setHausnummer(token);
		break;
		case 3://Straße
			result.setStrasse(token);
		break;
		case 4://Postleitzahl
			result.setPostleitzahl(token);
		break;
		case 5://Ort
			result.setOrt(token);
		break;
		case 6://Geburtstag
			result.setGeburtstag(address::parseDateTime(token));
		break;
		}
		i++;
	}
}

tm address::parseDateTime(string datetime)
{
	struct tm t;
	if (datetime=="") return t;
	const char *myformatstring = datetime.c_str();
	strptime(myformatstring,TIMESTRING,&t);
	return t;
}
