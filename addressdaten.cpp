#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "address.h"
using namespace std;

void showFileContent(string filename) {
	ifstream info;
	string readline;
	info.open(filename);
	if (!info.fail()) {
		while (getline(info, readline)) {
			cout << readline << endl;
		}
	} else {
		cerr << "File not found: " << filename << endl;
	}
	info.close();
}

void countFileContent(string filename) {
	ifstream info;
	string readline;
	unsigned long long ULL_count=0;
	cout << "Loading data of file " << filename << endl;
	info.open(filename);
	cout << "Counting data of file " << filename << endl;
	if (!info.fail()) {
		while (getline(info, readline)) {
			ULL_count++;
		}
	} else {
		cerr << "File not found: " << filename << endl;
	}
	info.close();
	cout << "I've counted " << ULL_count << " address in address data." << endl;
}

void writeAddress(string filename, address addresse) {
	ofstream outputfile;
	outputfile.open(filename, ios_base::app & ios_base::out);
	if (!outputfile.fail()) {
		outputfile << addresse.getSaveString() << endl;
	} else {
		cerr << "Can't create file: " << filename << endl;
	}
}

bool hastoken(string param, string value) {
	size_t found =param.find(value);
	if (found!=std::string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void split(const string& s, char delim,vector<string>& v) {
    auto i = 0;
    auto pos = s.find(delim);
    while (pos != string::npos) {
      v.push_back(s.substr(i, pos-i));
      i = ++pos;
      pos = s.find(delim, pos);


      if (pos == string::npos)
         v.push_back(s.substr(i, s.length()));
    }
}

string getAddress(char argv[]) {
	string text(argv);
	vector<string> result;
	split(text,' ',result);
	return result[result.size()];
}

string getInput(string bez)
{
	string line;
	do
	{
	cout << bez <<": ";
		getline(cin,line);
	}while(line.empty());
	return line;
}

address interactiveAddAddress()
{
	address addresse;
	addresse.setName(getInput("Name"));
	addresse.setVorname(getInput("Vorname"));
	addresse.setStrasse(getInput("Straße"));
	addresse.setHausnummer(getInput("Hausnummer"));
	addresse.setPostleitzahl(getInput("PLZ"));
	addresse.setOrt(getInput("Ort"));
	addresse.setGeburtstag(address::parseDateTime(getInput("Geburtstag (10.1.2017 00:00:00")));
	return addresse;
}

void showvalue(string value,bool b)
{
	cout << value << ":" << b <<endl;
}

int main(int argc, char **argv) {
	bool add, remove, search, interactive, count;
	string addressfile="addressen.csv";
	stringstream ss();
	string params;
	for(int i=0;i<argc;i++)
	{
		params.append(argv[i]);
	}

	if (argc == 1) {
		showFileContent("bannersimple");
		showFileContent("runinfo");
	} else {
		add = hastoken(params,"-a");
		search = hastoken(params,"-s");
		interactive = hastoken(params,"-i");
		remove = hastoken(params,"-r");
		count = hastoken(params,"-c");
		showvalue("add",add);
		showvalue("search",search);
		showvalue("interactive",interactive);
		showvalue("remove",remove);
		showvalue("count",count);

		if (add && interactive)
		{
			address address= interactiveAddAddress();
			writeAddress(addressfile,address);
		}
		if (remove && interactive)
		{
			cout << "Not yet implemented." << endl;
		}
		if (search && interactive)
		{
			cout << "Not yet implemented." << endl;
		}
		if (search && !interactive)
		{
			cout << "Not yet implemented." << endl;
		}
		if (remove && !interactive)
		{
			cout << "Not yet implemented." << endl;
		}
		if (count)
		{
			countFileContent(addressfile);
		}
	}
}
