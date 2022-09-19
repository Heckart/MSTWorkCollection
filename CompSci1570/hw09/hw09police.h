#ifndef HW09POLICE_H
#define HW09POLICE_H
#include "hw09city.h"
#include "hw09jewel.h"
#include "hw09robber.h"

using namespace std;

class Police {
public:
	// Desc: Default constructor for the Police class
	// Pre: None
	// Post: A Police is initialized with unknown values
	Police();
	// Desc: Parameterized constructor for the Police class
	// Pre: None
	// POst: A police is intialized with a unique ID and is placed on a free location of the city map
	Police(City& city);

	// Desc: This function arrests a robber and confiscates loot
	// Pre: The police must share a spot on the map with a robber
	// Post: The robber is deactivated, his loot is stolen, and the LootVal variable is updated
	void arrest(Robber<Jewel>& robber, City& city);

	// Desc: This function is used by the police to move around the map
	// Pre: None
	// Post: The police randomly moves to a new valid position on the map
	void move(City& city);

	// Desc: Getter function for the XCoordinate variable
	// Pre: None
	// Post: XCoordinate variable is returned
	int getXCoord() const;

	// Desc: Getter function for the YCoordinate variable
	// Pre: None
	// Post: YCoordinate variable is returned
	int getYCoord() const;

	// Desc: Getter function for the LootVal variable
	// Pre: None
	// Post: LootVal variable is returned
	int getLootVal() const;

	// Desc: Getter function for the RobbersCaught variable
	// Pre: None
	// Post: RobbersCaught variable is returned
	int getRobbersCaught() const;

	// Desc: Getter function for the ID variable
	// Pre: None
	// Post: ID variable is returned
	int getID() const;

	// Desc: This function increases the LootVal variable
	// Pre: None
	// Post: The LootVal variable is increased by the input
	void addLootVal(const int input);

private:
	static int pNumPolice;
	int p_ID;
	int p_XCoordinate;
	int p_YCoordinate;
	int p_RobbersCaught = 0;
	int p_LootVal;
};

#endif