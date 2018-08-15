/*
 * KoelnerPhonetik.h
 *
 *  Created on: 04.08.2018
 *      Author: daniel
 */

#ifndef KOELNERPHONETIK_H_
#define KOELNERPHONETIK_H_
/*
 *
 */
#include <stdio.h>
#include <iostream>
using namespace std;
class KoelnerPhonetik {
private:
	 // Predefined char arrays for better performance and less GC load
	 static const char AEIJOUY[];
	 static const char SCZ[];
	 static const char WFPV[];
	 static const char GKQ[];
	 static const char CKQ[];
	 static const char AHKLOQRUX[];
	 static const char SZ[];
	 static const char AHOUKQX[];
	 static const char TDX[];
	 static const char PREPROCESS_MAP[][];
	 string preprocess(string text);
	 static bool arrayContains(char arr[], char key);
public:
	KoelnerPhonetik();
	string koelnerphonetik(string text);

	virtual ~KoelnerPhonetik();
};


#endif /* KOELNERPHONETIK_H_ */
