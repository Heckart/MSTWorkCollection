#ifndef LAB10GUILDMEMBER_H
#define LAB10GUILDMEMBER_H
#include <string>

using namespace std;

class GuildMember {
public:
	// Desc: Default constructor for guildmember class
	// Pre: None
	// Post: Name is initialized to "Nobody" and all other stats to 0
	GuildMember();
	// Desc: first parameterized constructor for guildmember class
	// Pre: None
	// Post: Name is intitialized to the entered string and all other stats to 0
	GuildMember(const string NAME);
	// Desc: second parameterized constructor for the guildmember class
	// Pre: None
	// Post: Name is initialized to the entered names and stats are initialized based on the ints in the array
	GuildMember(const string NAME, const int STATS[], const int LEN);

	// Desc: overloaded addition operator for adding guildmember classes
	// Pre: None
	// Post: a new guildmember is returned with a concatenated name and added stats
	GuildMember operator+(const GuildMember rhs) const;

	// Desc: overloaded [] operator for returing a stat of a guild member
	// Pre: integer entered is in [0,4]
	// Post: 0=strength, 1=wisdom, 2=dexterity, 3=charisma, 4=intelligence, all others = 0
	void operator[](const int INPUT) const;

	// Desc: overloaded output stream operator to print a guildmember to the terminal
	// Pre: None
	// Post: Name and stats of the guildmember are printed to the terminal
	friend ostream& operator<<(ostream& os, const GuildMember& rhs);

private:
	string m_Name;
	int m_Strength, m_Wisdom, m_Dexterity, m_Charisma, m_Intelligence;
};

#endif