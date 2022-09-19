#ifndef LAB11MAGICSMASHER_H
#define LAB11MAGICSMASHER_H

using namespace std;

template <class T>
class MagicSmasher {
public:
	// Desc: Default constructor for MagicSmasher class
	// Pre: None
	// Post: MagicSmasher object is initialized with unknown values
	MagicSmasher(){};
	// Desc: Parameterized constructor for MagicSmasher class
	// Pre: Both inputs are of the same type
	// Post: MagicSmasher object is initialized with the inputs
	MagicSmasher(T inputOne, T inputTwo) {
		varOne = inputOne;
		varTwo = inputTwo;
	};

	// Desc: Returns a sum of the two variables
	// Pre: Both variables are of the same type
	// Post: The sum of the two objects is returned
	T sum() { return varOne + varTwo; };

private:
	T varOne;
	T varTwo;
};

#endif