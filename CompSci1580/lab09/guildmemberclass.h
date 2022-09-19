#ifndef GUILDMEMBERCLASS_H
#define GUILDMEMBERCLASS_H

#include <string>

using namespace std;

class GuildMember {
public:
	// Desc: This function returns the name of the member
	// Pre: None
	// Post: The member's name is returned to the calling object
	void getName() const;

	// Desc: This function returns the age of the member
	// Pre: None
	// Post: The member's age is returned to the calling object
	void getAge() const;

	// Desc: This function sets the value of the member name
	// Pre: None
	// Post: The member name of the calling object is set to the input
	void setName(const string input);

	// Desc: This function sets the value of the member age
	// Pre: None
	// Post: The member age of the calling object is set to the input
	void setAge(const int input);

	// Desc: This function sets the value of the member level
	// Pre: None
	// Post: The member level of the calling object is set to the input
	void setLevel(const int input);

	// Desc: This function sets the value of the member class
	// Pre: None
	// Post: The member class of the calling object is set to the input
	void setClass(const string input);

	// Desc: This function calls the private age() function
	// Pre: None
	// Post: The member age of the calling object is increased by one
	void passTime();

	// Desc: This function prints all of the variable values of the calling object
	// Pre: None
	// Post: The calling object's class values are printed to the terminal
	void print() const;

private:
	string m_name;
	string m_class;
	int m_lvl;
	int m_age;

	// Desc: This function increments the member's age
	// Pre: None
	// Post: The member age of the calling object is increased by one
	void age();
};

#endif