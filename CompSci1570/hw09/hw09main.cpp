// Programmer: Ethan Heckart
// File: hw09main.cpp
// Date: 4/29/22
// Purpose: main file for homework 9

/* ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* This is obviously a long & complicated assignment, so I tried to add as many comments as possible to make the grading process easier for you.          */
/* The main bodies of robbers one, two, three, and four are exactly identical (lines 56-429). I struggled to figure out how to do it another way. - Ethan */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include <iostream>

#include "hw09city.h"
#include "hw09header.h"
#include "hw09jewel.h"
#include "hw09police.h"
#include "hw09robber.h"

using namespace std;

int main() {
	srand(85);
	const int JEWEL_ARRAY_SIZE = 47;
	const int ROBBER_BAG_MAX = 18;	// actual max is 17, but their are said to hold '1' when the bag array is filled to index '0'
	const int ROBBER_WIN_VALUE = 438;
	const int MAX_ROUNDS = 29;
	City Rolla;
	Jewel jewels[JEWEL_ARRAY_SIZE];

	for (int i = 0; i < JEWEL_ARRAY_SIZE; i++) {  // populate Rolla with jewels
		jewels[i] = Jewel(Rolla);
	}
	Police officer(Rolla);
	Robber<Jewel> robberOne(Rolla, false);
	Robber<Jewel> robberTwo(Rolla, false);
	Robber<Jewel> robberThree(Rolla, true);
	Robber<Jewel> robberFour(Rolla, true);
	bool contPlaying = true;  // false if ending conditons for the game have been met
	bool moveAgain;			  // true if a greedy robber stole even valued loot and has moved < 3 times in his turn
	bool valid = true;		  // true if the original position of a gem is open
	int numRounds = 0;
	int count;	// number of times a greedy robber has moved in a turn
	int newX;	// new x value for a jewel if original spot is occupied
	int newY;	// new y value for a jewel if original spot is occupied
	int numRobbersCaught;

	cout << "The jewels, robbers, and cop are in place in the city.\n" << endl;
	printArray(Rolla, 10, 10);

	cout << "Let the chase begin!" << endl;

	while (contPlaying) {  // the main loop of the game
		numRounds++;
		cout << "~~~~~~~~~~~~ Round Number: " << numRounds << " ~~~~~~~~~~~~" << endl;

		// -----robber one logic-----
		if (robberOne.getActive()) {  // robber cannot be arrested
			if (Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == 'r') {
				Rolla.setCityMap(robberOne.getXCoord(), robberOne.getYCoord(), ' ');
			}
			if (Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == 'R') {
				Rolla.setCityMap(robberOne.getXCoord(), robberOne.getYCoord(), 'r');
			}

			moveAgain = true;
			robberOne.move(Rolla);
			if (Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == ' ') {  // if spot is empty
				Rolla.setCityMap(robberOne.getXCoord(), robberOne.getYCoord(), 'r');
			}
			if (Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == 'J') {  // if spot has a jewel
				if (robberOne.getNumStolen() < ROBBER_BAG_MAX) {
					Rolla.setCityMap(robberOne.getXCoord(), robberOne.getYCoord(), 'r');
					Rolla.decrementJewels();
					robberOne.incrementNumStolen();
					robberOne.pickUpLoot(jewels, JEWEL_ARRAY_SIZE);

					if (robberOne.getTotalVal() > ROBBER_WIN_VALUE) {
						contPlaying = false;
					}

					count = 1;
					if (robberOne.isGreedy()) {	 // if robber is greedy, keep moving
						while ((robberOne.getMostRecentStolenVal() % 2 == 0) && count < 4 && moveAgain) {
							if (Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == ' ') {  // if spot is empty
								Rolla.setCityMap(robberOne.getXCoord(), robberOne.getYCoord(), 'r');
								moveAgain = false;
							}
							if (Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == 'J') {  // if spot has a jewel
								Rolla.setCityMap(robberOne.getXCoord(), robberOne.getYCoord(), 'r');
								Rolla.decrementJewels();
								robberOne.incrementNumStolen();
								robberOne.pickUpLoot(jewels, JEWEL_ARRAY_SIZE);
								if (robberOne.getTotalVal() > ROBBER_WIN_VALUE) {
									contPlaying = false;
								}
								count++;
								if ((robberOne.getMostRecentStolenVal() % 2 != 0) ||
									count >= 4) {  // continue moving until value is odd, three moves have been made, or robber is arrested
									moveAgain = false;
								}
							}
						}
					}
				}
			}
			if (Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == 'r' ||
				Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == 'R') {  // if spot is occupied by a rober
				if (robberOne.isGreedy()) {												  // if the robber is greedy, he loses half his jewels
					int numToLose = robberOne.getNumStolen() / 2;
					for (int i = 0; i < numToLose; i++) {  // loop to deactivate the jewels in the robber's bag, remove their value, etc.
						robberOne.deactivateBag((robberOne.getNumStolen() - 1) - i);
						robberOne.returnBag(robberOne.getNumStolen() - i).deactivate();

						for (int i = 0; i < JEWEL_ARRAY_SIZE; i++) {
							if (jewels[i].getInPlay() == false && jewels[i].getXCoord() == robberOne.returnBag(i).getXCoord() &&
								jewels[i].getYCoord() == robberOne.returnBag(i).getXCoord()) {	// put jewel back on map
								jewels[i].activate();

								if (Rolla.getCityMap(jewels[i].getXCoord(), jewels[i].getYCoord() == ' ')) {  // jewel can occupy original spot
									Rolla.setCityMap(jewels[i].getXCoord(), jewels[i].getYCoord(), 'J');
									valid = true;
								} else {
									valid = false;
								}
								while (!valid) {  // find suitable new coordinates for the jewel
									newX = (rand() % (9 - 0 + 1)) + 0;
									newY = (rand() % (9 - 0 + 1)) + 0;
									if (Rolla.getCityMap(jewels[i].getXCoord(), jewels[i].getYCoord()) == ' ') {  // new spot is empty
										valid = true;
										jewels[i].setXCoord(newX);
										jewels[i].setYCoord(newY);
										Rolla.setCityMap(jewels[i].getXCoord(), jewels[i].getYCoord(), 'J');
									}
								}
							}
						}
					}
					for (int i = 0; i < numToLose; i++) {  // make the robber's num stolen value correct again
						robberOne.decrementNumStolen();
					}
					for (int i = 0; i < numToLose; i++) {  // add jewels back to the city count
						Rolla.addNumJewels();
					}
				}
			}

			if (Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == 'p') {  // if spot is occupied by police
				officer.arrest(robberOne, Rolla);
			}
		}

		// -----robber two logic-----
		if (robberTwo.getActive()) {  // robber cannot be arrested
			if (Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == 'r') {
				Rolla.setCityMap(robberTwo.getXCoord(), robberTwo.getYCoord(), ' ');
			}
			if (Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == 'R') {
				Rolla.setCityMap(robberTwo.getXCoord(), robberTwo.getYCoord(), 'r');
			}
			moveAgain = true;
			robberTwo.move(Rolla);
			if (Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == ' ') {  // if spot is empty
				Rolla.setCityMap(robberTwo.getXCoord(), robberTwo.getYCoord(), 'r');
			}
			if (Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == 'J') {  // if spot has a jewel
				if (robberTwo.getNumStolen() < ROBBER_BAG_MAX) {
					Rolla.setCityMap(robberTwo.getXCoord(), robberTwo.getYCoord(), 'r');
					Rolla.decrementJewels();
					robberTwo.incrementNumStolen();
					robberTwo.pickUpLoot(jewels, JEWEL_ARRAY_SIZE);
					if (robberTwo.getTotalVal() > ROBBER_WIN_VALUE) {
						contPlaying = false;
					}
					count = 1;
					if (robberTwo.isGreedy()) {	 // if robber is greedy, keep moving
						while ((robberTwo.getMostRecentStolenVal() % 2 == 0) && count < 4 && moveAgain) {
							if (Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == ' ') {  // if spot is empty
								Rolla.setCityMap(robberTwo.getXCoord(), robberTwo.getYCoord(), 'r');
								moveAgain = false;
							}
							if (Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == 'J') {  // if spot has a jewel
								Rolla.setCityMap(robberTwo.getXCoord(), robberTwo.getYCoord(), 'r');
								Rolla.decrementJewels();
								robberTwo.incrementNumStolen();
								robberTwo.pickUpLoot(jewels, JEWEL_ARRAY_SIZE);
								if (robberTwo.getTotalVal() > ROBBER_WIN_VALUE) {
									contPlaying = false;
								}
								count++;
								if ((robberTwo.getMostRecentStolenVal() % 2 != 0) ||
									count >= 4) {  // continue moving until value is odd, three moves have been made, or robber is arrested
									moveAgain = false;
								}
							}
						}
					}
				}
			}
			if (Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == 'r' ||
				Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == 'R') {  // if spot is occupied by a rober
				if (robberTwo.isGreedy()) {												  // if the robber is greedy, he loses half his jewels
					int numToLose = robberTwo.getNumStolen() / 2;
					for (int i = 0; i < numToLose; i++) {  // loop to deactivate the jewels in the robber's bag, remove their value, etc.
						robberTwo.deactivateBag((robberTwo.getNumStolen() - 1) - i);
						robberTwo.returnBag(robberTwo.getNumStolen() - i).deactivate();

						for (int i = 0; i < JEWEL_ARRAY_SIZE; i++) {
							if (jewels[i].getInPlay() == false && jewels[i].getXCoord() == robberTwo.returnBag(i).getXCoord() &&
								jewels[i].getYCoord() == robberTwo.returnBag(i).getXCoord()) {	// put jewel back on map
								jewels[i].activate();
								if (Rolla.getCityMap(jewels[i].getXCoord(), jewels[i].getYCoord() == ' ')) {  // jewel can occupy original spot
									Rolla.setCityMap(jewels[i].getXCoord(), jewels[i].getYCoord(), 'J');
									valid = true;
								} else {
									valid = false;
								}
								while (!valid) {  // find suitable new coordinates for the jewel
									newX = (rand() % (9 - 0 + 1)) + 0;
									newY = (rand() % (9 - 0 + 1)) + 0;
									if (Rolla.getCityMap(jewels[i].getXCoord(), jewels[i].getYCoord()) == ' ') {  // new spot is empty
										valid = true;
										jewels[i].setXCoord(newX);
										jewels[i].setYCoord(newY);
										Rolla.setCityMap(jewels[i].getXCoord(), jewels[i].getYCoord(), 'J');
									}
								}
							}
						}
					}
					for (int i = 0; i < numToLose; i++) {  // make the robber's num stolen value correct again
						robberTwo.decrementNumStolen();
					}
					for (int i = 0; i < numToLose; i++) {  // add jewels back to the city count
						Rolla.addNumJewels();
					}
				}
			}

			if (Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == 'p') {  // if spot is occupied by police
				officer.arrest(robberTwo, Rolla);
			}
		}

		// -----robber three logic-----
		if (robberThree.getActive()) {	// robber cannot be arrested
			if (Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == 'r') {
				Rolla.setCityMap(robberThree.getXCoord(), robberThree.getYCoord(), ' ');
			}
			if (Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == 'R') {
				Rolla.setCityMap(robberThree.getXCoord(), robberThree.getYCoord(), 'r');
			}
			moveAgain = true;
			robberThree.move(Rolla);
			if (Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == ' ') {  // if spot is empty
				Rolla.setCityMap(robberThree.getXCoord(), robberThree.getYCoord(), 'r');
			}
			if (Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == 'J') {  // if spot has a jewel
				if (robberThree.getNumStolen() < ROBBER_BAG_MAX) {
					Rolla.setCityMap(robberThree.getXCoord(), robberThree.getYCoord(), 'r');
					Rolla.decrementJewels();
					robberThree.incrementNumStolen();
					robberThree.pickUpLoot(jewels, JEWEL_ARRAY_SIZE);
					if (robberThree.getTotalVal() > ROBBER_WIN_VALUE) {
						contPlaying = false;
					}
					count = 1;
					if (robberThree.isGreedy()) {  // if robber is greedy, keep moving
						while ((robberThree.getMostRecentStolenVal() % 2 == 0) && count < 4 && moveAgain) {
							robberThree.move(Rolla);
							if (Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == ' ') {  // if spot is empty
								Rolla.setCityMap(robberThree.getXCoord(), robberThree.getYCoord(), 'r');
								moveAgain = false;
								count++;
							}
							if (Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == 'J') {  // if spot has a jewel
								Rolla.setCityMap(robberThree.getXCoord(), robberThree.getYCoord(), 'r');
								Rolla.decrementJewels();
								robberThree.incrementNumStolen();
								robberThree.pickUpLoot(jewels, JEWEL_ARRAY_SIZE);
								if (robberThree.getTotalVal() > ROBBER_WIN_VALUE) {
									contPlaying = false;
								}
								count++;
								if ((robberThree.getMostRecentStolenVal() % 2 != 0) ||
									count >= 4) {  // continue moving until value is odd, three moves have been made, or robber is arrested
									moveAgain = false;
								}
							}
						}
					}
				}
			}
			if (Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == 'r' ||
				Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == 'R') {  // if spot is occupied by a rober
				if (robberThree.isGreedy()) {												  // if the robber is greedy, he loses half his jewels
					int numToLose = robberThree.getNumStolen() / 2;
					for (int i = 0; i < numToLose; i++) {  // loop to deactivate the jewels in the robber's bag, remove their value, etc.
						robberThree.deactivateBag((robberThree.getNumStolen() - 1) - i);
						robberThree.returnBag(robberThree.getNumStolen() - i).deactivate();

						for (int i = 0; i < JEWEL_ARRAY_SIZE; i++) {
							if (jewels[i].getInPlay() == false && jewels[i].getXCoord() == robberThree.returnBag(i).getXCoord() &&
								jewels[i].getYCoord() == robberThree.returnBag(i).getXCoord()) {  // put jewel back on map
								jewels[i].activate();
								if (Rolla.getCityMap(jewels[i].getXCoord(), jewels[i].getYCoord() == ' ')) {  // jewel can occupy original spot
									Rolla.setCityMap(jewels[i].getXCoord(), jewels[i].getYCoord(), 'J');
									valid = true;
								} else {
									valid = false;
								}
								while (!valid) {  // find suitable new coordinates for the jewel
									newX = (rand() % (9 - 0 + 1)) + 0;
									newY = (rand() % (9 - 0 + 1)) + 0;
									if (Rolla.getCityMap(jewels[i].getXCoord(), jewels[i].getYCoord()) == ' ') {  // new spot is empty
										valid = true;
										jewels[i].setXCoord(newX);
										jewels[i].setYCoord(newY);
										Rolla.setCityMap(jewels[i].getXCoord(), jewels[i].getYCoord(), 'J');
									}
								}
							}
						}
					}
					for (int i = 0; i < numToLose; i++) {  // make the robber's num stolen value correct again
						robberThree.decrementNumStolen();
					}
					for (int i = 0; i < numToLose; i++) {  // add jewels back to the city count
						Rolla.addNumJewels();
					}
				}
			}

			if (Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == 'p') {  // if spot is occupied by police
				officer.arrest(robberThree, Rolla);
			}
		}

		// -----robber four logic-----
		if (robberFour.getActive()) {
			if (Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == 'r') {
				Rolla.setCityMap(robberFour.getXCoord(), robberFour.getYCoord(), ' ');
			}
			if (Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == 'R') {
				Rolla.setCityMap(robberFour.getXCoord(), robberFour.getYCoord(), 'r');
			}
			moveAgain = true;
			robberFour.move(Rolla);
			if (Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == ' ') {	// if spot is empty
				Rolla.setCityMap(robberFour.getXCoord(), robberFour.getYCoord(), 'r');
			}
			if (Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == 'J') {	// if spot has a jewel
				if (robberFour.getNumStolen() < ROBBER_BAG_MAX) {
					Rolla.setCityMap(robberFour.getXCoord(), robberFour.getYCoord(), 'r');
					Rolla.decrementJewels();
					robberFour.incrementNumStolen();
					robberFour.pickUpLoot(jewels, JEWEL_ARRAY_SIZE);
					if (robberFour.getTotalVal() > ROBBER_WIN_VALUE) {
						contPlaying = false;
					}
					count = 1;
					if (robberFour.isGreedy()) {  // if robber is greedy, keep moving
						while ((robberFour.getMostRecentStolenVal() % 2 == 0) && count < 4 && moveAgain) {
							robberFour.move(Rolla);
							if (Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == ' ') {	// if spot is empty
								Rolla.setCityMap(robberFour.getXCoord(), robberFour.getYCoord(), 'r');
								moveAgain = false;
							}
							if (Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == 'J') {	// if spot has a jewel
								Rolla.setCityMap(robberFour.getXCoord(), robberFour.getYCoord(), 'r');
								Rolla.decrementJewels();
								robberFour.incrementNumStolen();
								robberFour.pickUpLoot(jewels, JEWEL_ARRAY_SIZE);
								if (robberFour.getTotalVal() > ROBBER_WIN_VALUE) {
									contPlaying = false;
								}
								count++;
								if ((robberFour.getMostRecentStolenVal() % 2 != 0) ||
									count >= 4) {  // continue moving until value is odd, three moves have been made, or robber is arrested
									moveAgain = false;
								}
							}
						}
					}
				}
			}
			if (Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == 'r' ||
				Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == 'R') {	// if spot is occupied by a rober
				if (robberFour.isGreedy()) {												// if the robber is greedy, he loses half his jewels
					int numToLose = robberFour.getNumStolen() / 2;
					for (int i = 0; i < numToLose; i++) {  // loop to deactivate the jewels in the robber's bag, remove their value, etc.
						robberFour.deactivateBag((robberFour.getNumStolen() - 1) - i);
						robberFour.returnBag(robberFour.getNumStolen() - i).deactivate();

						for (int i = 0; i < JEWEL_ARRAY_SIZE; i++) {
							if (jewels[i].getInPlay() == false && jewels[i].getXCoord() == robberFour.returnBag(i).getXCoord() &&
								jewels[i].getYCoord() == robberFour.returnBag(i).getXCoord()) {	 // put jewel back on map
								jewels[i].activate();
								if (Rolla.getCityMap(jewels[i].getXCoord(), jewels[i].getYCoord() == ' ')) {  // jewel can occupy original spot
									Rolla.setCityMap(jewels[i].getXCoord(), jewels[i].getYCoord(), 'J');
									valid = true;
								} else {
									valid = false;
								}
								while (!valid) {  // find suitable new coordinates for the jewel
									newX = (rand() % (9 - 0 + 1)) + 0;
									newY = (rand() % (9 - 0 + 1)) + 0;
									if (Rolla.getCityMap(jewels[i].getXCoord(), jewels[i].getYCoord()) == ' ') {  // new spot is empty
										valid = true;
										jewels[i].setXCoord(newX);
										jewels[i].setYCoord(newY);
										Rolla.setCityMap(jewels[i].getXCoord(), jewels[i].getYCoord(), 'J');
									}
								}
							}
						}
					}
					for (int i = 0; i < numToLose; i++) {  // make the robber's num stolen value correct again
						robberFour.decrementNumStolen();
					}
					for (int i = 0; i < numToLose; i++) {  // add jewels back to the city count
						Rolla.addNumJewels();
					}
				}
			}

			if (Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == 'p') {	// if spot is occupied by police
				officer.arrest(robberFour, Rolla);
			}
		}

		// -----police logic-----
		officer.move(Rolla);
		if (Rolla.getCityMap(officer.getXCoord(), officer.getYCoord()) == ' ') {  // if spot is empty
			Rolla.setCityMap(officer.getXCoord(), officer.getYCoord(), 'p');
		}
		if (Rolla.getCityMap(officer.getXCoord(), officer.getYCoord()) == 'r' ||
			Rolla.getCityMap(officer.getXCoord(), officer.getYCoord()) == 'R') {  // if spot is occupied by robber, arrest them
			if ((robberOne.getXCoord() == officer.getXCoord()) && (robberOne.getYCoord() == officer.getYCoord())) {
				officer.arrest(robberOne, Rolla);
			}
			if ((robberTwo.getXCoord() == officer.getXCoord()) && (robberTwo.getYCoord() == officer.getYCoord())) {
				officer.arrest(robberTwo, Rolla);
			}
			if ((robberThree.getXCoord() == officer.getXCoord()) && (robberThree.getYCoord() == officer.getYCoord())) {
				officer.arrest(robberThree, Rolla);
			}
			if ((robberFour.getXCoord() == officer.getXCoord()) && (robberFour.getYCoord() == officer.getYCoord())) {
				officer.arrest(robberFour, Rolla);
			}
		}
		if (Rolla.getCityMap(officer.getXCoord(), officer.getYCoord()) == 'J') {
			Rolla.setCityMap(officer.getXCoord(), officer.getYCoord(), 'p');
			Rolla.decrementJewels();
			for (int i = 0; i < JEWEL_ARRAY_SIZE; i++) {  // put jewel in bag and update loot totals
				if (jewels[i].getInPlay() && jewels[i].getXCoord() == officer.getXCoord() && jewels[i].getYCoord() == officer.getYCoord()) {
					jewels[i].deactivate();
					officer.addLootVal(officer.getXCoord() + officer.getYCoord());
				}
			}
		}

		// ensure that the city map is correct in case of edge cases (i.e. a robber with a full bag lands on a jewel)
		for (int i = 0; i < JEWEL_ARRAY_SIZE; i++) {
			if (jewels[i].getInPlay()) {
				Rolla.setCityMap(jewels[i].getXCoord(), jewels[i].getYCoord(), 'J');
			}
		}
		if (robberOne.getActive()) {
			if (Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == ' ' || Rolla.getCityMap(robberOne.getXCoord(), robberOne.getYCoord()) == 'J') {
				Rolla.setCityMap(robberOne.getXCoord(), robberOne.getYCoord(), 'r');
			}
		}
		if (robberTwo.getActive()) {
			if (Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == ' ' || Rolla.getCityMap(robberTwo.getXCoord(), robberTwo.getYCoord()) == 'J') {
				Rolla.setCityMap(robberTwo.getXCoord(), robberTwo.getYCoord(), 'r');
			}
		}
		if (robberThree.getActive()) {
			if (Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == ' ' ||
				Rolla.getCityMap(robberThree.getXCoord(), robberThree.getYCoord()) == 'J') {
				Rolla.setCityMap(robberThree.getXCoord(), robberThree.getYCoord(), 'r');
			}
		}
		if (robberFour.getActive()) {
			if (Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == ' ' ||
				Rolla.getCityMap(robberFour.getXCoord(), robberFour.getYCoord()) == 'J') {
				Rolla.setCityMap(robberFour.getXCoord(), robberFour.getYCoord(), 'r');
			}
		}
		Rolla.setCityMap(officer.getXCoord(), officer.getYCoord(), 'p');

		// game ending conditions
		if (numRounds > MAX_ROUNDS || robberOne.getTotalVal() >= ROBBER_WIN_VALUE) {
			contPlaying = false;
		}
		numRobbersCaught = 0;
		if (robberOne.getActive() == false) {
			numRobbersCaught++;
		}
		if (robberTwo.getActive() == false) {
			numRobbersCaught++;
		}
		if (robberThree.getActive() == false) {
			numRobbersCaught++;
		}
		if (robberFour.getActive() == false) {
			numRobbersCaught++;
		}
		if (numRobbersCaught == 4) {
			contPlaying = false;
		}

		printArray(Rolla, 10, 10);
		cout << endl;
	}

	// game summary
	cout << "Summary of the chase:\n";
	if (numRounds > MAX_ROUNDS) {
		cout << "\tThe robbers win the chase because maximum turns (30) have been reached.\n";
	} else if (robberOne.getTotalVal() >= ROBBER_WIN_VALUE) {
		cout << "\tThe robbers win the chase because they stole more than $437 and bribed the cop.\n";
	} else {
		cout << "\tThe police officer won the chase because he captured all four robbers.\n";
	}

	cout << "\tPolice id: " << officer.getID() << endl;
	cout << "\t\tConfiscated jewels amount: $" << officer.getLootVal() << endl;
	cout << "\t\tFinal number of robbers caught: " << officer.getRobbersCaught() << endl;

	cout << "\tOrdinary Robber id: " << robberOne.getID() << endl;
	cout << "\t\tFinal number of jewels picked up: " << robberOne.getNumStolen() << endl;
	cout << "\t\tTotal jewel worth: $" << robberOne.getVal() << endl;

	cout << "\tOrdinary Robber id: " << robberTwo.getID() << endl;
	cout << "\t\tFinal number of jewels picked up: " << robberTwo.getNumStolen() << endl;
	cout << "\t\tTotal jewel worth: $" << robberTwo.getVal() << endl;

	cout << "\tGreedy Robber id: " << robberThree.getID() << endl;
	cout << "\t\tFinal number of jewels picked up: " << robberThree.getNumStolen() << endl;
	cout << "\t\tTotal jewel worth: $" << robberThree.getVal() << endl;

	cout << "\tGreedy Robber id: " << robberFour.getID() << endl;
	cout << "\t\tFinal number of jewels picked up: " << robberFour.getNumStolen() << endl;
	cout << "\t\tTotal jewel worth: $" << robberFour.getVal() << endl;

	return 0;
}