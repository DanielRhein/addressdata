/*
 * AddressdatenCMDL.cpp
 *
 *  Created on: 31.08.2018
 *      Author: daniel
 */

#include "AddressdatenCMDL.h"


namespace programm {
using namespace std;
using namespace debug;
AddressdatenCMDL::AddressdatenCMDL() {
	// TODO Auto-generated constructor stub
}

void AddressdatenCMDL::showFileContent(string filename) {
	ifstream info;
	string readline;
	info.open(filename);
	if (!info.fail()) {
		while (getline(info, readline)) {
			mycmd << readline << mycmd.endl();
		}
	} else {
		cerr << "File not found: " << filename << endl;
	}
	info.close();
}

bool  AddressdatenCMDL::question(string question, string positive, string negative,
		string default_value) {
	bool retry = true;
	do {
		string input = "";
		mycmd << question << mycmd.endl();
		cout << "(" << positive << "/" << negative
				<< ") default on empty input (" << default_value << "): ";
		getline(cin, input);

		if (!cin.fail()) {
			if (input.empty()) {
				if (default_value == positive) {
					mycmd << "Your default input was positive." << mycmd.endl();
					return true;
				} else {
					mycmd <<"Your default input was negative."<< mycmd.endl();
					return false;
				}

			} else {
				if (input == positive) {
					retry = false;
					mycmd << "Your input was positive." << mycmd.endl();
					return true;
				} else if (input == negative) {
					retry = false;
					mycmd << "Your input was positive." << mycmd.endl();
					return false;
				} else {
					mycmd << "Wrong input detected. Request will start soon." << mycmd.endl();
					retry = true;
				}
			}
		}
	} while (retry);
}


void AddressdatenCMDL::removeData(string filename, u_int32_t &ULL_id) {
	ifstream info;
	ofstream ostream;
	string readline;
	u_int32_t ULL_count = 0;

	cout << "Loading data of file " << filename << endl;
	info.open(filename);
	ostream.open("temp.txt");
	cout << "Reading data of file " << filename << endl;
	if (!info.fail()) {
		while (getline(info, readline)) {
			ULL_count++;
			if (ULL_id == ULL_count) {
				cout << "Found entry:" << readline << endl;
				if (question("Would you like to delete it", "Y", "N", "Y")) {
					cout << "Entry will be deleted." << endl;
				} else {
					ostream << readline;
				}
			} else {
				ostream << readline;
			}

		}
	} else {
		cerr << "File not found: " << filename << endl;
	}
	info.close();
	ostream.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
}

void AddressdatenCMDL::removeDataInteractively(string filename) {
	ifstream info;
	string readline;
	stringstream ss;
	u_int32_t ULL_count = 0;
	cout << "Loading data of file " << filename << endl;
	info.open(filename);
	cout << "Counting data of file " << filename << endl;
	if (!info.fail()) {
		while (getline(info, readline)) {
			ULL_count++;
			ss << "Would you like to delete this data? " << readline;
			if (question(ss.str(), "Y", "N", "Y")) {
				info.close();
				removeData(filename, ULL_count);
			}
			ss.clear();
		}
	} else {
		cerr << "File not found: " << filename << endl;
	}
	info.close();
}

u_int32_t AddressdatenCMDL::countFileContent(string filename) {
	ifstream info;
	string readline;
	u_int32_t ULL_count = 0;
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
	cout << "I've counted " << ULL_count << " addresses in address data."
			<< endl;
	return ULL_count;
}

void AddressdatenCMDL::writeAddress(string filename, Address addresse) {
	ofstream outputfile;
	outputfile.open(filename, ios_base::app);
	if (!outputfile.fail()) {
		outputfile << addresse.getSaveString() << endl;
	} else {
		cerr << "Can't create file: " << filename << endl;
	}
}

bool AddressdatenCMDL::hastoken(string param, string value) {
	size_t found = param.find(value);
	if (found != std::string::npos) {
		return true;
	} else {
		return false;
	}
}


void AddressdatenCMDL::split(const string& s, char delim, vector<string>& v) {
	auto i = 0;
	auto pos = s.find(delim);
	while (pos != string::npos) {
		v.push_back(s.substr(i, pos - i));
		i = ++pos;
		pos = s.find(delim, pos);

		if (pos == string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

string AddressdatenCMDL::getInput(string bez) {
	string line;
	do {
		cout << bez << ": ";
		getline(cin, line);
	} while (line.empty());
	return line;
}


string AddressdatenCMDL::getAddress(char argv[]) {
	string text(argv);
	vector<string> result;
	split(text, ' ', result);
	return result[result.size()];
}


Address AddressdatenCMDL::getAddressInteractivelyFromInput() {
	Address addresse;
	addresse.setName(getInput("Name"));
	addresse.setVorname(getInput("Vorname"));
	addresse.setStrasse(getInput("Straße"));
	addresse.setHausnummer(getInput("Hausnummer"));
	addresse.setPostleitzahl(getInput("PLZ"));
	addresse.setOrt(getInput("Ort"));
	addresse.setGeburtstag(
			Address::parseDateTime(getInput("Geburtstag (10.1.2017 00:00:00")));
	return addresse;
}

void AddressdatenCMDL::searchAddressInFileContent(Address searchAddress, string filename) {
	ifstream info;
	string readline;
	u_int32_t ULL_count = 0;
	Address readAddress;
	info.open(filename);
	if (!info.fail()) {
		while (getline(info, readline)) {
			ULL_count++;
			cout << "Readline: " << readline << endl;
			Address readAddress = Address::parseAddress(readline,Address::DELIMITER);
			cout << "Read address: " << readAddress.getSaveString() << endl;

			if (!searchAddress.getName().empty()) {
				if (readAddress.getName() == searchAddress.getName()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "Name not found." << endl;
				}
			}
			if (!searchAddress.getVorname().empty()) {
				if (readAddress.getVorname() == searchAddress.getVorname()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "Vorname not found." << endl;
				}
			}
			if (!searchAddress.getFormattedGeburtstag().empty()) {
				if (readAddress.getFormattedGeburtstag()
						== searchAddress.getFormattedGeburtstag()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "Geburtstag not found." << endl;
				}
			}
			if (!searchAddress.getHausnummer().empty()) {
				if (readAddress.getHausnummer()
						== searchAddress.getHausnummer()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "Hausnummer not found." << endl;
				}
			}
			if (!searchAddress.getOrt().empty()) {
				if (readAddress.getOrt() == searchAddress.getOrt()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "Ort not found." << endl;
				}
			}
			if (!searchAddress.getPostleitzahl().empty()) {
				if (readAddress.getPostleitzahl()
						== searchAddress.getPostleitzahl()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "PLZ not found." << endl;
				}
			}
		}
	} else {
		cerr << "File not found: " << filename << endl;
	}
	info.close();
}

void AddressdatenCMDL::searchAddressInteractively(string filename) {
	cout << "Please give me your Addressdatainformation" << endl;
	Address address = getAddressInteractivelyFromInput();
	searchAddressInFileContent(address, filename);
}

void AddressdatenCMDL::addAddress(string argv, string filename) {
	cout << "Reading address " << argv << endl;
	Address myaddress = Address::parseAddress(argv,",");
	cout << "Read address: " << myaddress.getSaveString() << endl;
	writeAddress(filename, myaddress);
	cout << "Saved address to file " << filename << endl;
}


string AddressdatenCMDL::toString(char **args, int argc) {
	cout << "Retrieve parameter with count " << argc << endl;
	stringstream mystringstream;
	for (int i = 2; i < argc; i++) {
		if (i == 2 || i==3) {
			mystringstream << args[i] << " ";
		} else if (i == 9) {
			mystringstream << args[i];
		} else {
			mystringstream << args[i] << ",";
		}
		cout << "Reading parameter " << args[i] << endl;
	}
	return mystringstream.str();
}

void AddressdatenCMDL::showvalue(string value, bool b) {
	cout << value << ":" << b << endl;
}

void AddressdatenCMDL::runProgramm(int argc, char **argv) {
	bool add, remove, search, interactive, kp, count;
	string addressfile = "addressen.csv";
	stringstream ss();
	string params;
	for (int i = 0; i < argc; i++) {
		params.append(argv[i]);
	}

	if (argc == 1) {
		showFileContent("bannersimple");
		showFileContent("runinfo");
	} else {
		add = hastoken(params, "-a");
		search = hastoken(params, "-s");
		interactive = hastoken(params, "-i");
		remove = hastoken(params, "-r");
		count = hastoken(params, "-c");
		kp = hastoken(params, "-k");
		showvalue("add", add);
		showvalue("search", search);
		showvalue("interactive", interactive);
		showvalue("remove", remove);
		showvalue("count", count);
		showvalue("koelnerphonetic", kp);

		if (add && interactive) {
			Address address = getAddressInteractivelyFromInput();
			writeAddress(addressfile, address);
		}
		if (remove && interactive) {
			removeDataInteractively(addressfile);
		}
		if (search && interactive) {
			searchAddressInteractively(addressfile);
		}
		if (search && interactive && kp) {
			cout << "Not yet implemented." << endl;
		}
		if (search && !interactive) {
			cout << "search addressdata." << endl;
			if (argc > 2) {
				string args = toString(argv, argc);
				if (!args.empty()) {
					searchAddressInFileContent(Address::parseAddress(args,","),
							addressfile);
				} else {
					cerr << "Addressdaten nicht gefunden." << endl;
				}
			} else {
				cerr << "Nicht genuegend Parameter." << endl;
			}
		}
		if (remove && !interactive) {
			cout << "Remove addressdata." << endl;
			if (argc > 2) {
				u_int32_t ULL_id = 0;
				ULL_id = atoi(argv[2]);
				cout << "Addressdata Nr. " << argv[2]
						<< "will be transformed to " << ULL_id << endl;
				u_int32_t ULL_count = countFileContent(addressfile);
				if (ULL_id > 0 && ULL_id <= ULL_count) {
					removeData(addressfile, ULL_id);
				} else {
					cerr << "Your id " << ULL_id
							<< " is not in range of the current count"
							<< ULL_count << endl;
				}
			} else {
				cerr << "Nicht genuegend Parameter." << endl;
			}
		}
		if (add && !interactive) {
			cout << "Add addressdata." << endl;
			if (argc > 2) {
				string args = toString(argv, argc);
				if (!args.empty()) {
					addAddress(args, addressfile);
				} else {
					cerr << "Addressdaten nicht gefunden." << endl;
				}
			} else {
				cerr << "Nicht genuegend Parameter." << endl;
			}
		}
		if (count) {
			countFileContent(addressfile);
		}
	}
}


AddressdatenCMDL::~AddressdatenCMDL() {
	// TODO Auto-generated destructor stub
}



} /* namespace programm */

/*#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Address.h"
using namespace std;

void showvalue(string value, bool b) {
	cout << value << ":" << b << endl;
}

int main(int argc, char **argv) {
	bool add, remove, search, interactive, kp, count;
	string addressfile = "addressen.csv";
	stringstream ss();
	string params;
	for (int i = 0; i < argc; i++) {
		params.append(argv[i]);
	}

	if (argc == 1) {
		showFileContent("bannersimple");
		showFileContent("runinfo");
	} else {
		add = hastoken(params, "-a");
		search = hastoken(params, "-s");
		interactive = hastoken(params, "-i");
		remove = hastoken(params, "-r");
		count = hastoken(params, "-c");
		kp = hastoken(params, "-k");
		showvalue("add", add);
		showvalue("search", search);
		showvalue("interactive", interactive);
		showvalue("remove", remove);
		showvalue("count", count);
		showvalue("koelnerphonetic", kp);

		if (add && interactive) {
			Address address = getAddressInteractivelyFromInput();
			writeAddress(addressfile, address);
		}
		if (remove && interactive) {
			removeDataInteractively(addressfile);
		}
		if (search && interactive) {
			searchAddressInteractively(addressfile);
		}
		if (search && interactive && kp) {
			cout << "Not yet implemented." << endl;
		}
		if (search && !interactive) {
			cout << "search addressdata." << endl;
			if (argc > 2) {
				string args = toString(argv, argc);
				if (!args.empty()) {
					searchAddressInFileContent(Address::parseAddress(args,","),
							addressfile);
				} else {
					cerr << "Addressdaten nicht gefunden." << endl;
				}
			} else {
				cerr << "Nicht genuegend Parameter." << endl;
			}
		}
		if (remove && !interactive) {
			cout << "Remove addressdata." << endl;
			if (argc > 2) {
				u_int32_t ULL_id = 0;
				ULL_id = atoi(argv[2]);
				cout << "Addressdata Nr. " << argv[2]
						<< "will be transformed to " << ULL_id << endl;
				u_int32_t ULL_count = countFileContent(addressfile);
				if (ULL_id > 0 && ULL_id <= ULL_count) {
					removeData(addressfile, ULL_id);
				} else {
					cerr << "Your id " << ULL_id
							<< " is not in range of the current count"
							<< ULL_count << endl;
				}
			} else {
				cerr << "Nicht genuegend Parameter." << endl;
			}
		}
		if (add && !interactive) {
			cout << "Add addressdata." << endl;
			if (argc > 2) {
				string args = toString(argv, argc);
				if (!args.empty()) {
					addAddress(args, addressfile);
				} else {
					cerr << "Addressdaten nicht gefunden." << endl;
				}
			} else {
				cerr << "Nicht genuegend Parameter." << endl;
			}
		}
		if (count) {
			countFileContent(addressfile);
		}
	}
}
 *
 */
