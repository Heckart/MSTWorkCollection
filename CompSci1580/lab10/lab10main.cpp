// Programmer: Ethan Heckart
// File: lab10main.cpp
// Date: 4/19/22
// Purpose: Main file for lab 10

#include <iostream>

#include "lab10guildmember.h"

using namespace std;

int main() {
	const int statsOne[5] = {8, 6, 7, 5, 3};
	const int statsTwo[5] = {0, 9, 8, 6, 7};
	GuildMember memberOne;
	GuildMember memberTwo("Kyle");
	GuildMember memberThree("Sawson", statsOne, 5);
	GuildMember memberFour("Pawson", statsTwo, 5);

	cout << memberOne;
	cout << memberTwo;
	cout << memberThree;
	cout << memberFour;

	cout << memberThree + memberFour;

	memberFour[3];

	std::cout << endl;

	return 0;
}