// Programmer: Ethan Heckart
// Date: 2/15/22
// Purpose: This file contains the code to helo Normo kill slimes in the slime fields

#include <iostream>

using namespace std;

// Desc: This function outputs a greeting to the terminal at the start of the program
// Pre: None
// Post: A greeting is displayed to the screen
void greet();

// Desc: This function will perform a slice attack
// Pre: None
// Post: If attackval >= 10 the slime will die, else Normo will lose one health
void slice(int attackval, int& experience, int& healthval, bool& cont);

// Desc: This function performs a spin attack
// Pre: None
// Post: If attackval >=15 10 slimes will die, else Normo will lose one health
void spin(int attackval, int& experience, int& healthval, bool& cont);

// Desc: This function swaps health and attack vals
// Pre: None
// Post: Attack and health values are swapped
void trick(int& attackval, int experience, int& healthval, bool& cont);

// Desc: This funciton leaves the slimefield
// Pre: None
// Post: The game ends and a summary is output
void leave(int attackval, int experience, int healthval);

int main() {
	int attack_val = 0;	 // Normo's attack
	int health_val = 0;	 // Normo's health
	int exp = 0;		 // Normo's experience
	bool cont = true;	 // If true, Normo has more than 0 health and the loop continues
	string menu_val;	 // Menu input

	cout << "What is your attack?" << endl;
	cin >> attack_val;
	cout << "What is your health?" << endl;
	cin >> health_val;

	while (cont) {	// Main loop for the menu
		cout << "what will you do" << endl;
		cout << "1. Slice" << endl;
		cout << "2. Spin" << endl;
		cout << "3. Trick" << endl;
		cout << "4. Leave" << endl;
		cin >> menu_val;
		if (menu_val == "Slice") {
			slice(attack_val, exp, health_val, cont);
		}
		if (menu_val == "Spin") {
			spin(attack_val, exp, health_val, cont);
		}
		if (menu_val == "Trick") {
			trick(attack_val, exp, health_val, cont);
		}
		if (menu_val == "Leave") {
			leave(attack_val, exp, health_val);
			cont = false;  // ends the loop
		}
	}
	return 0;
}

void greet() {
	cout << "Welcome to the Slime Fields, Normo!" << endl;
	return;
}

void slice(int attackval, int& experience, int& healthval, bool& cont) {
	if (attackval >= 10) {
		experience++;
		cout << "Killed 1 slime. Gained 1 xp." << endl;
	} else {
		healthval = healthval - 1;
		cout << "Your attack was to low" << endl;
		cout << "Killed 0 slime. Lost 1 health" << endl;
		if (healthval <= 0) {  // Output if Normo dies from the slice attack
			cout << "You have died." << endl;
			cout << "Normo:" << endl;
			cout << "Attack - " << attackval << endl;
			cout << "Health - 0" << endl;
			cout << "Exp - " << experience << endl;
			cont = false;
		}
	}
	return;
}

void spin(int attackval, int& experience, int& healthval, bool& cont) {
	if (attackval >= 15) {
		cout << "Killed 10 slime." << endl;
		experience = experience + 10;
	} else {
		cout << "Your attack was to low." << endl;
		cout << "Killed 0 slime. Lost 1 health" << endl;
		healthval = healthval - 10;
		if (healthval <= 0) {  // Output if Normo dies from the spin attack
			cout << "You have died." << endl;
			cout << "Normo:" << endl;
			cout << "Attack - " << attackval << endl;
			cout << "Health - 0" << endl;
			cout << "Exp - " << experience << endl;
			cont = false;
		}
	}
	return;
}

void trick(int& attackval, int experience, int& healthval, bool& cont) {
	int temp = 0;

	temp = healthval;
	healthval = attackval;
	attackval = temp;
	cout << "Attack is now " << attackval << ", Health is now " << healthval << endl;
	if (healthval <= 0) {  // Output if Normo dies from the trick
		cout << "You have died." << endl;
		cout << "Normo:" << endl;
		cout << "Attack - " << attackval << endl;
		cout << "Health - 0" << endl;
		cout << "Exp - " << experience << endl;
		cont = false;
	}
	return;
}

void leave(int attackval, int experience, int healthval) {
	cout << "You have left." << endl;
	cout << "Normo:" << endl;
	cout << "Attack - " << attackval << endl;
	cout << "Health - " << healthval << endl;
	cout << "Exp - " << experience << endl;
	return;
}