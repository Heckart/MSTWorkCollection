#ifndef HW07REGION_H
#define HW07REGION_H

#include <string>

using namespace std;

class Region {
public:
	// Desc: The default constructor for the region class
	// Pre: None
	// Post: region class is intialized with unknown values
	Region() {}
	// Desc: Parameterized constructor for the region class
	// Pre: None
	// Post: region is initialized with the name given to the constructor and the map is filled
	Region(const string name) {
		r_Name = name;
		initRegion(m_Area, 10, 4);
	};

	// Desc: This fuction initializes the region array
	// Pre: None
	// Post: 10x4 array is intialized with random values
	void initRegion(char arr[][4], const int ROW, const int COL);

	// Desc: Getter function for character at a point in the region array
	// Pre: None
	// Post: The character at the requested position in the map array is returned
	char getCoord(const int ROW, const int COL) const { return m_Area[ROW][COL]; };

	// Desc: Getter function for name variable
	// Pre: None
	// Post: The name variable is returned
	string getName() const { return r_Name; };

private:
	char m_Area[10][4];
	string r_Name;
};

#endif