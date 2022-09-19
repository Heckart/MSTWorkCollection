#include <iostream>

#include "hw08card.h"

using namespace std;

Card::Card() {}

Card::Card(const string VAL, const char SUIT) {
	c_Val = VAL;
	c_Suit = SUIT;
	c_Destroyed = false;
}

int Card::operator+(Card RHS) {
	int sum;

	if (c_Val == "J" || c_Val == "Q" || c_Val == "K" || c_Val == "A") {
		if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {
			sum = 20;
		} else {
			sum = 10 + stoi(RHS.c_Val);
		}
	} else if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {
		sum = 10 + stoi(c_Val);
	} else {
		sum = stoi(c_Val) + stoi(RHS.c_Val);
	}

	if (sum == 11) {
		c_Destroyed = true;
		RHS.c_Destroyed = true;
	}

	return sum;
}

bool Card::operator>(const Card RHS) const {
	if (c_Suit != RHS.c_Suit) {
		if (c_Val == "J" || c_Val == "Q" || c_Val == "K" || c_Val == "A") {
			if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {	 // both cards have a letter value & diff suit
				if (c_Val == "K" && (RHS.c_Val == "A" || RHS.c_Val == "Q" || RHS.c_Val == "J")) {
					return true;
				} else if (c_Val == "Q" && (RHS.c_Val == "A" || RHS.c_Val == "J")) {
					return true;
				} else if (c_Val == "J" && (RHS.c_Val == "A")) {
					return true;
				} else {
					return false;
				}
			}
			if (RHS.c_Val != "J" && RHS.c_Val != "Q" && RHS.c_Val != "K") {	 // only LHS has letter value & diff suit
				if (c_Val != "A") {
					return true;
				} else {
					return false;
				}
			}
		} else if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {	// only RHS has letter value & diff suit
			if (RHS.c_Val != "A") {
				return false;
			} else {
				return true;
			}
		} else {  // boths cards have number value & diff suit
			if (stoi(c_Val) > stoi(RHS.c_Val)) {
				return true;
			} else {
				return false;
			}
		}
	} else if (c_Suit == RHS.c_Suit) {
		if (c_Val == "J" || c_Val == "Q" || c_Val == "K" || c_Val == "A") {
			if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {	 // both cards have a letter value & same suit
				if (c_Val == "K" && (RHS.c_Val == "A" || RHS.c_Val == "Q" || RHS.c_Val == "J")) {
					return false;
				} else if (c_Val == "Q" && (RHS.c_Val == "A" || RHS.c_Val == "J")) {
					return false;
				} else if (c_Val == "J" && (RHS.c_Val == "A")) {
					return false;
				} else {
					return true;
				}
			}
			if (RHS.c_Val != "J" && RHS.c_Val != "Q" && RHS.c_Val != "K") {	 // only LHS has letter value & same suit
				if (c_Val != "A") {
					return false;
				} else {
					return true;
				}
			}
		} else if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {	// only RHS has letter value & same suit
			if (RHS.c_Val != "A") {
				return true;
			} else {
				return false;
			}
		} else {  // boths cards have number value & same suit
			if (stoi(c_Val) < stoi(RHS.c_Val)) {
				return true;
			} else {
				return false;
			}
		}
	}
	return false;  // this should never execute
}

bool Card::operator<(const Card RHS) const {
	if (c_Suit != RHS.c_Suit) {
		if (c_Val == "J" || c_Val == "Q" || c_Val == "K" || c_Val == "A") {
			if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {	 // both cards have a letter value & diff suit
				if (c_Val == "K" && (RHS.c_Val == "A" || RHS.c_Val == "Q" || RHS.c_Val == "J")) {
					return false;
				} else if (c_Val == "Q" && (RHS.c_Val == "A" || RHS.c_Val == "J")) {
					return false;
				} else if (c_Val == "J" && (RHS.c_Val == "A")) {
					return false;
				} else {
					return true;
				}
			}
			if (RHS.c_Val != "J" && RHS.c_Val != "Q" && RHS.c_Val != "K") {	 // only LHS has letter value & diff suit
				if (c_Val != "A") {
					return false;
				} else {
					return true;
				}
			}
		} else if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {	// only RHS has letter value & diff suit
			if (RHS.c_Val != "A") {
				return true;
			} else {
				return false;
			}
		} else {  // boths cards have number value & diff suit
			if (stoi(c_Val) > stoi(RHS.c_Val)) {
				return false;
			} else {
				return true;
			}
		}
	} else if (c_Suit == RHS.c_Suit) {
		if (c_Val == "J" || c_Val == "Q" || c_Val == "K" || c_Val == "A") {
			if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {	 // both cards have a letter value & same suit
				if (c_Val == "K" && (RHS.c_Val == "A" || RHS.c_Val == "Q" || RHS.c_Val == "J")) {
					return true;
				} else if (c_Val == "Q" && (RHS.c_Val == "A" || RHS.c_Val == "J")) {
					return true;
				} else if (c_Val == "J" && (RHS.c_Val == "A")) {
					return true;
				} else {
					return false;
				}
			}
			if (RHS.c_Val != "J" && RHS.c_Val != "Q" && RHS.c_Val != "K") {	 // only LHS has letter value & same suit
				if (c_Val != "A") {
					return true;
				} else {
					return false;
				}
			}
		} else if (RHS.c_Val == "J" || RHS.c_Val == "Q" || RHS.c_Val == "K" || RHS.c_Val == "A") {	// only RHS has letter value & same suit
			if (RHS.c_Val != "A") {
				return false;
			} else {
				return true;
			}
		} else {  // boths cards have number value & same suit
			if (stoi(c_Val) < stoi(RHS.c_Val)) {
				return false;
			} else {
				return true;
			}
		}
	}
	return false;  // this should never execute
}

bool Card::operator==(const Card RHS) const {
	if (c_Val == RHS.c_Val) {
		return true;
	}
	return false;
}

bool Card::operator!=(const Card RHS) const {
	if (c_Val != RHS.c_Val) {
		return true;
	}
	return false;
}

void Card::operator~() { c_Destroyed = true; }

ostream& operator<<(ostream& os, const Card RHS) {
	os << RHS.c_Val << RHS.c_Suit;
	return os;
}

bool Card::isDestoryed() {
	if (c_Destroyed == true) {
		return true;
	}
	return false;
}