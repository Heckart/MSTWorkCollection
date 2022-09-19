#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hw05Header.h"

using namespace std;

void initializeNeighbor(neighbor& newNeighbor) {
	static int id = -1;
	const int FRIENDLYNUM = 5;
	id++;

	int randNum = (rand() % (10 - 1 + 1)) + 1;	// used to determine if neighbor is good or bad
	newNeighbor.m_neighborID = id;
	newNeighbor.m_startLand = (rand() % (50 - 19 + 1)) + 19;
	newNeighbor.m_currentLand = newNeighbor.m_startLand;
	newNeighbor.m_numGarages = (newNeighbor.m_startLand / 10);
	if (randNum > FRIENDLYNUM) {
		newNeighbor.m_friendly = true;
	} else {
		newNeighbor.m_friendly = false;
	}

	return;
}

void requestAssistance(newHomeowner& theNewHomeowner, neighbor& aGoodNeighbor) {
	int randNum = (rand() % (100 - 1 + 1)) + 1;
	const float MINLAND = 0.0;
	const int MINGARAGES = 0;
	const int ONEGARAGE = 1;
	const int DONATEGARAGENUM = 81;
	const int DONATEGARAGENUMTWO = 31;

	if (theNewHomeowner.m_currentLand > MINLAND) {
		cout << "" << endl;
		cout << "You found Neighbor #" << aGoodNeighbor.m_neighborID << ". He is a good neighbor!" << endl;
		cout << "You have " << aGoodNeighbor.m_numGarages << " garages and the neighbor has " << aGoodNeighbor.m_numGarages << " garages." << endl;

		if (theNewHomeowner.m_numGarages < aGoodNeighbor.m_numGarages &&
			aGoodNeighbor.m_numGarages > MINGARAGES) {	// garage probability if neighbor has more garages
			if (randNum < DONATEGARAGENUM) {
				theNewHomeowner.m_numGarages++;
				cout << "The good neighbor donated you a garage!" << endl;
				cout << "You now have " << theNewHomeowner.m_numGarages << " garage(s)." << endl;
			} else {
				cout << "Your \"good\" neighbor decided he didn't want to donate a garage." << endl;
			}
		} else if (theNewHomeowner.m_numGarages >= aGoodNeighbor.m_numGarages &&
				   aGoodNeighbor.m_numGarages > MINGARAGES) {  // garage probability if neighbor has less than or the same garages
			if (randNum < DONATEGARAGENUMTWO) {
				theNewHomeowner.m_numGarages++;
				cout << "The good neighbor donated you a garage!" << endl;
				cout << "You now have " << theNewHomeowner.m_numGarages << " garage(s)." << endl;
			} else {
				cout << "Your \"good\" neighbor decided he didn't want to donate a garage." << endl;
			}
		} else if (aGoodNeighbor.m_numGarages < ONEGARAGE) {  // if neighbor has no garages to give
			cout << "Unfortunately your good neighbor does not have a garage to give." << endl;
		}

		return;
	}
}

void defendHomeland(newHomeowner& theNewHomeowner, neighbor& aBadNeighbor) {
	int randNum = (rand() % (100 - 1 + 1)) + 1;
	const float MINLAND = 0.0;
	const int RANDNUM27 = 27;
	const int RANDNUM28 = 28;
	const int RANDNUM47 = 47;
	const int RANDNUM73 = 73;

	if (aBadNeighbor.m_active == true && theNewHomeowner.m_currentLand > MINLAND) {
		cout << "" << endl;
		cout << "You encountered Neighbor #" << aBadNeighbor.m_neighborID << ". He is a bad neighbor!" << endl;
		if (theNewHomeowner.m_numGarages < aBadNeighbor.m_numGarages) {
			if (randNum < 54) {	 // land gets stolen
				int garageDiff = aBadNeighbor.m_numGarages - theNewHomeowner.m_numGarages;
				if (garageDiff > theNewHomeowner.m_currentLand) {  // ensure stolen land is not greater than current land
					garageDiff = theNewHomeowner.m_currentLand;
				}

				aBadNeighbor.m_currentLand = static_cast<float>(garageDiff) + static_cast<float>(aBadNeighbor.m_currentLand);
				theNewHomeowner.m_currentLand = static_cast<float>(theNewHomeowner.m_currentLand) - static_cast<float>(garageDiff);
				if (theNewHomeowner.m_currentLand < MINLAND) {
					theNewHomeowner.m_currentLand = MINLAND;
				}

				cout << "You lost " << garageDiff << " acre(s) of land." << endl;
				cout << "You now have " << theNewHomeowner.m_currentLand << " acre(s) of land." << endl;
				cout << "The bad neighbor now has " << aBadNeighbor.m_currentLand << " acre(s) of land." << endl;

				int randNum2 = (rand() % (100 - 1 + 1)) + 1;

				if (randNum2 < RANDNUM47) {	 // neighbor builds new garage
					aBadNeighbor.m_numGarages++;
					cout << "More bad news: the bad neighbor constructed a new garage. He now has " << aBadNeighbor.m_numGarages << " garage(s)." << endl;
				}
			}
		} else {  // land is defended
			cout << "You successfully defeneded your home." << endl;
			int roll = (rand() % (80 - 1 + 1)) + 1;
			if ((roll % 2 == 0) && (aBadNeighbor.m_currentLand > aBadNeighbor.m_startLand)) {
				int randNum2 = (rand() % (100 - 1 + 1)) + 1;

				if (randNum2 < RANDNUM73 && randNum2 > RANDNUM27)  // half of stolen land is returned
				{
					float acresStolenLand = aBadNeighbor.m_currentLand - aBadNeighbor.m_startLand;
					theNewHomeowner.m_currentLand += acresStolenLand / 2;
					aBadNeighbor.m_currentLand -= acresStolenLand / 2;
					cout << "You also took back half of the land stolen by this bad neighbor." << endl;
					cout << "You now control " << theNewHomeowner.m_currentLand << " acre(s) of land." << endl;
					cout << "This bad neighbor controls " << aBadNeighbor.m_currentLand << " acre(s) of land stolen from you." << endl;
				} else if (randNum2 < RANDNUM28) {	// all stolen land is returned and it is no longer active
					float acresStolenLand = aBadNeighbor.m_currentLand - aBadNeighbor.m_startLand;
					theNewHomeowner.m_currentLand += acresStolenLand;
					aBadNeighbor.m_currentLand -= acresStolenLand;
					aBadNeighbor.m_active = false;
					cout << "You also took back all of the land stolen by this bad neighbor and defeated the bad neighbor." << endl;
					cout << "You now control " << theNewHomeowner.m_currentLand << " acre(s) of land." << endl;
					cout << "This bad neighbor controls " << (aBadNeighbor.m_currentLand - aBadNeighbor.m_startLand) << " acre(s) of land stolen from you."
						 << endl;
				}
			}
			return;
		}
	}
}