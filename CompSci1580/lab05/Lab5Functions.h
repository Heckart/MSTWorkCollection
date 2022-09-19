#ifndef LAB5FUNCTIONS_H
#define LAB5FUNCTIONS_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Desc: This functions determines who wins a round of rock paper scissors
// Pre: None
// Post: numNormoWins increases if Normo wins, numJudgeWins increases if judge wins, else no change
void playRPS(const string normoInput, int& numNormoWins, int& numJudgeWins, int judgeInput = 1);

#endif