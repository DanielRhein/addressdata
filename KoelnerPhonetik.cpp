/*
 * KoelnerPhonetik.cpp
 *
 *  Created on: 04.08.2018
 *      Author: daniel
 */

#include "KoelnerPhonetik.h"

 // Predefined char arrays for better performance and less GC load
const char KoelnerPhonetik::AEIJOUY[] = new char[] { 'A', 'E', 'I', 'J', 'O', 'U', 'Y' };
const char KoelnerPhonetik::SCZ[] = new char[] { 'S', 'C', 'Z' };
const char KoelnerPhonetik::WFPV[] = new char[] { 'W', 'F', 'P', 'V' };
const char KoelnerPhonetik::GKQ[] = new char[] { 'G', 'K', 'Q' };
const char KoelnerPhonetik::CKQ[] = new char[] { 'C', 'K', 'Q' };
const char KoelnerPhonetik::AHKLOQRUX[] = new char[] { 'A', 'H', 'K', 'L', 'O', 'Q', 'R', 'U', 'X' };
const char KoelnerPhonetik::SZ[] = new char[] { 'S', 'Z' };
const char KoelnerPhonetik::AHOUKQX[] = new char[] { 'A', 'H', 'O', 'U', 'K', 'Q', 'X' };
const char KoelnerPhonetik::TDX[] = new char[] { 'T', 'D', 'X' };

/**
     * Maps some Germanic characters to plain for internal processing. The following characters are mapped:
     * <ul>
     * <li>capital a, umlaut mark</li>
    * <li>capital u, umlaut mark</li>
     * <li>capital o, umlaut mark</li>
     * <li>small sharp s, German</li>
     * </ul>
     */
 static const char KoelnerPhonetik::PREPROCESS_MAP[][] = new char[][]{
        {'\u00C4', 'A'}, // capital a, umlaut mark
        {'\u00DC', 'U'}, // capital u, umlaut mark
        {'\u00D6', 'O'}, // capital o, umlaut mark
        {'\u00DF', 'S'} // small sharp s, German
   };

static bool KoelnerPhonetik::arrayContains(char[] arr, char key) {
	for (char element : arr) {
            if (element == key) {
                return true;
            }
        }
        return false;
    }
}

KoelnerPhonetik::KoelnerPhonetik() {
	// TODO Auto-generated constructor stub

}

KoelnerPhonetik::~KoelnerPhonetik() {
	// TODO Auto-generated destructor stub
}

string KoelnerPhonetik::koelnerphonetik(string text)
{
	char* input;
	stringstream ss;
	char code;
	char chr;

	char lastcode='-';
	char lastchar='/';

	char nextchar;

	input = text..c_str()

}
