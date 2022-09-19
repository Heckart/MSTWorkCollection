// Programmer: Ethan Heckart
// File: lab09main.cpp
// Date: 4/11/22
// Purpose:

#include <iostream>

#include "guildmemberclass.h"

using namespace std;

int main() {
	string user_name, user_class;
	int user_age, user_level;
	GuildMember user;

	cin >> user_name;
	cin >> user_age;
	cin >> user_class;
	cin >> user_level;

	// set class values
	user.setName(user_name);
	user.setAge(user_age);
	user.setClass(user_class);
	user.setLevel(user_level);
	cout << endl;

	user.passTime();
	user.passTime();

	// print class variables
	user.print();
	cout << endl;

	user.getName();
	cout << endl;
	user.getAge();

	return 0;
}