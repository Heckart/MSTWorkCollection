#include <iostream>

#include "hw09header.h"

using namespace std;

void printArray(const City city, const int x, const int y) {
	cout << "+---+---+---+---+---+---+---+---+---+---+\n";	// divider between rows
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (j == 0) {
				cout << "| ";  // divider between tiles
			}

			cout << city.getCityMap(i, j);
			if (j < y) {
				cout << " | ";
			}
		}
		cout << "\n+---+---+---+---+---+---+---+---+---+---+";
		cout << endl;
	}

	return;
}