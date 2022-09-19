#include "hw09jewel.h"

using namespace std;

template <class T>
int Robber<T>::rTotalValStolen = 0;

template <class T>
int Robber<T>::rTotalNumRobbers = 0;

template <class T>
Robber<T>::Robber(City& city, const bool greedy) {
	rTotalNumRobbers++;
	r_ID = rTotalNumRobbers;
	r_ValStolen = 0;
	r_NumStolen = 0;

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

	if (greedy == true) {
		r_IsGreedy = true;
	} else {
		r_IsGreedy = false;
	}

	// set police coordinates
	r_XCoordinate = xCoord;
	r_YCoordinate = yCoord;
	// update city map
	city.setCityMap(xCoord, yCoord, 'r');
}

template <class T>
void Robber<T>::move(City& city) {
	if (r_Active) {
		bool validPosition = false;

		if (city.getCityMap(r_XCoordinate, r_YCoordinate) == 'r') {	 // update the map as necessary
			city.setCityMap(r_XCoordinate, r_YCoordinate, ' ');
		} else if (city.getCityMap(r_XCoordinate, r_YCoordinate) == 'R') {
			city.setCityMap(r_XCoordinate, r_YCoordinate, 'r');
		}

		while (!validPosition) {  // ensure position exists in the array
			int Coordinate = (rand() % (7 - 0 + 1)) + 0;
			if (Coordinate == 0 && r_XCoordinate > 0 && r_YCoordinate > 0) {
				r_XCoordinate--;
				r_YCoordinate--;
				validPosition = true;
			}
			if (Coordinate == 1 && r_YCoordinate > 0) {
				r_YCoordinate--;
				validPosition = true;
			}
			if (Coordinate == 2 && r_XCoordinate < 9 && r_YCoordinate > 0) {
				r_XCoordinate++;
				r_YCoordinate--;
				validPosition = true;
			}
			if (Coordinate == 3 && r_XCoordinate > 0) {
				r_XCoordinate--;
				validPosition = true;
			}
			if (Coordinate == 4 && r_XCoordinate < 9) {
				r_XCoordinate++;
				validPosition = true;
			}
			if (Coordinate == 5 && r_XCoordinate > 0 && r_YCoordinate < 9) {
				r_XCoordinate--;
				r_YCoordinate++;
				validPosition = true;
			}
			if (Coordinate == 6 && r_YCoordinate < 9) {
				r_YCoordinate++;
				validPosition = true;
			}
			if (Coordinate == 7 && r_XCoordinate < 9 && r_YCoordinate < 9) {
				r_XCoordinate++;
				r_YCoordinate++;
				validPosition = true;
			}
		}
	}
	return;
}

template <class T>
void Robber<T>::pickUpLoot(T arr[], const int len) {
	for (int i = 0; i < len; i++) {	 // put jewel in bag and update loot totals
		if (arr[i].getInPlay() && arr[i].getXCoord() == getXCoord() && arr[i].getYCoord() == getYCoord()) {
			arr[i].deactivate();
			r_MostRecentStolenVal = arr[i].getXCoord() + arr[i].getYCoord();
			r_ValStolen += r_MostRecentStolenVal;
			rTotalValStolen += r_MostRecentStolenVal;
			r_Bag[r_NumStolen - 1] = arr[i];
		}
	}

	return;
}

template <class T>
void Robber<T>::deactivateBag(const int index) {  // deactivate jewel in bag, and removed the value of the jewel from the totals
	r_Bag[index].deactivate();
	r_ValStolen -= r_Bag[index].getValue();
	rTotalValStolen -= r_Bag[index].getValue();

	return;
}

template <class T>
int Robber<T>::getXCoord() const {
	return r_XCoordinate;
}

template <class T>
int Robber<T>::getYCoord() const {
	return r_YCoordinate;
}

template <class T>
int Robber<T>::getMostRecentStolenVal() const {
	return r_MostRecentStolenVal;
}

template <class T>
int Robber<T>::getNumStolen() const {
	return r_NumStolen;
}

template <class T>
int Robber<T>::getVal() const {
	return r_ValStolen;
}

template <class T>
int Robber<T>::getTotalVal() const {
	return rTotalValStolen;
}

template <class T>
int Robber<T>::getID() const {
	return r_ID;
}

template <class T>
void Robber<T>::setVal(const int input) {
	r_ValStolen = input;
	return;
}

template <class T>
void Robber<T>::incrementNumStolen() {
	r_NumStolen++;
	return;
}

template <class T>
void Robber<T>::decrementNumStolen() {
	r_NumStolen--;
	return;
}

template <class T>
void Robber<T>::deactivateRobber() {
	r_Active = false;
	return;
}

template <class T>
void Robber<T>::decreaseTotalVal(const int input) {
	rTotalValStolen -= input;
	return;
}

template <class T>
bool Robber<T>::isGreedy() const {
	return r_IsGreedy;
}

template <class T>
T Robber<T>::returnBag(const int index) {
	return r_Bag[index];
}

template <class T>
bool Robber<T>::getActive() const {
	return r_Active;
}

template <class T>
void Robber<T>::zeroStolen() {
	r_NumStolen = 0;
	return;
}