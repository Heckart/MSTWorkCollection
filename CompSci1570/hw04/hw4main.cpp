// Programmer: Ethan Heckart
// Date: 3/4/22
// File: hw4main.cpp
// Purpose: Program the game "Are you smarter than a comp sci?"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hw4functions.h"

using namespace std;

int main() {
	bool left = false;
	bool contPlaying = true;
	int questionNum = 0;
	int playerAnswer = 0;
	int playerLives = 3;
	int playerMoney = 100;
	const int MIN_LIVES = 1;
	const int MAX__Q_NUM = 4;
	const int MIN_Q_NUM = 1;
	string playerInput = "NULL";

	srand(11);

	greeting();

	do {
		questionNum++;
		playerAnswer = 0;
		print_question(questionNum);
		cin >> playerInput;
		while ((!answerValidation(playerInput) && playerInput != "random" && playerInput != "lifeline" && playerInput != "leave") ||
			   (answerValidation(playerInput) && (stoi(playerInput) < MIN_Q_NUM || stoi(playerInput) > MAX__Q_NUM))) {	// validate input
			cout << "Your input must be an integer in [1,4], or must be \"random\", \"lifeline\", or \"leave\"" << endl;
			cin >> playerInput;
		}

		if (playerInput == "random") {
			if (playerInput == "random") {
				answerRandomly();
				questionNum--;
			}
		} else if (playerInput == "lifeline") {
			lifeLine(questionNum);
			questionNum--;
		} else if (playerInput == "leave") {
			left = leave();
		} else {
			playerAnswer = stoi(playerInput);
			if (!isCorrect(questionNum, playerAnswer) && left == false) {  // If answer is wrong update money and lives and tell the user
				playerLives--;
				playerMoney = updateMoney(playerMoney, false);
				cout << "Incorrect!" << endl;
				if (playerLives != MIN_LIVES) {
					cout << "You have " << playerLives << " lives remaining" << endl;
					cout << "" << endl;

				} else {
					cout << "You have 1 life remaining" << endl;
					cout << "" << endl;
				}
			} else if (isCorrect(questionNum, playerAnswer) && left == false) {	 // If answer is correct update money and tell the user
				playerMoney = updateMoney(playerMoney, true);
				cout << "Correct!" << endl;
				cout << "" << endl;
			}
		}

		if (left == true || questionNum > 9 || playerLives < MIN_LIVES) {
			contPlaying = false;
		}
	} while (contPlaying == true);

	if (left == true) {
		exitMessage("leave", playerMoney);
	} else if (playerLives == 0) {
		exitMessage("lose", playerMoney);
	} else {
		exitMessage("win", playerMoney);
	}

	return 0;
}