// Programmer: Ethan Heckart
// Date: 2/22/22
// File: LabFour.cpp
// Purpose: This file allows Normo to swap the soul values of two slimes

#include <iostream>

using namespace std;

// Desc: This function takes two values as input and swaps them
// Pre: None
// Post: The two input values are swapped and confirmation is printed to the console
template <typename T>
void trick(T& val1, T& val2) {
	const T TEMP = val1;
	cout << "" << endl;
	cout << "The soul values are " << val1 << " and " << val2 << endl;
	cout << "-Performing a trick-" << endl;
	val1 = val2;
	val2 = TEMP;
	cout << "The soul values are " << val1 << " and " << val2 << endl;
	cout << "" << endl;
	return;
}

int main() {
	int intSoulOne = 0, intSoulTwo = 0;
	string strSoulOne = "Null", strSoulTwo = "Null";
	bool blSoulOne = 0, blSoulTwo = 0;

	cout << "Give me two integer based slime souls" << endl;
	cin >> intSoulOne;
	cin >> intSoulTwo;
	trick(intSoulOne, intSoulTwo);	// Swap the interer based souls

	cout << "Give me two booleon based slime souls" << endl;
	cin >> blSoulOne;
	cin >> blSoulTwo;
	trick(blSoulOne, blSoulTwo);  // Swap the boolean based souls

	cout << "Give me two string based slime souls" << endl;
	cin >> strSoulOne;
	cin >> strSoulTwo;
	trick(strSoulOne, strSoulTwo);	// Swap the string based souls

	return 0;
}