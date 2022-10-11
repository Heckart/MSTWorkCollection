#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
	std::string line;

	while (getline(cin, line)) {
		if (line[0] != '#') {
			cout << line << endl;
		}
	}

	return 0;
}
