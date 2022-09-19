#ifndef HW05NEIGHBOR_H
#define HW05NEIGHBOR_H

#include <string>

using namespace std;

struct neighbor {
	int m_neighborID = 0;
	int m_numGarages = 0;
	float m_startLand = 0.0;
	float m_currentLand = 0.0;
	bool m_friendly = false;
	bool m_active = true;
};

#endif