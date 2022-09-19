#include <string>

#include "lab7header.h"

using namespace std;

string findCriminal(string slimeArray[], const int ARRAYSIZE) {
	string guiltySlime = "";

	for (int i = 0; i < ARRAYSIZE; i++) {
		if (slimeArray[i].length() >= guiltySlime.length()) {
			guiltySlime = slimeArray[i];
		}
	}

	return guiltySlime;
}