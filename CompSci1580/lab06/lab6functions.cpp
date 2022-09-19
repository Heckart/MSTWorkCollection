#include <iostream>

#include "lab6header.h"

using namespace std;

void printSlimes(Slime slimes) {
	static int numSlime = 0;
	numSlime++;

	cout << "Slime number " << numSlime << endl;
	cout << "Name - " << slimes.m_firstName << " " << slimes.m_lastName << endl;
	cout << "Violence Level - " << slimes.m_lvlViolence << endl;
	cout << "Age - " << slimes.m_age << endl;
	cout << "Wants to hurt you - ";
	if (slimes.m_dangerous == true) {
		cout << "Yes" << endl;
		cout << "I'd steer clear of this one." << endl;
	} else {
		cout << "No" << endl;
		cout << "Seems safe to me!" << endl;
	}
	cout << "" << endl;

	return;
}