// Programmer: Ethan Heckart
// Date: 3/14/22
// File: lab7main.cpp
// Purpose: Help Normo convict an innocent slime

#include <iostream>

#include "lab7header.h"

using namespace std;

int main() {
	string slimes[5] = {};
	const int SLIMEARRAYSIZE = 5;
	string guilty = "NULL";

	cout << "Please enter the names of  the 5 suspects." << endl;
	for (int i = 0; i < SLIMEARRAYSIZE; i++) {
		cin >> slimes[i];
	}

	cout << endl;
	guilty = findCriminal(slimes, SLIMEARRAYSIZE);
	cout << "The perpetrator was: " << guilty;

	return 0;
}