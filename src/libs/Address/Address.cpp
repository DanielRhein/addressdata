/*
 * address.cpp
 *
 *  Created on: 28.07.2018
 *      Author: daniel
 */

#include <sstream>
#include "Address.h"

const string Address::DELIMITER=";";
const char* Address::TIMESTRING="%d.%m.%Y %H:%M:%S";

Address::Address() {
	name="";
	vorname="";
	strasse="";
	hausnummer="";
	postleitzahl="";
	ort="";
	struct tm t;
	geburtstag=t;
}

Address::~Address() {

}

string Address::getFormattedGeburtstag(void)
{
	tm * geburtstagptr = &geburtstag;
	char returnval[80] = "";
	strftime(returnval,80,TIMESTRING,geburtstagptr);
	return returnval;
}

tm Address::getGeburtstag(void)
{
	return geburtstag;
}

string Address::getHausnummer(void)
{
	return hausnummer;
}

string Address::getName(void)
{
	return name;
}


string Address::getVorname(void)
{
	return vorname;
}

string Address::getOrt()
{
	return ort;
}

string Address::getPostleitzahl()
{
	return postleitzahl;
}

string Address::getSaveString()
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


string Address::getStrasse()
{
	return strasse;
}

void Address::setGeburtstag(tm geburtstag)
{
	this->geburtstag = geburtstag;
}

void Address::setName(string name)
{
	this->name = name;
}

void Address::setOrt(string ort)
{
	this->ort = ort;
}

void Address::setPostleitzahl(string postleitzahl)
{
	this->postleitzahl = postleitzahl;
}

void Address::setStrasse(string strasse)
{
	this->strasse = strasse;
}


void Address::setVorname(string vorname)
{
	this->vorname = vorname;
}

void Address::setHausnummer(string hausnummer)
{
	this->hausnummer = hausnummer;
}


Address Address::parseAddress(string strAddress,string delimiter)
{
	Address result;
	if (strAddress.empty()) {
		cout<<" Addresse  " << strAddress << " is empty " << endl;
		return result;
	}
	size_t pos=0;
	string token;
	int i=0;
	while((pos=strAddress.find(delimiter,pos)) != string::npos)
	{
		token = strAddress.substr(0,pos);
		strAddress = strAddress.substr(pos+1,strAddress.length());
		cout<<" read token: " << token << " at ( " << pos<< " ) " << endl;
		cout<<" String: " << strAddress << endl;
		switch(i)
		{
		case 0://Name
			cout<<" Set Name: " << token << endl;
			result.setName(token);
		break;
		case 1://Vorname
			cout<<" Set Vorname: " << token << endl;
			result.setVorname(token);
		break;
		case 2://Straße
			cout<<" Set Strasse: " << token << endl;
			result.setStrasse(token);
		break;
		case 3://Hausnummer
			cout<<" Set Hausnummer: " << token << endl;
			result.setHausnummer(token);
		break;
		case 4://Postleitzahl
			cout<<" Set Plz: " << token << endl;
			result.setPostleitzahl(token);
		break;
		case 5://Ort
			cout<<" Set Ort: " << token << endl;
			result.setOrt(token);
		break;
		}
		i++;
		pos=0;
	}
	if (!strAddress.empty())
	{
			cout<<" Geburtstagssring: " << strAddress << endl;
			result.setGeburtstag(Address::parseDateTime(strAddress));
	}
	return result;
}

tm Address::parseDateTime(string datetime)
{
	struct tm t;
	if (datetime=="") return t;
	const char *myformatstring = datetime.c_str();
	strptime(myformatstring,TIMESTRING,&t);
	return t;
}
