#include <iostream>

#include "lab10guildmember.h"

using namespace std;

GuildMember::GuildMember() {
	m_Name = "Nobody";
	m_Strength = 0;
	m_Charisma = 0;
	m_Dexterity = 0;
	m_Intelligence = 0;
	m_Wisdom = 0;
}

GuildMember::GuildMember(const string NAME) {
	m_Name = NAME;
	m_Strength = 0;
	m_Charisma = 0;
	m_Dexterity = 0;
	m_Intelligence = 0;
	m_Wisdom = 0;
}

GuildMember::GuildMember(const string NAME, const int STATS[], const int LEN) {
	m_Name = NAME;
	m_Strength = STATS[LEN - 5];
	m_Wisdom = STATS[LEN - 4];
	m_Dexterity = STATS[LEN - 3];
	m_Charisma = STATS[LEN - 2];
	m_Intelligence = STATS[LEN - 1];
}

GuildMember GuildMember::operator+(const GuildMember rhs) const {
	GuildMember result;
	result.m_Name = m_Name + rhs.m_Name;
	result.m_Strength = m_Strength + rhs.m_Strength;
	result.m_Wisdom = m_Wisdom + rhs.m_Wisdom;
	result.m_Dexterity = m_Dexterity + rhs.m_Dexterity;
	result.m_Charisma = m_Charisma + rhs.m_Charisma;
	result.m_Intelligence = m_Intelligence + rhs.m_Intelligence;

	return result;
}

void GuildMember::operator[](const int INPUT) const {
	if (INPUT == 0) {
		cout << m_Strength;
	} else if (INPUT == 1) {
		cout << m_Wisdom;
	} else if (INPUT == 2) {
		cout << m_Dexterity;
	} else if (INPUT == 3) {
		cout << m_Charisma;
	} else if (INPUT == 4) {
		cout << m_Intelligence;
	}
	return;
}

ostream& operator<<(ostream& os, const GuildMember& rhs) {
	os << "Name: " << rhs.m_Name << "\nStrength: " << rhs.m_Strength << "\nWisdom: " << rhs.m_Wisdom << "\nDexterity: " << rhs.m_Dexterity
	   << "\nCharisma: " << rhs.m_Charisma << "\nIntelligence: " << rhs.m_Intelligence << "\n\n";
	return os;
}