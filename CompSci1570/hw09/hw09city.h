#ifndef HW09CITY_H
#define HW09CITY_H

using namespace std;

class City {
public:
	// Desc: Default constructor for City class
	// Pre: None
	// Post: A 10x10 character array is initialized with all spaces being ' ' for empty
	City();

	// Desc: This function increments the number of Jewels variable
	// Pre: None
	// Post: c_NumJewels is increased by one
	void addNumJewels();

	// Desc: This function decrements the number of Jewels variable
	// Pre: None
	// Post: c_NumJewels is decreased by one
	void decrementJewels();

	// Desc: This function updates the city map array at a specfic coordinate
	// Pre: The coordinates must be in the 10x10 array
	// Post: The c_CityMap array is updated at the specific coordinates
	void setCityMap(const int xCoord, const int yCoord, const char input);

	// Desc: This function returns the value at a location on the city map
	// Pre: The coordinates must be in the 10x10 array
	// Post: The c_CityMap character array at the coordinate is returned
	char getCityMap(const int xCoord, const int yCoord) const;

	// Desc: This function returns the value of the Jewels variable
	// Pre: None
	// Post: The value of c_NumJewels is returned
	int getNumJewels() const;

private:
	char c_CityMap[10][10];
	int c_NumJewels;
};

#endif