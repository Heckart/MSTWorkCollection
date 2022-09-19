#ifndef HW09JEWEL_H
#define HW09JEWEL_H

#include "hw09city.h"

using namespace std;

class Jewel {
public:
	// Desc: Default constructor for the Jewel class
	// Pre: None
	// Post: A Jewel is initializd with unknown values
	Jewel(){};
	// Desc: Parameterized constructor for the Jewel class
	// Pre: None
	// Post: A Jewel is intialized, is placed in an empty spot in the city's map array, and is given a value
	Jewel(City& city);

	// Desc: Getter function for inPlay variable
	// Pre: None
	// Post: The value of the inPlay function is returned
	bool getInPlay() const;

	// Desc: Getter function for the XCoordinate variable
	// Pre: None
	// Post: The value of the XCorodinate variable is returned
	int getXCoord() const;

	// Desc: Getter function for the YCoordinate variable
	// Pre: None
	// Post: The value of the XCoordinate variable is returned
	int getYCoord() const;

	// Desc: Getter function for the Value variable
	// Pre: None
	// Post: The value of the Value variable is returned
	int getValue() const;

	// Desc: This function will change the inPlay variable to false
	// Pre: None
	// Post: The inPlay variable is set to false
	void deactivate();

	// Desc: This function will change the inPlay variable to true
	// Pre: None
	// Post: The inPlay variable is set to true
	void activate();

	// Desc: Setter function for XCoordinate variable
	// Pre: input is in [0,9]
	// Post: The XCoordinate variable is changed to the input
	void setXCoord(const int input);

	// Desc: Setter function for YCoordinate variable
	// Pre: input is in [0,9]
	// Post: The YCoordinate variable is changed to the input
	void setYCoord(const int input);

private:
	int j_Value;
	int j_XCoordinate;
	int j_YCoordinate;
	bool j_inPlay = true;
};

#endif