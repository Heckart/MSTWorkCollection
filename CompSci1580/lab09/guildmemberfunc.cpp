#include <iostream>

#include "guildmemberclass.h"

using namespace std;

void GuildMember::age() { m_age++; }

void GuildMember::getName() const {
	cout << "Members name is: " << m_name;
	return;
}

void GuildMember::getAge() const {
	cout << "Members age is: " << m_age;
	return;
}

void GuildMember::setName(const string input) { m_name = input; }

void GuildMember::setAge(const int input) { m_age = input; }

void GuildMember::setLevel(const int input) { m_lvl = input; }

void GuildMember::setClass(const string input) { m_class = input; }

void GuildMember::passTime() { age(); }

void GuildMember::print() const {
	cout << "Name: " << m_name << endl;
	cout << "Class: " << m_class << endl;
	cout << "Level: " << m_lvl << endl;
	cout << "Age: " << m_age << endl;
}
