#include "lab5Functions.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void playRPS(const string normoInput, int& numNormoWins, int& numJudgeWins, int judgeInput) {
	string judgeWord;
	if (judgeInput == 1) {
		judgeWord = "rock";
	} else if (judgeInput == 2) {
		judgeWord = "paper";
	} else {
		judgeWord = "scissors";
	}

	cout << "Judge chooses: " << judgeWord << endl;

	if (normoInput == "rock" && judgeInput == 3) {
		cout << "You have won a round" << endl;
		numNormoWins++;
		return;
	} else if (normoInput == "paper" && judgeInput == 1) {
		cout << "You have won a round" << endl;
		numNormoWins++;
		return;
	} else if (normoInput == "scissors" && judgeInput == 2) {
		cout << "You have won a round" << endl;
		numNormoWins++;
		return;
	} else if (normoInput == judgeWord) {
		cout << "You have tied a round" << endl;
	} else {
		cout << "You have lost a round" << endl;
		numJudgeWins++;
	}
	return;
}