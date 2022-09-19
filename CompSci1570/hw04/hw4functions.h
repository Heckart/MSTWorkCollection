#ifndef HW4FUNCTIONS_H
#define HW4FUNCTIONS_H

#include <iostream>

using namespace std;

// Desc: This function updates the player's money
// Pre: None
// Post: If the question is correct, money is multipled by 2, else 100 is taken away
template <typename T>
int updateMoney(T currentMoney, bool isCorrect) {
	if (isCorrect == true) {
		currentMoney = currentMoney * 2;
	} else {
		currentMoney = currentMoney - 100;
	}
	return currentMoney;
}

// Desc: This function greets the user
// Pre: None
// Post: A greeting is printed to the terminal
void greeting();

// Desc: This function prints a question to the terminal
// Pre: None
// Post: The question corresponding to the questionNumber input is printed to the terminal
void print_question(int questionNumber);

// Desc: This function generates a random number between one and four
// Pre: None
// Post: A random number between one and four is printed to the terminal
void answerRandomly();

// Desc: This funciton provides a lifeline to the user with 80% chance of being correct
// Pre: None
// Post: A number with an 80% chance of being correct is printed to the terminal
void lifeLine(int questionNumber);

// Desc: This funcitons displays the closing message of the game
// Pre: The game has been completed
// Post: A messge corresponding to how the game ended (lost, won, left) is printed to the terminal along with the winnings
void exitMessage(string winLoseorLeave, int winnings);

// Desc: The function determines if the given answer to the given question is correct
// Pre: None
// Post: If the answer is correct, the function returns true, else false is returned
bool isCorrect(int questionNumber, int userAnswer);

// Desc: This fucntion determines if the input only contains digits
// Pre: None
// Post: If the input is all digits, the function retuns true, else false is returned
bool answerValidation(string answer);

// Desc: This function helps exit the question loop
// Pre: None
// Post: true is returned if it is called
bool leave();

#endif