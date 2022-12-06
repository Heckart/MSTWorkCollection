#include <cstdlib>
#include <ctime>
#include <iostream>

#include "vector.h"
using namespace std;

template <class T>
int average(Vector<T> vect) {
	int sum = 0;
	for (unsigned int i = 0; i < vect.length(); i++) {
		sum += vect[i];
	}

	return sum / vect.length();
}

int main() {
	srand(time(NULL));
	Vector<int> rand_nums;

	for (unsigned int i = 0; i < 1000; i++) {
		rand_nums.push_back(rand() % 1000);

		int sum = 0;

		for (int i = 0; i < rand_nums.length(); i++) {
			sum += rand_nums[i];
		}

		sum = sum / rand_nums.length();

		cout << sum << endl;
	}

	return 0;
}