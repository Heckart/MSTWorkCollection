#include "hw07header.h"

using namespace std;

void gameSummary(Mapmaker mapmaker1, Mapmaker mapmaker2) {
	const int ROW = 10;
	const int COL = 4;

	cout << "COMPETITION SUMMARY:" << endl;
	cout << "\t" << mapmaker1.getName() << ":" << endl;
	cout << "\t\tMap:" << endl;
	for (int i = 0; i < ROW; i++) {	 // output player map
		for (int j = 0; j < COL; j++) {
			cout << "\t\t";
			cout << mapmaker1.getMCoord(i, j);
		}
		cout << endl;
	}
	cout << "\t\tNumber of locations explored: " << mapmaker1.getNumExplored() << endl;
	cout << "\t\tNumber of Rock Paper Scissors won: " << mapmaker1.getRPSWins() << endl;
	cout << endl;
	cout << "\t" << mapmaker2.getName() << ":" << endl;
	cout << "\t\tMap:" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {	 // output player map
			cout << "\t\t";
			cout << mapmaker2.getMCoord(i, j);
		}
		cout << endl;
	}
	cout << "\t\tNumber of locations explored: " << mapmaker2.getNumExplored() << endl;
	cout << "\t\tNumber of Rock Paper Scissors won: " << mapmaker2.getRPSWins() << endl;
}