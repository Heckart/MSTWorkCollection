#ifndef HW08CARD_H
#define HW08CARD_H

#include <string>

using namespace std;

class Card {
public:
	// Desc: Default construtor for Card class
	// Pre: None
	// Post: class is intialized with unknown values
	Card();
	// Desc: Parameterized constructor for the Card class
	// Pre: Have a suitable string for card value and char for card suit
	// Post: Card is initialized as undestroyed and with the given values
	Card(const string VAL, const char SUIT);

	// Desc: This function checks if a card is destroyed
	// Pre: None
	// Post: returns true if card is destroyed, else returns false
	bool isDestoryed();

	// Desc: overloaded addition operator for the card class
	// Pre: None
	// Post: returns the value of the added cards. If sum is 11, both cards are destroyed
	int operator+(Card RHS);

	// Desc: Overloaded greater than operator for the card class
	// Pre: None
	// Post: Returns true if lhs is greater than rhs and they have different suits, this is reversed if they share a suit
	bool operator>(const Card RHS) const;

	// Desc: overloaded less than operator for the card class
	// Pre: None
	// Post: Returns true if lhs is less than rhs and they have different suits, this is reversed if they share a suit
	bool operator<(const Card RHS) const;

	// Desc: overloaded equal to operator for the card class
	// Pre: None
	// Post: returns true is lhs value is equal to rhs value, else returns false
	bool operator==(const Card RHS) const;

	// Desc: overloaded not equal to operator for the card class
	// Pre: None
	// Post: returns true is lhs value is not equal to rhs value, else returns false
	bool operator!=(const Card RHS) const;

	// Desc: overloaded tilde operator for the card class
	// Pre: None
	// Post: destroys the card being operated on
	void operator~();

	// Desc: overloaded insertion operator for the card class
	// Pre: None
	// Post: Outputs the value and suit of the card being operator on
	friend ostream& operator<<(ostream& os, const Card RHS);

private:
	string c_Val = "";
	char c_Suit = 'N';
	bool c_Destroyed = true;
};

#endif