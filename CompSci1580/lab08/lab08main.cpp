// Programmer: Ethan Heckart
// File: lab08main.cpp
// Date: 3/21/22
// Purpose: Help "Normo" get a new identity

#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream fin;
	ofstream fout;
	const string OUTPUTFILE = "output.txt";
	string inputFile;
	string inputLines;
	string data;  // the type of value from the input file
	string val;	  // the number/name of the type
	string normoName = "Normo";
	string normoClass = "accountant";
	string normoLevel = "0";

	cout << "What is the name of the input file?" << endl;
	cin >> inputFile;
	fin.open(inputFile.c_str());

	while (!fin) {	// file input validation
		cout << endl;
		cout << "File not found." << endl;
		cout << "What is the name of the input file?" << endl;
		cin >> inputFile;
		fin.open(inputFile.c_str());
	}

	cout << "File stream successfully connected" << endl;

	if (fin.is_open()) {  // assign the number of input lines
		for (size_t i = 0; i < 1; i++) {
			getline(fin, inputLines);
		}
	}

	if (fin.is_open()) {  // read file and assign appropriate vales to "Normo"
		for (int i = 0; i <= stoi(inputLines); i++) {
			while (getline(fin, data, ' ')) {
				getline(fin, val);
				if (data == "name") {  // new name
					normoName = val;
				} else if (data == "class") {  // new class
					normoClass = val;
				} else if (data == "level") {  // new level
					normoLevel = val;
				}
			}
		}
	}

	fin.close();

	fout.open(OUTPUTFILE.c_str());

	fout << normoName << "'s final attricutes:" << endl;
	fout << endl;
	fout << "Name - " << normoName << endl;
	fout << "Class - " << normoClass << endl;
	fout << "Level - " << normoLevel;

	fout.close();

	return 0;
}