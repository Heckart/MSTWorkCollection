// Programmer: Ethan Heckart
// Date: 3/20/22
// File: hw06main.cpp
// Purpose: Main file for homework 6

#include <fstream>
#include <iostream>

#include "hw06header.h"

using namespace std;

int main() {
	const int COLUMN = 10, ROW = 10;
	char worldArray[COLUMN][ROW];
	const string INPUTFILE = "input.txt";
	const string OUTPUTFILE = "output.txt";
	int p1 = 0;
	int p2 = 0;
	ifstream fin;
	ofstream fout;

	fin.open(INPUTFILE.c_str());

	for (int i = 0; i < ROW; i++) {	 // assign input to 2d array
		for (int j = 0; j < COLUMN; j++) {
			fin >> worldArray[i][j];
		}
	}

	while (fin >> p1) {	 // Perform the Bee airdrop at the desired point
		fin >> p2;
		airdropBees(worldArray, p1, p2);
	}

	fin.close();

	fout.open(OUTPUTFILE.c_str());

	for (int i = 0; i < ROW; i++) {	 // assign 2d array to output
		for (int j = 0; j < COLUMN; j++) {
			fout << worldArray[i][j];
		}
		fout << endl;
	}

	fout.close();

	return 0;
}