// Programmer: Ethan Heckart
// File: fishbomb.cpp
// Date: 9/28/22
// Purpose: Help Bender catch the most fish

#include <iostream>

using namespace std;

int main() {
	int height = 0;
	int width = 0;
	int input = 0;
	int testCases = 0;	 // Used to know when to exit the do-while loop. Will decrement after completion of each loop.
	int highSum = 0;	 // The highest total sum measured.
	int currentSum = 0;	 // The current sum in the loop. Will be compared with the highSum and potentially replace it.
	int optimalX = 0;	 // X coordinate of the highSum location.
	int optimalY = 0;	 // Y coordinate of the highSum location.
	int turnNum = 0;

	int** grid;

	cin >> testCases;

	do {
		highSum = 0;
		currentSum = 0;
		cin >> height;
		cin >> width;

		grid = new int*[height];

		for (int i = 0; i < height; i++) {	// create the rows of the dynamic array
			grid[i] = new int[width];
		}

		for (int i = 0; i < height; i++) {	// populate the dynamic array
			for (int j = 0; j < width; j++) {
				cin >> input;
				grid[i][j] = input;
			}
		}

		// Algorithm to detect the optimal place for the bomb
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				currentSum = 0;
				for (int k = 0; k < width; k++) {
					currentSum += grid[i][k];
				}
				for (int l = 0; l < height; l++) {
					currentSum += grid[l][j];
				}
				currentSum -= grid[i][j];  // ensure the starting position isn't double counted.

				if (currentSum > highSum) {
					highSum = currentSum;
					optimalX = i;
					optimalY = j;
				}
			}
		}

		cout << "#" << turnNum << ": at (" << optimalX << "," << optimalY << ") Bender catches " << highSum << " fish." << endl;

		for (int i = 0; i < height; i++) {	// deallocate the dynamic array
			delete[] grid[i];
			grid[i] = NULL;
		}
		delete[] grid;
		grid = NULL;

		testCases--;
		turnNum++;

	} while (testCases > 0);

	return 0;
}