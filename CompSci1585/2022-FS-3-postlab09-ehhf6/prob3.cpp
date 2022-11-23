#include <iostream>

#include "vector.h"
using namespace std;

int main() {
	Vector<char *> lines;
	char *buf = new char[100];
	unsigned int total = 0;

	while (cin.getline(buf, 100)) {
		unsigned int length = 0;
		for (unsigned int j = 0; buf[j] != '\0'; j++) {
			length++;
		}
		total += length;
		lines.push_back(buf);
		buf = new char[100];

		// Calculate average line length
		cout << total / lines.length() << endl;
	}

	return 0;
}
