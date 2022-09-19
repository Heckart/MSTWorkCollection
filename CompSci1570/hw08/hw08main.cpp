// Programmer: Ethan Heckart
// File: hw08main.cpp
// Date: 4/22/22
// Purpose: Main file for homework 8

#include <iostream>

#include "hw08deck.h"

using namespace std;

int main() {
	const int DECK_SIZE = 26;
	string plr1Name;
	string plr2Name;
	bool contPlaying = true;
	Deck defaultDeck;
	defaultDeck.shuffle();
	Card cardArrayOne[DECK_SIZE];
	Card cardArrayTwo[DECK_SIZE];

	srand(469);

	for (int i = 0; i < DECK_SIZE; i++) {  // populate first array
		cardArrayOne[i] = defaultDeck.getCard(i);
	}
	for (int i = 0; i < DECK_SIZE; i++) {  // populate second array
		cardArrayTwo[i] = defaultDeck.getCard(i + DECK_SIZE);
	}

	Deck plr1Hand(cardArrayOne, DECK_SIZE);
	Deck plr2Hand(cardArrayTwo, DECK_SIZE);

	cout << "This is war!" << endl;
	cout << "Input defender name:" << endl;
	cin >> plr1Name;
	cout << "Input attacker name:" << endl;
	cin >> plr2Name;
	cout << "\nBattle commence!\n" << endl;

	int i = -1;	 // index for plr1Hand
	int j = -1;	 // index for plr2Hand
	int q = 0;	 // index for adding stolen card
	const int MIN_HAND_SIZE = 11;

	do {  // the main loop of the game
		i++;
		j++;
		while (plr1Hand.isDestroyed(i)) {  // ensure plr1hand has valid card
			i++;
			if (i > plr1Hand.getLength()) {
				i = 0;
			}
		}
		while (plr2Hand.isDestroyed(j)) {  // ensure plr2hand has valid card
			j++;
			if (j > plr2Hand.getLength()) {
				j = 0;
			}
		}

		if (plr1Hand.getLength() < MIN_HAND_SIZE || plr2Hand.getLength() < MIN_HAND_SIZE) {	 // ending conditions for the game
			contPlaying = false;
		}

		if (plr1Hand.getCard(i) == plr2Hand.getCard(j)) {  // if cards have same val, both are destroyed
			cout << plr1Hand.getCard(i) << " " << plr2Hand.getCard(j) << " - "
				 << " destroyed" << endl;
			~plr1Hand.getCard(i);
			plr1Hand.decrementNumCards();
			~plr2Hand.getCard(j);
			plr2Hand.decrementNumCards();
		} else if ((plr1Hand.getCard(i) + plr2Hand.getCard(j)) == MIN_HAND_SIZE) {	// if cards val adds toMIN_HAND_SIZE, both are destroyed
			cout << plr1Hand.getCard(i) << " " << plr2Hand.getCard(j) << " - "
				 << " destroyed" << endl;
			~plr1Hand.getCard(i);
			plr1Hand.decrementNumCards();
			~plr2Hand.getCard(j);
			plr2Hand.decrementNumCards();
		} else if (plr1Hand.getCard(i) > plr2Hand.getCard(j)) {
			cout << plr1Hand.getCard(i) << " " << plr2Hand.getCard(j) << " - " << plr1Name << " wins" << endl;

			q = 0;								// index for the new card
			while (!plr1Hand.isDestroyed(q)) {	// ensure plr1hand index is destroyed card
				q++;
				if (q > 50) {
					q = 0;
				}
			}

			plr1Hand.setCard(plr2Hand.getCard(j), q);
			~plr2Hand.getCard(j);
			plr2Hand.decrementNumCards();
		} else if (plr2Hand.getCard(i) > plr1Hand.getCard(j)) {
			cout << plr1Hand.getCard(i) << " " << plr2Hand.getCard(j) << " - " << plr2Name << " wins" << endl;

			q = 0;								// index for the new card
			while (!plr2Hand.isDestroyed(q)) {	// ensure plr1hand index is destroyed card
				q++;
				if (q > 50) {
					q = 0;
				}
			}
			plr2Hand.setCard(plr1Hand.getCard(i), q);
			~plr1Hand.getCard(i);
			plr1Hand.decrementNumCards();
		}
	} while (contPlaying);

	cout << "\n-Game Over-" << endl;

	if (plr1Hand.getLength() < MIN_HAND_SIZE) {
		cout << "\nCongratulations " << plr2Name << ", you have won! Enjoy your new country!" << endl;
	}
	if (plr2Hand.getLength() < MIN_HAND_SIZE) {
		cout << "\nCongratualations " << plr1Name << ", you have won! You still rule your country!" << endl;
	}

	return 0;
}
