#include <cstdlib>

#include "hw09jewel.h"

using namespace std;

Jewel::Jewel(City& city) {
	bool locationFree = false;

	int xCoord;
	int yCoord;

	while (!locationFree) {
		// generate random coordinates for the jewel
		int xCoordinate = (rand() % (9 - 0 + 1)) + 0;
		int yCoordinate = (rand() % (9 - 0 + 1)) + 0;
		// ensure the city location is free
		if (city.getCityMap(xCoordinate, yCoordinate) == ' ') {
			locationFree = true;
			xCoord = xCoordinate;
			yCoord = yCoordinate;
		}
	}

	// set jewel coordinates
	j_XCoordinate = xCoord;
	j_YCoordinate = yCoord;
	// set jewel value
	j_Value = xCoord + yCoord;
	// update city map
	city.setCityMap(xCoord, yCoord, 'J');
	// increment number of jewels
	city.addNumJewels();
}

bool Jewel::getInPlay() const { return j_inPlay; }

int Jewel::getXCoord() const { return j_XCoordinate; }

int Jewel::getYCoord() const { return j_YCoordinate; }

int Jewel::getValue() const { return j_Value; }

void Jewel::deactivate() { j_inPlay = false; }

void Jewel::activate() { j_inPlay = true; }

void Jewel::setXCoord(const int input) { j_XCoordinate = input; }

void Jewel::setYCoord(const int input) { j_YCoordinate = input; }