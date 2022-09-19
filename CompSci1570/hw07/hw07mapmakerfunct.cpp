#include <cstdlib>
#include <ctime>

#include "hw07mapmaker.h"

using namespace std;

void Mapmaker::initMap(const int ROW, const int COL) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			r_Map[i][j] = 'U';
		}
	}

	return;
}

void Mapmaker::checkMap(const int ROW, const int COL) {
	int numUnexplored = 0;
	const int MAPSPOTS = 40;
	bool moreUnexplored = false;

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (getMCoord(i, j) == 'U') {
				numUnexplored++;
				moreUnexplored = true;
				r_numExplored = MAPSPOTS - numUnexplored;
			}
		}
	}

	if (moreUnexplored == true) {
		cout << "\t\tNumber of uncharted locations remaining: " << numUnexplored << endl;
	}

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (getMCoord(i, j) == 'U') {
				return;
			}
		}
	}

	if (moreUnexplored == false) {
		r_mapExplored = true;
	}

	return;
}

void Mapmaker::exploreMap(Region region) {
	const int ROW = 10;
	const int COL = 4;
	const int MIN = 1;

	int randRow = rand() % ((ROW - MIN) + MIN);
	int randCol = rand() % ((COL - MIN) + MIN);
	bool cont = false;

	cout << "\t\tExploring location "
		 << "[" << randRow << "]"
		 << "[" << randCol << "]..." << endl;

	if (getMCoord(randRow, randCol) != 'U') {
		cout << "\t\tAchoo! This area is already explored!" << endl;
	}

	if (getMCoord(randRow, randCol) == 'U') {
		r_Map[randRow][randCol] = region.getCoord(randRow, randCol);
		r_numExplored++;
		cont = true;
	}
	if (region.getCoord(randRow, randCol) == 'A' && cont == true) {
		cout << "\t\tAnimals shed serious dander!" << endl;
	} else if (region.getCoord(randRow, randCol) == 'D' && cont == true) {
		cout << "\t\tDust will never leave!" << endl;
	} else if (region.getCoord(randRow, randCol) == 'P' && cont == true) {
		cout << "\t\tPollen travels a long trajectory!" << endl;
	}
	return;
}

void playRPS(Mapmaker& mapmaker1, Mapmaker& mapmaker2) {
	const int ROCK = 1;
	const int PAPER = 2;
	const int SCISSORS = 3;

	int mapmaker1Throw = (rand() % (SCISSORS - ROCK + ROCK)) + ROCK;
	int mapmaker2Throw = (rand() % (SCISSORS - ROCK + ROCK)) + ROCK;

	if (mapmaker1Throw == mapmaker2Throw) {
		cout << "\t\tRock Paper Scissors! The players tied, nobody won!" << endl;
	} else if ((mapmaker1Throw == ROCK && mapmaker2Throw == SCISSORS) || (mapmaker1Throw == PAPER && mapmaker2Throw == ROCK) ||
			   (mapmaker1Throw == SCISSORS && mapmaker2Throw == PAPER)) {
		cout << "\t\tRock Paper Scissors! " << mapmaker1.r_Name << " won!" << endl;
		mapmaker1.r_RPSWins++;
	} else if ((mapmaker2Throw == ROCK && mapmaker1Throw == SCISSORS) || (mapmaker2Throw == PAPER && mapmaker1Throw == ROCK) ||
			   (mapmaker2Throw == SCISSORS && mapmaker1Throw == PAPER)) {
		cout << "\t\tRock Paper Scissors! " << mapmaker2.r_Name << " won!" << endl;
		mapmaker2.r_RPSWins++;
	}
	return;
}