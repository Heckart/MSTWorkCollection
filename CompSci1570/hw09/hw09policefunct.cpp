#include <cstdlib>

#include "hw09police.h"

using namespace std;

int Police::pNumPolice = 0;

Police::Police(City& city) {
	pNumPolice++;
	p_ID = pNumPolice;
	bool locationFree = false;

	int xCoord;
	int yCoord;

	while (!locationFree) {
		// generate random coordinates for the police
		int xCoordinate = (rand() % (9 - 0 + 1)) + 0;
		int yCoordinate = (rand() % (9 - 0 + 1)) + 0;
		// ensure the city location is free
		if (city.getCityMap(xCoordinate, yCoordinate) == ' ') {
			locationFree = true;
			xCoord = xCoordinate;
			yCoord = yCoordinate;
		}
	}

	// set police coordinates
	p_XCoordinate = xCoord;
	p_YCoordinate = yCoord;
	// update city map
	city.setCityMap(xCoord, yCoord, 'p');
}

void Police::arrest(Robber<Jewel>& robber, City& city) {
	robber.deactivateRobber();
	p_RobbersCaught++;
	p_LootVal = robber.getVal();
	robber.decreaseTotalVal(robber.getVal());
	robber.setVal(0);
	robber.zeroStolen();
	city.setCityMap(robber.getXCoord(), robber.getYCoord(), ' ');

	return;
}

void Police::move(City& city) {
	bool validPosition = false;

	if (city.getCityMap(p_XCoordinate, p_YCoordinate) == 'p') {
		city.setCityMap(p_XCoordinate, p_YCoordinate, ' ');
	}

	while (!validPosition) {  // ensure position exists in the array map
		int Coordinate = (rand() % (7 - 0 + 1)) + 0;
		if (Coordinate == 0 && p_XCoordinate > 0 && p_YCoordinate > 0) {
			p_XCoordinate--;
			p_YCoordinate--;
			validPosition = true;
		}
		if (Coordinate == 1 && p_YCoordinate > 0) {
			p_YCoordinate--;
			validPosition = true;
		}
		if (Coordinate == 2 && p_XCoordinate < 9 && p_YCoordinate > 0) {
			p_XCoordinate++;
			p_YCoordinate--;
			validPosition = true;
		}
		if (Coordinate == 3 && p_XCoordinate > 0) {
			p_XCoordinate--;
			validPosition = true;
		}
		if (Coordinate == 4 && p_XCoordinate < 9) {
			p_XCoordinate++;
			validPosition = true;
		}
		if (Coordinate == 5 && p_XCoordinate > 0 && p_YCoordinate < 9) {
			p_XCoordinate--;
			p_YCoordinate++;
			validPosition = true;
		}
		if (Coordinate == 6 && p_YCoordinate < 9) {
			p_YCoordinate++;
			validPosition = true;
		}
		if (Coordinate == 7 && p_XCoordinate < 9 && p_YCoordinate < 9) {
			p_XCoordinate++;
			p_YCoordinate++;
			validPosition = true;
		}
	}

	return;
}

int Police::getXCoord() const { return p_XCoordinate; }

int Police::getYCoord() const { return p_YCoordinate; }

int Police::getLootVal() const { return p_LootVal; }

int Police::getRobbersCaught() const { return p_RobbersCaught; }

int Police::getID() const { return p_ID; }

void Police::addLootVal(const int input) { p_LootVal += input; }