
// Programmer: Jason Xu
// Date: 2-12-2022
// Assignment: HW2
// Purpose: Modified Wordle

#include <iostream>
#include <string>

using namespace std;

// this function gets the input from the user
string getInput(const string& prompt);

// this function checks if a string is a valid integer
bool isInteger(const string& str);

// this function checks if a string is a valid word (all alphabet)
bool isValidWord(const string& word);

// this function checks if "character" exists in the "word"
bool isInWord(const string& word, const char character);

int main() {
	string userInput, player1Name;
	bool cont;
	cout << "Welcome to Wordle for Friends!\n≤^.^≥" << endl;
	// get player 1 info
	player1Name = getInput("Player 1, please input your name:");
	cout << "Welcome, " << player1Name << endl;
	do {  // begin the game
		string player2Name;
		int friendshipLevel, rounds = 0;
		// get player 2 info
		player2Name = getInput("Player 2, please input your name:");
		cout << "Welcome, " << player2Name << endl;
		// input validation for the friendship level
		userInput = getInput(player1Name + ", please input friendship level:");
		while (!isInteger(userInput) || stoi(userInput) < 0 || stoi(userInput) > 100) {
			userInput = getInput(player1Name + ", please input friendship level (integer between 0 and 100): ");
		}
		friendshipLevel = stoi(userInput);
		do {  // begin the first round with player 2
			int usedAttempts = 0;
			string guessWord, player2Guess;
			guessWord = getInput(player1Name + ", please input word for Player 2 to guess:");
			while (!isValidWord(guessWord)) {
				guessWord = getInput(player1Name + ", please input word for Player 2 to guess (must be a 5 letter word): ");
			}
			player2Guess = getInput(player2Name + ", please input guess:");
			while (!isValidWord(player2Guess)) {
				player2Guess = getInput(player2Name + ", please input guess (must be a 5 letter word):");
			}
			usedAttempts++;
			// player 2 has a maximum of 6 attempts
			while (player2Guess != guessWord && usedAttempts <= 6) {
				cout << "You entered \"" << player2Guess << "\". Nice try, keep going !" << endl;
				for (int i = 0; i < 5; i++) {
					if (guessWord[i] == player2Guess[i]) {
						cout << player2Guess[i] << ": ^o^" << endl;
					} else if (isInWord(guessWord, player2Guess[i])) {
						cout << player2Guess[i] << ": ^( '-' )^" << endl;
					} else {
						cout << player2Guess[i] << ": @.@" << endl;
					}
				}
				player2Guess = getInput("This is your attempt #" + to_string(usedAttempts + 1) + ", " + player2Name + ", please input guess:");
				while (!isValidWord(player2Guess)) {
					player2Guess = getInput(player2Name + ", please input guess (must be a 5 letter word): ");
				}
				usedAttempts++;
			}
			if (guessWord == player2Guess) {
				cout << "You entered \"" << player2Guess << "\". Congratulations, \"" << player2Guess << "\" it is!" << endl;
				cout << "Friendship Level: " << friendshipLevel << " -> " << (friendshipLevel + usedAttempts) << endl;
				friendshipLevel += usedAttempts;
			} else {
				cout << "Sorry, you ran out of guesses, the correct word was \"" << guessWord << "\"!" << endl;
			}
			rounds++;
			// output the round summary
			cout << "Round " << rounds << " summary:\n"
				 << "\tPlayer 1: " << player1Name << "\n"
				 << "\tPlayer 2: " << player2Name << endl;
			userInput = getInput("Play again with " + player2Name + "?");
			while (userInput != "y" && userInput != "n" && userInput != "Y" && userInput != "N") {
				userInput = getInput("Play again with " + player2Name + " (Yy/Nn)?");
			}
			cont = userInput == "y" || userInput == "Y";
		} while (cont);
		cout << "Ok, " << player1Name << ". Your final friendship level with " << player2Name << " is " << friendshipLevel << " after " << rounds << (rounds > 1 ? " rounds " : " round " << "of Wordle. \nRemember, a real friend is one who always Wordles with you when the rest of the world won’t !" << endl; 
             userInput = getInput("Play again with a new Player 2?");
		while (userInput != "y" && userInput != "n" && userInput != "Y" && userInput != "N") {
			userInput = getInput("Play again with a new Player 2 (Yy/Nn)?");
		}
		cont = userInput == "y" || userInput == "Y";
	} while (cont);
	cout << "Ok, good bye, " << player1Name << "! See you soon, Wordle Wordle!" << endl;
	return 0;
}
string getInput(const string& prompt) {
	string input;
	cout << prompt << endl;
	cin >> input;
	return input;
}
bool isInteger(const string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}
bool isValidWord(const string& word) {
	if (word.length() != 5) {
		return false;
	}
	for (size_t i = 0; i < word.length(); i++) {
		if (!isalpha(word[i])) {
			return false;
		}
	}
	return true;  // The bonus is left as an exercise to the reader :P
}
bool isInWord(const string& word, const char character) {
	for (size_t i = 0; i < word.length(); i++) {
		if (word[i] == character) {
			return true;
		}
	}
	return false;
}
