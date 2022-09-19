#include <cstdlib>
#include <iostream>

#include "hw08deck.h"

using namespace std;

Deck::Deck() {
	d_deck[0] = Card("2", 'H');
	d_deck[1] = Card("3", 'H');
	d_deck[2] = Card("4", 'H');
	d_deck[3] = Card("5", 'H');
	d_deck[4] = Card("6", 'H');
	d_deck[5] = Card("7", 'H');
	d_deck[6] = Card("8", 'H');
	d_deck[7] = Card("9", 'H');
	d_deck[8] = Card("10", 'H');
	d_deck[9] = Card("J", 'H');
	d_deck[10] = Card("Q", 'H');
	d_deck[11] = Card("K", 'H');
	d_deck[12] = Card("A", 'H');
	d_deck[13] = Card("2", 'C');
	d_deck[14] = Card("3", 'C');
	d_deck[15] = Card("4", 'C');
	d_deck[16] = Card("5", 'C');
	d_deck[17] = Card("6", 'C');
	d_deck[18] = Card("7", 'C');
	d_deck[19] = Card("8", 'C');
	d_deck[20] = Card("9", 'C');
	d_deck[21] = Card("10", 'C');
	d_deck[22] = Card("J", 'C');
	d_deck[23] = Card("Q", 'C');
	d_deck[24] = Card("K", 'C');
	d_deck[25] = Card("A", 'C');
	d_deck[26] = Card("2", 'S');
	d_deck[27] = Card("3", 'S');
	d_deck[28] = Card("4", 'S');
	d_deck[29] = Card("5", 'S');
	d_deck[30] = Card("6", 'S');
	d_deck[31] = Card("7", 'S');
	d_deck[32] = Card("8", 'S');
	d_deck[33] = Card("9", 'S');
	d_deck[34] = Card("10", 'S');
	d_deck[35] = Card("J", 'S');
	d_deck[36] = Card("Q", 'S');
	d_deck[37] = Card("K", 'S');
	d_deck[38] = Card("A", 'S');
	d_deck[39] = Card("2", 'D');
	d_deck[40] = Card("3", 'D');
	d_deck[41] = Card("4", 'D');
	d_deck[42] = Card("5", 'D');
	d_deck[43] = Card("6", 'D');
	d_deck[44] = Card("7", 'D');
	d_deck[45] = Card("8", 'D');
	d_deck[46] = Card("9", 'D');
	d_deck[47] = Card("10", 'D');
	d_deck[48] = Card("J", 'D');
	d_deck[49] = Card("Q", 'D');
	d_deck[50] = Card("K", 'D');
	d_deck[51] = Card("A", 'D');
	d_numCards = 52;
}

Deck::Deck(const Card CARDS[], const int LEN) {
	Card destoryedCard;
	~destoryedCard;

	for (int i = 0; i < LEN; i++) {
		d_deck[i] = CARDS[i];
	}
	d_numCards = LEN;

	if (LEN < 52) {	 // fill the rest of the array with blank destroyed cards
		for (int i = LEN; i < 52; i++) {
			d_deck[i] = destoryedCard;
		}
	}
}

void Deck::shuffle() {
	const int MAX_DECK = 51;
	for (int i = 0; i < 10000; i++) {
		const int RANDNUMONE = rand() % (MAX_DECK + 1);
		const int RANDNUMTWO = rand() % (MAX_DECK + 1);

		Card tempCard = d_deck[RANDNUMTWO];

		d_deck[RANDNUMTWO] = d_deck[RANDNUMONE];
		d_deck[RANDNUMONE] = tempCard;
	}

	return;
}

Card Deck::getCard(const int NUM) { return d_deck[NUM]; }

bool Deck::isDestroyed(const int NUM) {
	Card card = getCard(NUM);
	if (card.isDestoryed()) {
		return true;
	} else {
		return false;
	}
}

void Deck::decrementNumCards() {
	d_numCards--;
	return;
}

void Deck::setCard(const Card CARD, const int NUM) { d_deck[NUM] = CARD; }