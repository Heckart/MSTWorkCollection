// Programmer: Ethan Heckart
// Date: 2/28/22
// File: lab5main.cpp
// Purpose: Give normo a trial by roshambo

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "lab5Functions.h"

using namespace std;

int main() {
	string normoInput;
	int numNormoWins = 0;
	int numJudgeWins = 0;
	short numRounds = 0;

	srand(11);

	cout << "It all comes down to this, Normo." << endl;

	do {
		numRounds++;
		if (numRounds % 2 == 0) {
			cout << "" << endl;
			cout << "What do you choose?" << endl;
			cin >> normoInput;
			cout << "" << endl;
			playRPS(normoInput, numNormoWins, numJudgeWins);
		} else {
			cout << "" << endl;
			cout << "What do you choose?" << endl;
			cin >> normoInput;
			cout << "" << endl;
			playRPS(normoInput, numNormoWins, numJudgeWins, rand() % (3 - 1 + 1) + 1);
		}
	} while (numNormoWins < 2 && numJudgeWins < 2);

	if (numNormoWins == 2) {
		cout << "" << endl;
		cout << "The verdict came up as innocent. You are scot free, Normo." << endl;
	} else {
		cout << "" << endl;
		cout << "The verdict came up as guilty. You have been imprisoned forever." << endl;
	}
	return 0;
}