#ifndef HW08DECK_H
#define HW08DECK_H

#include "hw08card.h"

using namespace std;

class Deck {
public:
	// Desc: Default constructor for the Deck class
	// Pre: None
	// Post: A deck standard 52 card deck is initialized
	Deck();
	// Desc: Parameterized constructor for the Deck class
	// Pre: a valid array of Cards to be input
	// Post: A Deck is initialized with the cards in the input array. All extra space is intialized as blank destroyed cards
	Deck(const Card CARDS[], const int LEN);

	// Desc: Shuffles the cards in the deck
	// Pre: None
	// Post: The cards of the deck are put into a random order
	void shuffle();

	// Desc: Checks if a card is destroyed
	// Pre: None
	// Post: Returns true if card is destroyed, else returns false
	bool isDestroyed(const int NUM);

	// Desc: Getter function for card at the requested position in deck array
	// Pre: None
	// Post: The card at the requested position in the deck array is returned
	Card getCard(const int NUM);

	// Desc: Sets a card at a specific value in the deck array
	// Pre: None
	// Post: The card in the requested position of the deck array is set to the function's card
	void setCard(const Card CARD, const int NUM);

	// Desc: Getter function for length of the deck array
	// Pre: None
	// Post: The numCards variable is returned
	int getLength() { return d_numCards; };

	// Desc: This function decrements the numCards variable
	// Pre: None
	// Post: The numCards variable is decreased by one
	void decrementNumCards();

private:
	Card d_deck[52];
	int d_numCards;
};

#endif