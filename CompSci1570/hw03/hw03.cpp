// Programmer: Ethan Heckart
// Date: 2/25/22
// File hw03.cpp
// Assignment: HW3
// Purpose: This file contains the program Wordle for Friends using a switch case and functions

#include <iostream>

using namespace std;

// Desc: This function sends a greeting to the user at the beginning of the program
// Pre: None
// Post: A greeting is printed to the terminal
void greet();

// Desc: This funciton gets new input from the user and can save it to a new variable
// Pre: None
// Post: The user's input is taken and returned
string new_input(const string& message);

// Desc: This function takes a string and verifies that it only contains digits
// Pre: None
// Post: Returns true if string is only digits, else returns false
bool integer_validation(const string& integer);

// Desc: This function takes a string and verifies that it conatins five letter
// Pre: None
// Post: Returns true if string is 5 lettersm else returns false
bool word_validation(const string& word);

// Desc: This function will print a summary of the games played between the current players
// Pre: At least one round has been played
// Post: Game summary is printed to the terminal. If the friend level is < 20, it is increased by 2
void printGameSummary(const string PLR1_NAME, const string PLR2_NAME, const int ROUNDS_PLAYED, const int INIT_FRIEND_LVL, int& current_friend_lvl);

// Desc: This function will print a summary of the last round
// Pre: At least one round has been played
// Post: Round summary is printed to the terminal including the wordle faces per guess
void shareWordle(const string PLR1_NAME, const string PLR2_NAME, const int LAST_RND_NUM, const int NUM_ATTEMPS, const string FACES);

int main() {
	int menu_val = 0;
	int round_num = 0;
	int initial_friend_lvl = 0;
	int friend_lvl = 0;
	int num_guesses = 0;
	const int MENU_ONE = 1, MENU_TWO = 2, MENU_THREE = 3, MENU_FOUR = 4, MENU_FIVE = 5;
	const int MIN_FRND_LVL = 1, MAX_FRND_LVL = 100;
	const int MAX_GUESSES = 7;
	bool cont_playing = true;
	bool correct_guess = false;
	string plr1_name = "Null", plr2_name = "Null";
	string user_input = "Null";	 // Used as a placeholder for integer values
	string guess_wrd = "Null";	 // Word to be guessed
	string plr2_guess = "Null";
	string wordle_faces = "";

	greet();
	plr1_name = new_input("Player 1, please enter your name:");
	cout << "Welcome, " << plr1_name << "!" << endl;
	cout << "" << endl;
	while (cont_playing == true) {
		cout << "The Wordle's Menu" << endl;
		cout << "-----------------" << endl;
		cout << "1. Start a new game (with new players)" << endl;
		cout << "2. Start a new round (with existing players)" << endl;
		cout << "3. Print game summary (of existing players)" << endl;
		cout << "4. Share result (of last round)" << endl;
		cout << "5. Exit the game (are you sure?)" << endl;
		cout << "" << endl;
		cin >> user_input;

		while (!integer_validation(user_input) || stoi(user_input) < MENU_ONE || stoi(user_input) > MENU_FIVE) {  // Verify input is a number in [1,5]
			cout << "Your input must be included in the menu" << endl;
			user_input = new_input("Please enter a new menu value");
			cout << "" << endl;
		}

		menu_val = stoi(user_input);
		while ((menu_val == MENU_TWO || menu_val == MENU_THREE || menu_val == MENU_FOUR) &&
			   round_num < 1) {	 // Verify atleast one round has been played to chose options three or four
			cout << "You have to complete a round to use that option" << endl;
			cout << "Please enter a new menu value" << endl;
			cin >> menu_val;
			cout << "" << endl;
		}

		switch (menu_val) {
			case 1:
				/* ---------- Get player 2 name and friendship level ---------- */
				correct_guess = false;
				friend_lvl = 0;
				round_num = 1;
				plr2_name = new_input("Now, Player 2, please enter your name: ");
				cout << "Welcome, " << plr2_name << "!" << endl;
				cout << "" << endl;
				user_input = new_input(plr1_name + ", Please rate your friendship with " + plr2_name + " (enter an integer value in [0, 100]): ");

				while (!integer_validation(user_input) || stoi(user_input) < MIN_FRND_LVL ||
					   stoi(user_input) > MAX_FRND_LVL) {  // Verify input is a number in [1,100]
					cout << "Your input must be between 1 and 100 inclusive" << endl;
					user_input = new_input("Please enter a new menu value\n");
					cout << "" << endl;
				}

				friend_lvl = stoi(user_input);
				initial_friend_lvl = friend_lvl;
				cout << "" << endl;
				cout << "Hooray, that's an admirable friendship level between you two!" << endl;
				cout << "" << endl;

				/* ---------- Get guess word ---------- */
				cout << "Let the game being now!" << endl;
				cout << "" << endl;
				guess_wrd = new_input(
					"Wait... " + plr1_name +
					", I need the key word from you (yes, you may whisper it into my ears...) and remember, it has to be a valid five-letter word all UPPERCASE");

				while (!word_validation(guess_wrd)) {  // Verfy word is all leters and 5 characters
					guess_wrd = new_input("Your word must be five letters long and all UPERCASE. Please try again");
				}

				cout << "Got it, " << plr1_name << " The key word is now securely processed and saved." << endl;

				/* ---------- Guesses ---------- */
				cout << "" << endl;
				cout << "Get ready, " << plr2_name << ". It's mow time to Wordle with " << plr1_name << "!" << endl;
				cout << "You will have a total of 6 attempts to guess the word correctly." << endl;
				num_guesses = 0;
				wordle_faces = "";

				do {
					num_guesses++;
					if (num_guesses == MAX_GUESSES) {
						cout << "You have run out of guesses" << endl;
						cout << "The word was " << guess_wrd << endl;
						cout << "" << endl;
					} else {
						cout << "" << endl;
						plr2_guess = new_input("This is your attempt #" + to_string(num_guesses) + ", " + plr2_name + ", please input guess:");

						while (!word_validation(plr2_guess)) {	// Verfy guess is all leters and 5 characters
							plr2_guess = new_input("Your guess must be five letters long and all UPERCASE. Please try again");
						}

						if (plr2_guess != guess_wrd) {
							cout << "You entered \"" << plr2_guess << "\". Nice try, keep going!" << endl;
							wordle_faces += "\n";
							for (int index = 0; index < 5; index++) {
								cout << plr2_guess.at(index);
								if (plr2_guess.at(index) == guess_wrd.at(index)) {
									cout << ": ^o^" << endl;
									wordle_faces += "^o^ ";
								} else if (guess_wrd.find(plr2_guess.at(index)) != string::npos) {
									cout << ": ^-^" << endl;
									wordle_faces += "^-^ ";
								} else {
									cout << ": @.@" << endl;
									wordle_faces += "@.@ ";
								}
							}
						}
						if (plr2_guess == guess_wrd) {
							cout << "You entered \"" << plr2_guess << "\". Congratulations, \"" << plr2_guess << "\" it is!" << endl;
							cout << "" << endl;
							friend_lvl += num_guesses;
							wordle_faces += "\n^o^ ^o^ ^o^ ^o^ ^o^";
							if (friend_lvl > MAX_FRND_LVL) {
								friend_lvl = MAX_FRND_LVL;
							}
							correct_guess = true;
						}
					}
				} while (correct_guess == false && num_guesses < MAX_GUESSES);
				break;
			case 2:
				/* ---------- Get guess word ---------- */
				round_num++;
				correct_guess = false;
				cout << "Let the game being now!" << endl;
				cout << "" << endl;
				guess_wrd = new_input(
					"Wait... " + plr1_name +
					", I need the key word from you (yes, you may whisper it into my ears...) and remember, it has to be a valid five-letter word all UPPERCASE");

				while (!word_validation(guess_wrd)) {  // Verfy word is all leters and 5 characters
					guess_wrd = new_input("Your word must be five letters long and all UPERCASE. Please try again");
				}

				cout << "Got it, " << plr1_name << " The key word is now securely processed and saved." << endl;

				/* ---------- Guesses ---------- */
				cout << "" << endl;
				cout << "Get ready, " << plr2_name << ". It's mow time to Wordle with " << plr1_name << "!" << endl;
				cout << "You will have a total of 6 attempts to guess the word correctly." << endl;
				num_guesses = 0;
				wordle_faces = "";

				do {
					num_guesses++;
					if (num_guesses == MAX_GUESSES) {
						cout << "You have run out of guesses" << endl;
						cout << "The word was " << guess_wrd << endl;
						cout << "" << endl;
					} else {
						cout << "" << endl;
						plr2_guess = new_input("This is your attempt #" + to_string(num_guesses) + ", " + plr2_name + ", please input guess:");

						while (!word_validation(plr2_guess)) {	// Verfy guess is all leters and 5 characters
							plr2_guess = new_input("Your guess must be five letters long and all UPERCASE. Please try again");
						}

						if (plr2_guess != guess_wrd) {
							cout << "You entered \"" << plr2_guess << "\". Nice try, keep going!" << endl;
							wordle_faces += "\n";
							for (int index = 0; index < 5; index++) {
								cout << plr2_guess.at(index);
								if (plr2_guess.at(index) == guess_wrd.at(index)) {
									cout << ": ^o^" << endl;
									wordle_faces += "^o^ ";
								} else if (guess_wrd.find(plr2_guess.at(index)) != string::npos) {
									cout << ": ^-^" << endl;
									wordle_faces += "^-^ ";
								} else {
									cout << ": @.@" << endl;
									wordle_faces += "@.@ ";
								}
							}
						}
						if (plr2_guess == guess_wrd) {
							cout << "You entered \"" << plr2_guess << "\". Congratulations, \"" << plr2_guess << "\" it is!" << endl;
							cout << "" << endl;
							friend_lvl += num_guesses;
							wordle_faces += "\n^o^ ^o^ ^o^ ^o^ ^o^";
							if (friend_lvl > MAX_FRND_LVL) {
								friend_lvl = MAX_FRND_LVL;
							}
							correct_guess = true;
						}
					}
				} while (correct_guess == false && num_guesses < MAX_GUESSES);
				break;
			case 3:
				printGameSummary(plr1_name, plr2_name, round_num, initial_friend_lvl, friend_lvl);
				break;
			case 4:
				shareWordle(plr1_name, plr2_name, round_num, num_guesses, wordle_faces);
				break;
			case 5:
				cont_playing = false;
				break;
		}
	}
	return 0;
}

void greet() {
	cout << "Welcome to Wordle For Friends!" << endl;
	cout << "<^.^>" << endl;
	cout << "" << endl;
	return;
}

string new_input(const string& message) {
	string str;
	cout << message << endl;
	cin >> str;
	return str;
}

bool integer_validation(const string& integer) {
	for (size_t i = 0; i < integer.length(); i++) {
		if (!isdigit(integer[i])) {
			return false;
		}
	}
	return true;
}

bool word_validation(const string& word) {
	if (word.length() != 5) {
		return false;
	}
	for (size_t i = 0; i < word.length(); i++) {
		if (!isalpha(word[i])) {
			return false;
		}
	}
	return true;
}

void printGameSummary(const string PLR1_NAME, const string PLR2_NAME, const int ROUNDS_PLAYED, const int INIT_FRIEND_LVL, int& current_friend_lvl) {
	if (current_friend_lvl < 20) {
		current_friend_lvl += 2;
	}
	cout << "" << endl;
	cout << "Game Summary" << endl;
	cout << "	Player 1: " << PLR1_NAME << endl;
	cout << "	Player 2: " << PLR2_NAME << endl;
	cout << "	Number of rounds played: " << ROUNDS_PLAYED << endl;
	cout << "	Initial friendship level: " << INIT_FRIEND_LVL << endl;
	cout << "	Current friendship: " << current_friend_lvl << endl;
	cout << "" << endl;
	return;
}

void shareWordle(const string PLR1_NAME, const string PLR2_NAME, const int LAST_RND_NUM, const int NUM_ATTEMPS, const string FACES) {
	cout << "" << endl;
	cout << "Wordle For Friends (" << PLR1_NAME << " and " << PLR2_NAME << ")" << endl;
	cout << FACES << endl;
	cout << "" << endl;
	cout << "Wordle Round " << LAST_RND_NUM << " " << NUM_ATTEMPS << "/6" << endl;
	cout << "This is your Wordle journey for the day to be shared!" << endl;
	cout << "" << endl;
	return;
}