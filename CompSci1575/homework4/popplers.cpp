#include <iostream>

#include "linkedqueue.hpp"
#include "randomengine.h"

int main() {
	LinkedQueue<int> fishyJoesLine;
	randomEngine re;
	int numinQueue;	 // the number of people in the queue at the start
	int intInput;
	int numNxtEnqueue;	// keeps track of the number of popplers the next person will want
	int numRolled;
	int finishedCustomers = 0;	// used to allow keeping track of the leastEaten when the fist person exits the queue for the final time
	int totalPopEaten = 0;		// represents the amount eaten for all people combined
	int leastEaten = 0;			// number of the least popplers eaten by a single person
	int mostEaten = 0;			// number of the most popplers eaten by a single person
	string strInput;
	string leastEatenName;	// name of the person who has eaten the least popplers
	string mostEatenName;	// name of the person who has eaten the most popplers

	cin >> numinQueue;
	for (int i = 0; i < numinQueue; i++) {	// take all necessary input in assign to queues
		cin >> strInput;
		cin >> intInput;
		if (intInput % 5 == 0) {  // if input is divisible by 5, no changes need to be made;
			fishyJoesLine.enqueue(intInput);
			fishyJoesLine.updateTotals(intInput, 0);
		} else {
			while (intInput % 5 != 0) {	 // make the input divisible by 5 if it wasn't originally
				intInput++;
			}
			fishyJoesLine.enqueue(intInput);
			fishyJoesLine.updateTotals(intInput, 0);
		}
		fishyJoesLine.assignName(strInput);
	}

	while (!fishyJoesLine.isEmpty()) {	// this loop will continue until the queue is empty
		numNxtEnqueue = 0;
		numRolled = 0;
		try {
			for (int i = 0; i < fishyJoesLine.front(); i++) {  // generate a random number after each poppler is eaten
				numRolled = re.rollD(6);
				if (numRolled == 6) {  // if the generated random numner is a 6, the person will want to eat another poppler
					numNxtEnqueue++;
				}
			}
		} catch (Oops errObj) {
			cerr << "The list is empty!" << endl;
		}

		// no need for exception handling here because it would have already passed the earlier exception handling
		cout << fishyJoesLine.frontName() << " eats " << fishyJoesLine.front() << " popplers. ";  // print the number of popplers eaten

		if (numNxtEnqueue == 0) {  // condition for a final exit from the queue
			finishedCustomers++;
			cout << fishyJoesLine.frontName() << " is satisfied after eating " << fishyJoesLine.frontTotal() << " popplers.\n";

			if (fishyJoesLine.frontTotal() < leastEaten || finishedCustomers == 1) {  // keep track of the least eaten
				leastEaten = fishyJoesLine.frontTotal();
				leastEatenName = fishyJoesLine.frontName();
			}

			if (fishyJoesLine.frontTotal() > mostEaten) {  // keep track of the most eaten
				mostEaten = fishyJoesLine.frontTotal();
				mostEatenName = fishyJoesLine.frontName();
			}

			totalPopEaten += fishyJoesLine.frontTotal();  // keep track of the total eaten

			fishyJoesLine.dequeue();
		} else {
			cout << fishyJoesLine.frontName() << " wants " << numNxtEnqueue;
			(numNxtEnqueue != 1) ? cout << " more popplers!\n" : cout << " more poppler!\n";  // format well

			if (numNxtEnqueue % 5 == 0) {  // if input is divisible by 5, no changes need to be made;
				fishyJoesLine.enqueue(numNxtEnqueue);
				fishyJoesLine.updateTotals(numNxtEnqueue, fishyJoesLine.front());
			} else {
				while (numNxtEnqueue % 5 != 0) {  // make the input divisible by 5 if it wasn't originally
					numNxtEnqueue++;
				}
				fishyJoesLine.enqueue(numNxtEnqueue);
				fishyJoesLine.updateTotals(numNxtEnqueue, fishyJoesLine.front());
			}
			fishyJoesLine.assignName(fishyJoesLine.frontName());

			fishyJoesLine.dequeue();
		}
	}

	cout << "\nA total of " << totalPopEaten << " popplers were eaten.\n";
	cout << mostEatenName << " ate the most popplers: " << mostEaten << endl;
	cout << leastEatenName << " ate the fewest popplers: " << leastEaten << endl;
	return 0;
}