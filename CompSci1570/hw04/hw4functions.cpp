#include "hw4functions.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void greeting() {
	cout << "Welcome to are you smarter than a comp sci! Are you ready to play?" << endl;
	cout << "" << endl;
	return;
}

void print_question(const int questionNumber) {
	switch (questionNumber) {
		case 1:
			cout << "Question 1: Which of these is not a numeric data type?" << endl;
			cout << "1 - Integer" << endl;
			cout << "2 - Double" << endl;
			cout << "3 - Boolean" << endl;
			cout << "4 - Float" << endl;
			break;
		case 2:
			cout << "Question 2: Which of the following is a reserved C++ keyword?" << endl;
			cout << "1 - Buddy" << endl;
			cout << "2 - Friend" << endl;
			cout << "3 - Pal" << endl;
			cout << "4 - Homeslice" << endl;
			break;
		case 3:
			cout << "Question 3: What does the \"&\" symbol mean in C++?" << endl;
			cout << "1 - Address of" << endl;
			cout << "2 - And" << endl;
			cout << "3 - Not" << endl;
			cout << "4 - Value of" << endl;
			break;
		case 4:
			cout << "Question 4: You do not need to document your functions in CS1570" << endl;
			cout << "1 - True" << endl;
			cout << "2 - False" << endl;
			cout << "3 - Sometimes" << endl;
			cout << "4 - I don't know" << endl;
			break;
		case 5:
			cout << "Question 5: What is \"OOP\"?" << endl;
			cout << "1 - Only Once Programming" << endl;
			cout << "2 - Object Oriented Programming" << endl;
			cout << "3 - What I say when I stub my toe" << endl;
			cout << "4 - Ope, oh peanuts" << endl;
			break;
		case 6:
			cout << "Question 6: How many significant digits can a float have?" << endl;
			cout << "1 - Nine" << endl;
			cout << "2 - Eight" << endl;
			cout << "3 - Seven" << endl;
			cout << "4 - Six" << endl;
			break;
		case 7:
			cout << "Question 7: If C is three, then C++ is:" << endl;
			cout << "1 - An object oriented programming language" << endl;
			cout << "2 - Four" << endl;
			cout << "3 - Amazing" << endl;
			cout << "4 - All of the above" << endl;
			break;
		case 8:
			cout << "Question 8: What is the maximum value of a signed integer in C++?" << endl;
			cout << "1 - 81" << endl;
			cout << "2 - 2,147,483,647" << endl;
			cout << "3 - 11" << endl;
			cout << "4 - -12" << endl;
			break;
		case 9:
			cout << "Question 9: What does \"==\" do in C++?" << endl;
			cout << "1 - Sets the left variable equal to the right variable" << endl;
			cout << "2 - Checks the validity of a data type in C++" << endl;
			cout << "3 - Checks if two values are equal to each other" << endl;
			cout << "4 - All of the above" << endl;
			break;
		case 10:
			cout << "Question 10: Can you lose money in this game show?" << endl;
			cout << "1 - Yes" << endl;
			cout << "2 - No" << endl;
			cout << "3 - Don't pick this one" << endl;
			cout << "4 - Don't pick this one either" << endl;
		default:
			break;
	}
	return;
}

void answerRandomly() {
	int randomNum = 0;
	randomNum = (rand() % (4 - 1 + 1)) + 1;
	cout << "You have thought of " << randomNum << ". What is your answer?" << endl;
	cout << "" << endl;
	return;
}

void lifeLine(int questionNumber) {
	int randomNum = 0;
	int returnNum = 0;
	static int numLifelines = 4;

	numLifelines--;

	if (numLifelines > 0) {
		randomNum = (rand() % (10 - 1 + 1)) + 1;

		if (randomNum > 2) {
			switch (questionNumber) {
				case 1:
					returnNum = 3;
					break;
				case 2:
					returnNum = 2;
					break;
				case 3:
					returnNum = 1;
					break;
				case 4:
					returnNum = 2;
					break;
				case 5:
					returnNum = 2;
					break;
				case 6:
					returnNum = 4;
					break;
				case 7:
					returnNum = 4;
					break;
				case 8:
					returnNum = 2;
					break;
				case 9:
					returnNum = 3;
					break;
				case 10:
					returnNum = 1;
					break;
				default:
					break;
			}
		}
		if (randomNum <= 2) {
			switch (questionNumber) {
				case 1:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					if (returnNum == 3) {
						returnNum = 4;
					}
					break;
				case 2:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					if (returnNum == 2) {
						returnNum = 4;
					}
					break;
				case 3:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					if (returnNum == 1) {
						returnNum = 4;
					}
					break;
				case 4:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					if (returnNum == 2) {
						returnNum = 4;
					}
					break;
				case 5:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					if (returnNum == 2) {
						returnNum = 4;
					}
					break;
				case 6:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					break;
				case 7:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					break;
				case 8:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					if (returnNum == 2) {
						returnNum = 4;
					}
					break;
				case 9:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					if (returnNum == 3) {
						returnNum = 4;
					}
					break;
				case 10:
					returnNum = (rand() % (3 - 1 + 1)) + 1;
					if (returnNum == 1) {
						returnNum = 4;
					}
					break;
				default:
					break;
			}
		}
		cout << "" << endl;
		cout << "Your friend said the answer is " << returnNum << ". What is your answer?" << endl;
		cout << "" << endl;
	}
	if (numLifelines < 1) {
		cout << "" << endl;
		cout << "You have no lifelines remaining." << endl;
		cout << "" << endl;
	}
	return;
}

void exitMessage(const string winLoseorLeave, const int winnings) {
	if (winLoseorLeave == "win") {
		cout << "" << endl;
		cout << "Congratulations! You are smarter than a comp sci. Your winnings are $" << winnings << "." << endl;
	} else if (winLoseorLeave == "lose") {
		cout << "" << endl;
		cout << "You lost, and walked away with $0" << endl;
	} else if (winLoseorLeave == "leave") {
		cout << "" << endl;
		cout << "You left and walked away with $" << winnings << "." << endl;
	}
	return;
}

bool isCorrect(const int questionNumber, const int userAnswer = 3) {
	switch (questionNumber) {
		case 1:
			if (userAnswer == 3) {
				return true;
			}
			break;
		case 2:
			if (userAnswer == 2) {
				return true;
			}
			break;
		case 3:
			if (userAnswer == 1) {
				return true;
			}
			break;
		case 4:
			if (userAnswer == 2) {
				return true;
			}
			break;
		case 5:
			if (userAnswer == 2) {
				return true;
			}
			break;
		case 6:
			if (userAnswer == 4) {
				return true;
			}
			break;
		case 7:
			if (userAnswer == 4) {
				return true;
			}
			break;
		case 8:
			if (userAnswer == 2) {
				return true;
			}
			break;
		case 9:
			if (userAnswer == 3) {
				return true;
			}
			break;
		case 10:
			if (userAnswer == 1) {
				return true;
			}
			break;
		default:
			break;
	}
	return false;
}

bool answerValidation(const string answer) {
	for (size_t i = 0; i < answer.length(); i++) {
		if (!isdigit(answer[i])) {
			return false;
		}
	}
	return true;
}

bool leave() { return true; }