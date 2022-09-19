#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hw07region.h"

using namespace std;

void Region::initRegion(char arr[][4], const int ROW, const int COL) {
	int random;
	const int MAX = 100;
	const int MIN = 1;
	const int TWENTYONE = 21;
	const int TWENTYTWO = 22;
	const int FIFTYEIGHT = 58;

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			random = (rand() % (MAX - MIN + MIN)) + MIN;
			if (random <= TWENTYONE) {	// 21% chance dander
				arr[i][j] = 'A';
			} else if (random <= FIFTYEIGHT && random >= TWENTYTWO) {  // 37% chance dust
				arr[i][j] = 'D';
			} else {  // 42% chance pollen
				arr[i][j] = 'P';
			}
		}
	}
}