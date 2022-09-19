#ifndef HW09ROBBER_H
#define HW09ROBBER_H

#include "hw09city.h"

using namespace std;

template <class T>
class Robber {
public:
	// Desc: Deafult constructor for the Robber class
	// Pre: None
	// Post: A robber is initialized with unknown values
	Robber();
	// Desc: Parameterized constructor for the Robber class
	// Pre: None
	// Post: A robber is intialized and places in a free spot of the city array
	Robber(City& city, const bool greedy);

	// Desc: This function grabs loot from the city array and puts it into the bag array
	// Pre: The robber must be standing on a tile with loot and the bag must not be full
	// Post: The loot is put into the bag and loot totals are updated
	void pickUpLoot(T arr[], const int len);

	// Desc: This function is used by the robber to move around the map
	// Pre: None
	// Post: The robber randomly moves to a new valid position on the map
	void move(City& city);

	// Desc: Getter function for XCoordinate variable
	// Pre: None
	// Post: XCoordinate variable is returned
	int getXCoord() const;

	// Desc: Getter function for YCoordinate variable
	// Pre: None
	// Post: YCoordinate variable is returned
	int getYCoord() const;

	// Desc: Getter function for MostRecentStolenVal
	// Pre: None
	// Post: MostRecentStolenVal is returned
	int getMostRecentStolenVal() const;

	// Desc: Getter function for NumStolen variable
	// Pre: None
	// Post: NumStolen variable is returned
	int getNumStolen() const;

	// Desc: Getter function for ValStolen variable
	// Pre: None
	// Post: ValStolen variable is returned
	int getVal() const;

	// Desc: Getter function for TotalValStolen variable
	// Pre: None
	// Post: TotalValStolen variable is returned
	int getTotalVal() const;

	// Desc: Getter function for ID variable
	// Pre: None
	// Post: ID variable is returned
	int getID() const;

	// Desc: This function deactivates the jewel at the specified location in the robber's bag
	// Pre: Index must be in [0,16]
	// Post: Th jewel at the index is deactivated and the corresponding value adjustments are made
	void deactivateBag(const int index);

	// Desc: Setter function for the ValStolen variable
	// Pre: None
	// Post: ValStolen is changed to the input
	void setVal(const int input);

	// Desc: This function incremets the NumStolen variable
	// Pre: None
	// Post: NumStolen is increased by one
	void incrementNumStolen();

	// Desc: This function decrements the NumStolen variable
	// Pre: None
	// Post: NumStolen is decreased by one
	void decrementNumStolen();

	// Desc: This function sets the NumStolen variable to 0
	// Pre: None
	// Post: NumStolen is set to 0
	void zeroStolen();

	// Desc: This function deactives the robber
	// Pre: None
	// Post: the Active variable is set to false
	void deactivateRobber();

	// Desc: This function decreases the TotalValStolen staic variable
	// Pre: None
	// Post: The TotalValStolen variable is decreased by the input
	void decreaseTotalVal(const int input);

	// Desc: Getter function for the IsGreedy variable
	// Pre: None
	// Post: IsGreedy variable is returned
	bool isGreedy() const;

	// Desc: This function returns the jewel stored at an index in the bag array
	// Pre: The input is in [0,16]
	// Post: The object stored at the requested index in the array is returned
	T returnBag(const int index);

	// Desc: Getter function for the Active variable
	// Pre: None
	// Post: The value of the active variable is returned
	bool getActive() const;

private:
	static int rTotalValStolen;
	static int rTotalNumRobbers;
	int r_NumStolen = 0;
	int r_ValStolen = 0;
	int r_MostRecentStolenVal;	// this is required for a greedy robber to determine if he gets to move again
	int r_ID;
	int r_XCoordinate;
	int r_YCoordinate;
	T r_Bag[17];
	bool r_Active = true;
	bool r_IsGreedy;
};

#include "hw09robberfunct.hpp"
#endif