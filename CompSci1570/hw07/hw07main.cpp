// Programmer: Ethan Heckart
// File: hw07main.cpp
// Date: 4/16/22
// Purpose: main file for homework 7

#include <iostream>

#include "hw07header.h"
#include "hw07mapmaker.h"
#include "hw07region.h"

using namespace std;

int main() {
	Region gameRegion = Region("Hip Hop Garden");
	int numRounds = 1;
	const int ROW = 10;
	const int COL = 4;
	const int MAXROUNDS = 151;
	bool contPlaying = true;

	srand(278);

	cout << "Achoo! Allergy season has arrived in the Kingdom of EET." << endl;
	cout << endl;
	cout << "King Rajmund has tasked the mapmakers to explore and learn about the allergens in the region of " << gameRegion.getName() << "." << endl;

	Mapmaker playerOne;
	Mapmaker playerTwo = Mapmaker("Pamelia Angelina");

	cout << "Welcome! Mapmaker " << playerOne.getName() << "." << endl;
	cout << "Lets also welcome your competitors: " << playerTwo.getName() << "." << endl;
	cout << endl;

	do {
		cout << "ROUND " << numRounds << ":" << endl;
		// Player one portion: explore map, check remaining unexplored places, play rock paper scissors
		cout << "\t" << playerOne.getName() << ":" << endl;
		playerOne.exploreMap(gameRegion);
		playerOne.checkMap(ROW, COL);
		playRPS(playerOne, playerTwo);
		// Player two portion: explore map, check remaining unexplored places, play rock paper scissors
		cout << "\t" << playerTwo.getName() << ":" << endl;
		playerTwo.exploreMap(gameRegion);
		playerTwo.checkMap(ROW, COL);
		playRPS(playerTwo, playerOne);
		if (playerOne.getMapExplored() == true || playerTwo.getMapExplored() == true) {	 // ending condition for the game
			contPlaying = false;
		}
		numRounds++;

	} while (numRounds < MAXROUNDS && contPlaying);

	cout << endl;
	gameSummary(playerOne, playerTwo);

	return 0;
}