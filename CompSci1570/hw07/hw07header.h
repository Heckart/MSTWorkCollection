#ifndef HW07HEADER_H
#define HW07HEADER_H

#include <string>

#include "hw07mapmaker.h"
#include "hw07region.h"

using namespace std;

// Desc: Prints a summary of the game to the console
// Pre: None
// Post: Final map, number of locations explored, and number of RPS wins of each mapmaker are printed to the console
void gameSummary(Mapmaker mapmaker1, Mapmaker mapmaker2);

#endif