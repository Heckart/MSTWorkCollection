// Programmer: Ethan Heckart
// Date: 3/15/22
// File: hw05main.cpp
// Purpose: help homeowner defend is land against bad neighbors

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hw05Header.h"

using namespace std;

int main() {
	neighbor arrayOfNeighbors[6];
	int numFriendlyNeighbors = 0;
	int numInactiveNeighbors = 0;
	int numRounds = 1;
	int homeownerGaragesBeforeRound = 0;
	int homeownerLandBeforeRound = 0;
	const int ARRAYSIZE = 6;
	const int MINLANDGARAGENUM = 1;
	const int MAXFRIENDLYNEIGHBORS = 6;
	const int MAXNUMROUNDS = 10;
	newHomeowner homeowner;
	bool playGame = true;				// used to continue the game loop
	bool allFriendlyNeighbors = false;	// if all neighbors are friendly, dont play game

	srand(327);

	cout << "Hello, new homeowner!" << endl;
	cout << "What is your name?" << endl;
	cin >> homeowner.m_name;
	cout << "Thanks. What is the address of your home?" << endl;
	cin.ignore();
	getline(cin, homeowner.m_address);
	cout << "Nice real estate. How many acres of land do you own?" << endl;
	cin >> homeowner.m_startLand;
	while (homeowner.m_startLand < MINLANDGARAGENUM) {	// input validation
		cout << "You must input a number greater than 0" << endl;
		cin >> homeowner.m_startLand;
	}
	homeowner.m_currentLand = homeowner.m_startLand;
	cout << "Okay one final question before the battle beings. How many garages are currently under your control?" << endl;
	cin >> homeowner.m_numGarages;
	while (homeowner.m_numGarages < MINLANDGARAGENUM) {	 // input validation
		cout << "You must input an integer greater than 0" << endl;
		cin >> homeowner.m_numGarages;
	}

	for (size_t i = 0; i < ARRAYSIZE; i++) {  // initialize neighbors
		initializeNeighbor(arrayOfNeighbors[i]);
	}

	for (size_t i = 0; i < ARRAYSIZE; i++)	// determine how many neighbors are friendly
	{
		if (arrayOfNeighbors[i].m_friendly == true) {
			numFriendlyNeighbors++;
		}
	}

	if (numFriendlyNeighbors == MAXFRIENDLYNEIGHBORS) {	 // do not proceed with game if all neighbors are friendly
		cout << "All neighbors are friendly! You don't need to defend your home." << endl;
		playGame = false;
		allFriendlyNeighbors = true;
	}

	cout << endl;
	cout << "You have " << numFriendlyNeighbors << " friendly neighbor(s) and " << ARRAYSIZE - numFriendlyNeighbors << " bad neighbor(s)." << endl;

	if (playGame == true) {
		cout << "It is time to defend your home" << endl;
	}

	while (playGame == true) {	// the main loop of the game
		homeownerLandBeforeRound = homeowner.m_currentLand;
		homeownerGaragesBeforeRound = homeowner.m_numGarages;
		cout << "" << endl;
		cout << "Round #" << numRounds << endl;
		for (size_t i = 0; i < ARRAYSIZE; i++) {  // iterate through neighbors

			if (arrayOfNeighbors[i].m_friendly == true) {
				requestAssistance(homeowner, arrayOfNeighbors[i]);
			} else if (arrayOfNeighbors[i].m_friendly == false) {
				defendHomeland(homeowner, arrayOfNeighbors[i]);
			}
		}

		cout << endl;
		cout << "ROUND SUMMARY:" << endl;
		cout << "	Current acres of land: " << homeowner.m_currentLand << "	Change: " << homeowner.m_currentLand - homeownerLandBeforeRound << endl;
		cout << "	Current number of garages: " << homeowner.m_numGarages << " 	Change: " << homeowner.m_numGarages - homeownerGaragesBeforeRound << endl;

		numRounds++;

		for (size_t i = 0; i < ARRAYSIZE; i++) {  // calculate inactive neighbors
			if (arrayOfNeighbors[i].m_active == false) {
				numInactiveNeighbors++;
			}
		}

		if (numRounds > MAXNUMROUNDS) {	 // game ending criteria
			playGame = false;
		} else if (numInactiveNeighbors == (ARRAYSIZE - numFriendlyNeighbors)) {
			playGame = false;
		} else if (homeowner.m_currentLand < 1) {
			playGame = false;
		}
	}

	cout << "" << endl;
	cout << "********** GAME SUMMARY **********" << endl;
	if (allFriendlyNeighbors == true) {
		cout << "You did not need to defend your home because all neighbors were friendly.";
		cout << "You finished with " << homeowner.m_startLand << " acre(s) of land at " << homeowner.m_address << "." << endl;
	} else if (homeowner.m_currentLand < 1) {
		cout << homeowner.m_name << ", unfortunately you lost all of you land to the bad neighbors. You'll need to get a new home elsewhere." << endl;
	} else if (numInactiveNeighbors == (ARRAYSIZE - numFriendlyNeighbors)) {
		cout << "Congratulations, " << homeowner.m_name << ". You defeated all of your bad neighbrs." << endl;
		cout << "You finished with " << homeowner.m_startLand << " acre(s) of land at " << homeowner.m_address << "." << endl;
	} else {
		cout << "The game ended after 10 rounds." << endl;
		cout << "You finished with " << homeowner.m_startLand << " acre(s) of land at " << homeowner.m_address << "." << endl;
	}

	cout << endl;
	cout << "********** NEIGHBOR SUMMARY **********" << endl;
	for (size_t i = 0; i < ARRAYSIZE; i++) {
		cout << "Neighbor ID #: " << arrayOfNeighbors[i].m_neighborID << endl;
		cout << "Acres of Land Owned: " << arrayOfNeighbors[i].m_currentLand << endl;
		cout << "Acres of Land Stolen: " << arrayOfNeighbors[i].m_currentLand - arrayOfNeighbors[i].m_startLand << endl;
		cout << "Number of Garages Owned: " << arrayOfNeighbors[i].m_numGarages << endl;
		if (arrayOfNeighbors[i].m_friendly == true) {
			cout << "Likeable?  GOOD!" << endl;
		} else {
			cout << "Likeable?  BAD!" << endl;
		}
		if (arrayOfNeighbors[i].m_active == true) {
			cout << "Status:  Active" << endl;
		} else {
			cout << "Status:  Inactive" << endl;
		}
		cout << endl;
	}

	return 0;
}