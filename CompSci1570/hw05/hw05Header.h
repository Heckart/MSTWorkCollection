#ifndef HW05HEADER_H
#define HW05HEADER_H

#include "hw05Neighbor.h"
#include "hw05NewHomeowner.h"

using namespace std;

// Desc: This function fills a neighbor's varibles
// Pre: None
// Post: The neighbors attricutes are randomly given
void initializeNeighbor(neighbor& newNeighbor);

// Desc: This function potentially gives the homeowner a garage
// Pre: Homeowner has more than 0 acres of land and neighbor has at least one garage
// Post: By variable random chance, the homeowner may receive a new garage
void requestAssistance(newHomeowner& theNewHomeowner, neighbor& aGoodNeighbor);

// Desc: This function potentially loses the homeowner land
// Pre: Homeowner hs more than 0 acres of land and neighbor is active
// Post: By variable random chance, the homeowner loses (or regains taken) land
void defendHomeland(newHomeowner& theNewHomeowner, neighbor& aBadNeighbor);

#endif