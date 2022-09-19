#ifndef HW07MAPMAKER_H
#define HW07MAPMAKER_H

#include <iostream>

#include "hw07region.h"

using namespace std;

class Mapmaker {
public:
	// Desc: defualt constructor for mapmaker class
	// Pre: None
	// Post: name is input to the console and map is intialized
	Mapmaker() {
		cout << "Please enter the name for the first mapmaker." << endl;
		cin >> r_Name;
		initMap(10, 4);
	}
	// Desc: parameterized constructor for mapmaker class
	// Pre: None
	// Post: name entered to the constructor is given to the mapmaker and the map is initialized
	Mapmaker(const string name) {
		r_Name = name;
		initMap(10, 4);
	};

	// Desc: This fuction initializes the map array
	// Pre: None
	// Post: 10x4 array is intialized with all spaces being 'U'
	void initMap(const int ROW, const int COL);

	// Desc: This function determines if unexplored areas remaining
	// Pre: None
	// Post: Number of unexplored areas are counted, and a message is printed the terminal. Returns false is there are no more unexplored areas
	void checkMap(const int ROW, const int COL);

	// Desc: This function explores a spot in the region map
	// Pre: None
	// Post: Updates random mapmaker map coordinate to match region map coordinate
	void exploreMap(Region region);

	// Desc: Getter function for name variable
	// Pre: None
	// Post: The name variable is returned
	string getName() const { return r_Name; };

	// Desc: Getter function for mapExplored variable
	// Pre: None
	// Post: The mapExplored variable is returned
	bool getMapExplored() const { return r_mapExplored; };

	// Desc: Getter function for character at a point in the map array
	// Pre: None
	// Post: The character at the requested position in the map array is returned
	char getMCoord(const int ROW, const int COL) const { return r_Map[ROW][COL]; };

	// Desc: Getter function for the numExolored variable
	// Pre: None
	// Post: The numExplored function is returned
	int getNumExplored() const { return r_numExplored; };

	// Desc: Getter function for the RPSWins variable
	// Pre: None
	// Post: The RPSWins variable is returned
	int getRPSWins() const { return r_RPSWins; };

	// Desc: This function plays rock paper scissors between two members of the mapmaker class
	// Pre: None
	// Post: Rock paper scissors is played, the winner is printed to terminal, and the winner variable is updated
	friend void playRPS(Mapmaker& mapmaker1, Mapmaker& mapmaker2);

private:
	bool r_mapExplored = false;
	string r_Name;
	char r_Map[10][4];
	int r_RPSWins = 0;
	int r_numExplored = 0;
};

#endif