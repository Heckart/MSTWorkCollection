// Programmer: Ethan Heckart
// Date: 3/7/22
// File: lab6main.cpp
// Purpose: Help Normo determine which slimes are his friends and which aren't

#include <iostream>

#include "lab6header.h"

using namespace std;

int main() {
	Slime firstSlime = {"Slime", "Oore", 12.63, 23, 1};
	Slime secondSlime = {"Goo", "Laurie", 4.2, 62, 0};
	Slime thirdSlime = {"Stanley", "Koobleck", 812.6, 70, 1};

	Slime Array[3] = {firstSlime, secondSlime, thirdSlime};

	for (size_t i = 0; i < 3; i++) {
		printSlimes(Array[i]);
	}

	return 0;
}