// Programmer: Ethan Heckart
// File: lab11main.cpp
// Date: 4/25/22
// Purpose:

#include <iostream>

#include "lab11magicsmasher.h"

using namespace std;

int main() {
	MagicSmasher<int> msOne(420, 11);
	MagicSmasher<bool> msTwo(true, false);
	MagicSmasher<string> msThree("SawsonPawson", "MichaelPichael");

	int val1 = msOne.sum();
	bool val2 = msTwo.sum();
	string val3 = msThree.sum();

	cout << val1 << endl;
	cout << val2 << endl;
	cout << val3 << endl;

	return 0;
}