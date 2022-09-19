#include <iostream>

#include "hw09city.h"

using namespace std;

City::City() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {	// populate city map
			c_CityMap[i][j] = ' ';
		}
	}
}

void City::setCityMap(const int xCoord, const int yCoord, const char input) {
	if (xCoord >= 0 && xCoord <= 9) {  // ensure input location exists in the array
		if (yCoord >= 0 && yCoord <= 9) {
			c_CityMap[xCoord][yCoord] = input;
		}
	} else {
		cout << "Error: requested coordinates do not exist in the array";
	}
	return;
}

void City::addNumJewels() { c_NumJewels++; }

char City::getCityMap(const int xCoord, const int yCoord) const { return c_CityMap[xCoord][yCoord]; }

int City::getNumJewels() const { return c_NumJewels; }

void City::decrementJewels() { c_NumJewels--; }