// Programmer: Ethan Heckart
// Date: 2/9/2022
// File: homework2.cpp
// Assignment: HW2
// Purpose: this file contains the program Wordle For Friends

#include <ctype.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
	/* ------- Variable Declarations ------- */
	string guess_wrd = "null";		// The Word to be guessed
	string plr1_name = "null";		// Name of Player 1
	string plr2_name = "null";		// Name of Player 2
	string guess = "null";			// Guess of Player 2
	string new_game_input = "N";	// User input to detemine if a new game is to be played with the same players
	string play_again_input = "N";	// User input to determine if a new game is to be played with a new player
	short friend_lvl = 0;			// Friendship level between players
	short new_friend_lvl = 0;		// The Friendship level after playing a round
	short wrd_len = 0;				// Length of word to be guessed
	short guess_len = 0;			// Length of guesser's word
	short round_num = 0;			// Round Number
	short alpha_counter = 0;		// Numebr of charcters in the string that is alphabetic
	bool play_again = 0;			// Loops the game again with new players if = 1
	bool new_game = 0;				// Loops the game again with same players if = 1
	bool correct = 0;				// Guess was correct if = 1
	bool is_alpha = 0;				// Word to be guessed is alphabetic if = 1
	bool is_alpha_guess = 0;		// Gusser's word is alphabetic if = 1

	/* ------- Greetings ------- */
	cout << "Welcome to Wordle For Friends!" << endl;
	cout << "<^.^>" << endl;
	cout << "" << endl;
	cout << "Player 1, please enter your name:" << endl;
	cin >> plr1_name;
	cout << "Welcome, " << plr1_name << "!" << endl;
	cout << "" << endl;

	/* ------- Player 2 Input ------- */
	do {
		play_again = 0;
		cout << "Now, Player 2, please enter your name: " << endl;
		cin >> plr2_name;
		cout << "Welcome, " << plr2_name << "!";
		cout << "" << endl;
		cout << "" << endl;
		cout << plr1_name << ", please rate the friendship level you have with" << plr2_name << " (enter an integer value in [0, 100]):" << endl;
		cin >> friend_lvl;
		while (friend_lvl < 0 || friend_lvl > 100) {
			cout << "" << endl;
			cout << "Can't you read, " << plr1_name << " The friendship level you input is invalid!" << endl;
			cout << "" << endl;
			cout << "Please enter the friendship level again (an integer value in [0, 100]):" << endl;
			cin >> friend_lvl;
		}
		cout << "" << endl;
		cout << "Hooray, that's an admirabe friendship between you two!" << endl;
		cout << "" << endl;

		/* ------- Word Input ------- */
		do {
			new_game = 1;
			round_num++;
			correct = 0;
			cout << "Let the game begin now!" << endl;
			cout << "" << endl;
			cout << "Wait..." << plr1_name
				 << ", I need the key word from you (yes, you may whisper into my ears... and remember, it has to be a valid five-letter word all UPPERCASE):"
				 << endl;
			cin >> guess_wrd;
			wrd_len = guess_wrd.length();
			cout << "" << endl;
			while (wrd_len != 5) {
				cout << "Seriously, " << plr1_name << "? Your input word is " << wrd_len << " letters long! Don't make me quit on you right now..." << endl;
				cout << "" << endl;
				cout << "Please enter the key word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
				cin >> guess_wrd;
				wrd_len = guess_wrd.length();
			}

			while (is_alpha != 1) {
				alpha_counter = 0;
				for (int i = 0; i < guess_wrd.length(); i++) {
					if (isalpha(guess_wrd[i]) == 0) {
						cout << "" << endl;
						cout << "Don't make me arrest you, " << plr1_name << "! Your input word is contaminated with non-alphabet characters..." << endl;
						cout << "" << endl;
						cout << "Please enter the key word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
						is_alpha = 0;
						cin >> guess_wrd;
						alpha_counter = 0;
					}

					if (isalpha(guess_wrd[i]) != 0) {
						alpha_counter++;
					}
					if (alpha_counter == 5) {
						is_alpha = 1;
					}
				}
			}

			cout << "Got it, " << plr1_name << " The key word is now securely processed and saved." << endl;
			cout << "" << endl;

			/* ------- Guesses ------- */
			cout << "Get ready, " << plr2_name << ". It's now time to Wordle with " << plr1_name << "!" << endl;
			cout << "You will have a total of 6 attempts to guess the word correctly." << endl;
			cout << "" << endl;

			cout << "This is your attempt #1, " << plr2_name << ", please enter a valid five-letter word (all UPPERCASE):" << endl;
			cin >> guess;
			guess_len = guess.length();
			while (guess_len != 5) {
				cout << "" << endl;
				cout << "Seriously, " << plr2_name << "? Your input word is " << wrd_len << " letters long! Don't make me quit on you right now..." << endl;
				cout << "" << endl;
				cout << "Please enter the guessing word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
				cin >> guess;
				guess_len = guess.length();
			}
			while (is_alpha_guess != 1) {
				alpha_counter = 0;
				for (int i = 0; i < guess.length(); i++) {
					if (isalpha(guess[i]) == 0) {
						cout << "" << endl;
						cout << "Don't make me arrest you, " << plr2_name << "! Your input word is contaminated with non-alphabet characters..." << endl;
						cout << "" << endl;
						cout << "Please enter the key word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
						is_alpha_guess = 0;
						cin >> guess;
						alpha_counter = 0;
					}

					if (isalpha(guess[i]) != 0) {
						alpha_counter++;
					}
					if (alpha_counter == 5) {
						is_alpha_guess = 1;
					}
				}
			}

			if (guess != guess_wrd) {
				cout << "You enterred \"" << guess << "\". Nice try, keep going!" << endl;
				for (int index = 0; index < guess.length(); index++) {
					cout << guess.at(index);
					if (guess.at(index) == guess_wrd.at(index)) {
						cout << ": ^o^" << endl;
					} else if (guess_wrd.find(guess.at(index)) != string::npos) {
						cout << ": ^('-')^" << endl;
					} else {
						cout << ": @.@" << endl;
					}
				}
			}
			if (guess == guess_wrd) {
				cout << "You entered \"" << guess << "\". Congratulations, \"" << guess << "\" it is!" << endl;
				correct = 1;
				if (friend_lvl < 100) {
					new_friend_lvl = friend_lvl + 1;
				} else {
					new_friend_lvl = 100;
				}
			}

			if (correct != 1) {
				is_alpha_guess = 0;
				cout << "" << endl;
				cout << "This is your attempt #2, " << plr2_name << ", please enter a valid five-letter word (all UPPERCASE):" << endl;
				cin >> guess;
				guess_len = guess.length();
				while (guess_len != 5) {
					cout << "" << endl;
					cout << "Seriously, " << plr2_name << "? Your input word is " << wrd_len << " letters long! Don't make me quit on you right now..." << endl;
					cout << "" << endl;
					cout << "Please enter the guessing word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
					cin >> guess;
					guess_len = guess.length();
				}
				while (is_alpha_guess != 1) {
					alpha_counter = 0;
					for (int i = 0; i < guess.length(); i++) {
						if (isalpha(guess[i]) == 0) {
							cout << "" << endl;
							cout << "Don't make me arrest you, " << plr2_name << "! Your input word is contaminated with non-alphabet characters..." << endl;
							cout << "" << endl;
							cout << "Please enter the key word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
							is_alpha_guess = 0;
							cin >> guess;
							alpha_counter = 0;
						}

						if (isalpha(guess[i]) != 0) {
							alpha_counter++;
						}
						if (alpha_counter == 5) {
							is_alpha_guess = 1;
						}
					}
				}
				if (guess != guess_wrd) {
					cout << "" << endl;
					cout << "You enterred \"" << guess << "\". Nice try, keep going!" << endl;
					for (int index = 0; index < guess.length(); index++) {
						cout << guess.at(index);
						if (guess.at(index) == guess_wrd.at(index)) {
							cout << ": ^o^" << endl;
						} else if (guess_wrd.find(guess.at(index)) != string::npos) {
							cout << ": ^('-')^" << endl;
						} else {
							cout << ": @.@" << endl;
						}
					}
				}
				if (guess == guess_wrd) {
					cout << "You entered \"" << guess << "\". Congratulations, \"" << guess << "\" it is!" << endl;
					correct = 1;
					if (friend_lvl < 99) {
						new_friend_lvl = friend_lvl + 2;
					} else {
						new_friend_lvl = 100;
					}
				}
			}

			if (correct != 1) {
				is_alpha_guess = 0;
				cout << "" << endl;
				cout << "This is your attempt #3, " << plr2_name << ", please enter a valid five-letter word (all UPPERCASE):" << endl;
				cin >> guess;
				guess_len = guess.length();
				while (guess_len != 5) {
					cout << "" << endl;
					cout << "Seriously, " << plr2_name << "? Your input word is " << wrd_len << " letters long! Don't make me quit on you right now..." << endl;
					cout << "" << endl;
					cout << "Please enter the guessing word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
					cin >> guess;
					guess_len = guess.length();
				}
				while (is_alpha_guess != 1) {
					alpha_counter = 0;
					for (int i = 0; i < guess.length(); i++) {
						if (isalpha(guess[i]) == 0) {
							cout << "" << endl;
							cout << "Don't make me arrest you, " << plr2_name << "! Your input word is contaminated with non-alphabet characters..." << endl;
							cout << "" << endl;
							cout << "Please enter the key word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
							is_alpha_guess = 0;
							cin >> guess;
							alpha_counter = 0;
						}

						if (isalpha(guess[i]) != 0) {
							alpha_counter++;
						}
						if (alpha_counter == 5) {
							is_alpha_guess = 1;
						}
					}
				}
				if (guess != guess_wrd) {
					cout << "You enterred \"" << guess << "\". Nice try, keep going!" << endl;
					for (int index = 0; index < guess.length(); index++) {
						cout << guess.at(index);
						if (guess.at(index) == guess_wrd.at(index)) {
							cout << ": ^o^" << endl;
						} else if (guess_wrd.find(guess.at(index)) != string::npos) {
							cout << ": ^('-')^" << endl;
						} else {
							cout << ": @.@" << endl;
						}
					}
				}
				if (guess == guess_wrd) {
					cout << "You entered \"" << guess << "\". Congratulations, \"" << guess << "\" it is!" << endl;
					correct = 1;
					if (friend_lvl < 98) {
						new_friend_lvl = friend_lvl + 3;
					} else {
						new_friend_lvl = 100;
					}
				}
			}

			if (correct != 1) {
				is_alpha_guess = 0;
				cout << "" << endl;
				cout << "This is your attempt #4, " << plr2_name << ", please enter a valid five-letter word (all UPPERCASE):" << endl;
				cin >> guess;
				guess_len = guess.length();
				while (guess_len != 5) {
					cout << "" << endl;
					cout << "Seriously, " << plr2_name << "? Your input word is " << wrd_len << " letters long! Don't make me quit on you right now..." << endl;
					cout << "" << endl;
					cout << "Please enter the guessing word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
					cin >> guess;
					guess_len = guess.length();
				}
				while (is_alpha_guess != 1) {
					alpha_counter = 0;
					for (int i = 0; i < guess.length(); i++) {
						if (isalpha(guess[i]) == 0) {
							cout << "" << endl;
							cout << "Don't make me arrest you, " << plr2_name << "! Your input word is contaminated with non-alphabet characters..." << endl;
							cout << "" << endl;
							cout << "Please enter the key word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
							is_alpha_guess = 0;
							cin >> guess;
							alpha_counter = 0;
						}

						if (isalpha(guess[i]) != 0) {
							alpha_counter++;
						}
						if (alpha_counter == 5) {
							is_alpha_guess = 1;
						}
					}
				}
				if (guess != guess_wrd) {
					cout << "You enterred \"" << guess << "\". Nice try, keep going!" << endl;
					for (int index = 0; index < guess.length(); index++) {
						cout << guess.at(index);
						if (guess.at(index) == guess_wrd.at(index)) {
							cout << ": ^o^" << endl;
						} else if (guess_wrd.find(guess.at(index)) != string::npos) {
							cout << ": ^('-')^" << endl;
						} else {
							cout << ": @.@" << endl;
						}
					}
				}
				if (guess == guess_wrd) {
					cout << "You entered \"" << guess << "\". Congratulations, \"" << guess << "\" it is!" << endl;
					correct = 1;
					if (friend_lvl < 97) {
						new_friend_lvl = friend_lvl + 4;
					} else {
						new_friend_lvl = 100;
					}
				}
			}

			if (correct != 1) {
				is_alpha_guess = 0;
				cout << "" << endl;
				cout << "This is your attempt #5, " << plr2_name << ", please enter a valid five-letter word (all UPPERCASE):" << endl;
				cin >> guess;
				guess_len = guess.length();
				while (guess_len != 5) {
					cout << "" << endl;
					cout << "Seriously, " << plr2_name << "? Your input word is " << wrd_len << " letters long! Don't make me quit on you right now..." << endl;
					cout << "" << endl;
					cout << "Please enter the guessing word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
					cin >> guess;
					guess_len = guess.length();
				}
				while (is_alpha_guess != 1) {
					alpha_counter = 0;
					for (int i = 0; i < guess.length(); i++) {
						if (isalpha(guess[i]) == 0) {
							cout << "" << endl;
							cout << "Don't make me arrest you, " << plr2_name << "! Your input word is contaminated with non-alphabet characters..." << endl;
							cout << "" << endl;
							cout << "Please enter the key word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
							is_alpha_guess = 0;
							cin >> guess;
							alpha_counter = 0;
						}

						if (isalpha(guess[i]) != 0) {
							alpha_counter++;
						}
						if (alpha_counter == 5) {
							is_alpha_guess = 1;
						}
					}
				}
				if (guess != guess_wrd) {
					cout << "You enterred \"" << guess << "\". Nice try, keep going!" << endl;
					for (int index = 0; index < guess.length(); index++) {
						cout << guess.at(index);
						if (guess.at(index) == guess_wrd.at(index)) {
							cout << ": ^o^" << endl;
						} else if (guess_wrd.find(guess.at(index)) != string::npos) {
							cout << ": ^('-')^" << endl;
						} else {
							cout << ": @.@" << endl;
						}
					}
				}
				if (guess == guess_wrd) {
					cout << "You entered \"" << guess << "\". Congratulations, \"" << guess << "\" it is!" << endl;
					correct = 1;
					if (friend_lvl < 96) {
						new_friend_lvl = friend_lvl + 5;
						;
					} else {
						new_friend_lvl = 100;
					}
				}
			}

			if (correct != 1) {
				is_alpha_guess = 0;
				cout << "" << endl;
				cout << "This is your attempt #6, " << plr2_name << ", please enter a valid five-letter word (all UPPERCASE):" << endl;
				cin >> guess;
				guess_len = guess.length();
				while (guess_len != 5) {
					cout << "" << endl;
					cout << "Seriously, " << plr2_name << "? Your input word is " << wrd_len << " letters long! Don't make me quit on you right now..." << endl;
					cout << "" << endl;
					cout << "Please enter the guessing word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
					cin >> guess;
					guess_len = guess.length();
				}
				while (is_alpha_guess != 1) {
					alpha_counter = 0;
					for (int i = 0; i < guess.length(); i++) {
						if (isalpha(guess[i]) == 0) {
							cout << "" << endl;
							cout << "Don't make me arrest you, " << plr2_name << "! Your input word is contaminated with non-alphabet characters..." << endl;
							cout << "" << endl;
							cout << "Please enter the key word again (remember, it has to be a valid five-letter word all UPPERCASE):" << endl;
							is_alpha_guess = 0;
							cin >> guess;
							alpha_counter = 0;
						}

						if (isalpha(guess[i]) != 0) {
							alpha_counter++;
						}
						if (alpha_counter == 5) {
							is_alpha_guess = 1;
						}
					}
				}
				if (guess != guess_wrd) {
					cout << "You enterred \"" << guess << "\". Nice try, keep going!" << endl;
					for (int index = 0; index < guess.length(); index++) {
						cout << guess.at(index);
						if (guess.at(index) == guess_wrd.at(index)) {
							cout << ": ^o^" << endl;
						} else if (guess_wrd.find(guess.at(index)) != string::npos) {
							cout << ": ^('-')^" << endl;
						} else {
							cout << ": @.@" << endl;
						}
					}
				}
				if (guess == guess_wrd) {
					cout << "You entered \"" << guess << "\". Congratulations, \"" << guess << "\" it is!" << endl;
					correct = 1;
					if (friend_lvl < 95) {
						new_friend_lvl = friend_lvl + 6;
					} else {
						new_friend_lvl = 100;
					}
				}
			}
			/* ----- Round end summary ----- */

			cout << "Round " << round_num << " Summary" << endl;
			cout << "   Player 1: " << plr1_name << endl;
			cout << "   Player 2: " << plr2_name << endl;
			cout << "   Friendship Level: " << friend_lvl << " -> " << new_friend_lvl << endl;
			friend_lvl = new_friend_lvl;
			cout << "" << endl;
			cout << plr1_name << ", do you want to play another round with " << plr2_name << " (Y/N)?" << endl;
			cin >> new_game_input;
			if (new_game_input == "N") {
				cout << "" << endl;
				cout << "OK, " << plr1_name << ". Your final friendship level with " << plr2_name << " is " << new_friend_lvl << " after " << round_num
					 << " round(s) of Wordle." << endl;
				cout << "Remember, a real friend is one who always Wordles with you when the rest won't!" << endl;
				new_game = 0;
			} else {
				new_game = 1;
			}
		} while (new_game == 1);
		cout << "" << endl;
		cout << "Okay " << plr1_name << ", do you want to start a new game with a different player then (Y/N)?" << endl;
		cin >> play_again_input;
		if (play_again_input == "N") {
			cout << "" << endl;
			cout << "OK, good bye, " << plr1_name << "! See you soon, Wordle Wordle!" << endl;
		} else {
			play_again = 1;
		}
	} while (play_again == 1);
	return 0;
}
