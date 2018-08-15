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

bool question(string question, string positive, string negative,
		string default_value) {
	bool retry = true;
	do {
		string input = "";
		cout << question << endl;
		cout << "(" << positive << "/" << negative
				<< ") default on empty input (" << default_value << "): ";
		getline(cin, input);

		if (!cin.fail()) {
			if (input.empty()) {
				if (default_value == positive) {
					cout << "Your default input was positive." << endl;
					return true;
				} else {
					cout << "Your default input was negative." << endl;
					return false;
				}

			} else {
				if (input == positive) {
					retry = false;
					cout << "Your input was positive." << endl;
					return true;
				} else if (input == negative) {
					retry = false;
					cout << "Your input was negative." << endl;
					return false;
				} else {
					cout << "Wrong input detected. Request will start soon."
							<< endl;
					retry = true;
				}
			}
		}
	} while (retry);
}

void removeData(string filename, unsigned long long &ULL_id) {
	ifstream info;
	ofstream ostream;
	string readline;
	unsigned long long ULL_count = 0;

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

void removeDataInteractively(string filename) {
	ifstream info;
	string readline;
	stringstream ss;
	unsigned long long ULL_count = 0;
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

void countFileContent(string filename) {
	ifstream info;
	string readline;
	unsigned long long ULL_count = 0;
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
	size_t found = param.find(value);
	if (found != std::string::npos) {
		return true;
	} else {
		return false;
	}
}

void split(const string& s, char delim, vector<string>& v) {
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

string getAddress(char argv[]) {
	string text(argv);
	vector<string> result;
	split(text, ' ', result);
	return result[result.size()];
}

string getInput(string bez) {
	string line;
	do {
		cout << bez << ": ";
		getline(cin, line);
	} while (line.empty());
	return line;
}

address getAddressInteractivelyFromInput() {
	address addresse;
	addresse.setName(getInput("Name"));
	addresse.setVorname(getInput("Vorname"));
	addresse.setStrasse(getInput("Straße"));
	addresse.setHausnummer(getInput("Hausnummer"));
	addresse.setPostleitzahl(getInput("PLZ"));
	addresse.setOrt(getInput("Ort"));
	addresse.setGeburtstag(
			address::parseDateTime(getInput("Geburtstag (10.1.2017 00:00:00")));
	return addresse;
}

void searchAddressInFileContent(address searchAddress, string filename) {
	ifstream info;
	string readline;
	unsigned long long ULL_count = 0;
	address readAddress;
	info.open(filename);
	if (!info.fail()) {
		while (getline(info, readline)) {
			ULL_count++;
			address readAddress = address::parseAddress(readline);
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
					cout << "Name not found." << endl;
				}
			}
			if (!searchAddress.getFormattedGeburtstag().empty()) {
				if (readAddress.getFormattedGeburtstag()
						== searchAddress.getFormattedGeburtstag()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "Name not found." << endl;
				}
			}
			if (!searchAddress.getHausnummer().empty()) {
				if (readAddress.getHausnummer()
						== searchAddress.getHausnummer()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "Name not found." << endl;
				}
			}
			if (!searchAddress.getOrt().empty()) {
				if (readAddress.getOrt() == searchAddress.getOrt()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "Name not found." << endl;
				}
			}
			if (!searchAddress.getPostleitzahl().empty()) {
				if (readAddress.getPostleitzahl()
						== searchAddress.getPostleitzahl()) {
					cout << ULL_count << readline << endl;
				} else {
					cout << "Name not found." << endl;
				}
			}
		}
	} else {
		cerr << "File not found: " << filename << endl;
	}
	info.close();
}

void searchAddressInteractively(string filename) {
	cout << "Please give me your Addressdatainformation" << endl;
	address address = getAddressInteractivelyFromInput();
	searchAddressInFileContent(address, filename);
}

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
			address address = getAddressInteractivelyFromInput();
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
			cout << "Not yet implemented." << endl;
		}
		if (remove && !interactive) {
			cout << "Not yet implemented." << endl;
		}
		if (count) {
			countFileContent(addressfile);
		}
	}
}
