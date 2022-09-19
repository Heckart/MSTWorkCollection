#include "hw06header.h"

using namespace std;

void airdropBees(char array[][10], const int P1, const int P2) {
	const int CONST_ZERO = 0;
	const int CONST_ONE = 1;
	const int CONST_NINE = 9;

	if (array[P1][P2] == '_') {
		array[P1][P2] = 'B';
	} else if (array[P1][P2] == 'B') {
		if (P1 != CONST_ZERO && P2 != CONST_ZERO) {	 // B Above & left
			if (array[P1 - CONST_ONE][P2 - CONST_ONE] == '_') {
				array[P1 - CONST_ONE][P2 - CONST_ONE] = 'B';
			} else if (array[P1 - CONST_ONE][P2 - CONST_ONE] == 'B') {
				array[P1 - CONST_ONE][P2 - CONST_ONE] = 'W';
			}
		}
		if (P1 != CONST_ZERO) {	 // B Above
			if (array[P1 - CONST_ONE][P2] == '_') {
				array[P1 - CONST_ONE][P2] = 'B';
			} else if (array[P1 - CONST_ONE][P2] == 'B') {
				array[P1 - CONST_ONE][P2] = 'W';
			}
		}
		if (P1 != CONST_ZERO && P2 != CONST_NINE) {	 // B Above & right
			if (array[P1 - CONST_ONE][P2 + CONST_ONE] == '_') {
				array[P1 - CONST_ONE][P2 + CONST_ONE] = 'B';
			} else if (array[P1 - CONST_ONE][P2 + CONST_ONE] == 'B') {
				array[P1 - CONST_ONE][P2 + CONST_ONE] = 'W';
			}
		}
		if (P2 != CONST_ZERO) {	 // B Left
			if (array[P1][P2 - CONST_ONE] == '_') {
				array[P1][P2 - CONST_ONE] = 'B';
			} else if (array[P1][P2 - CONST_ONE] == 'B') {
				array[P1][P2 - CONST_ONE] = 'W';
			}
		}
		if (P2 != CONST_NINE) {	 // B Right
			if (array[P1][P2 + CONST_ONE] == '_') {
				array[P1][P2 + CONST_ONE] = 'B';
			} else if (array[P1][P2 + CONST_ONE] == 'B') {
				array[P1][P2 + CONST_ONE] = 'W';
			}
		}
		if (P1 != CONST_NINE && P2 != CONST_ZERO) {	 // B Below & left
			if (array[P1 + CONST_ONE][P2 - CONST_ONE] == '_') {
				array[P1 + CONST_ONE][P2 - CONST_ONE] = 'B';
			} else if (array[P1 + CONST_ONE][P2 - CONST_ONE] == 'B') {
				array[P1 + CONST_ONE][P2 - CONST_ONE] = 'W';
			}
		}
		if (P1 != CONST_NINE) {	 // B Below
			if (array[P1 + CONST_ONE][P2] == '_') {
				array[P1 + CONST_ONE][P2] = 'B';
			} else if (array[P1 + CONST_ONE][P2] == 'B') {
				array[P1 + CONST_ONE][P2] = 'W';
			}
		}
		if (P1 != CONST_NINE && P2 != CONST_NINE) {	 // B Below & right
			if (array[P1 + CONST_ONE][P2 + CONST_ONE] == '_') {
				array[P1 + CONST_ONE][P2 + CONST_ONE] = 'B';
			} else if (array[P1 + CONST_ONE][P2 + CONST_ONE] == 'B') {
				array[P1 + CONST_ONE][P2 + CONST_ONE] = 'W';
			}
		}
	} else if (array[P1][P2] == 'W') {
		if (P1 != CONST_ZERO && P2 != CONST_ZERO) {	 // W Above & left
			if (array[P1 - CONST_ONE][P2 - CONST_ONE] == '_') {
				array[P1 - CONST_ONE][P2 - CONST_ONE] = 'W';
			} else if (array[P1 - CONST_ONE][P2 - CONST_ONE] == 'B') {
				array[P1 - CONST_ONE][P2 - CONST_ONE] = 'W';
			} else if (array[P1 - CONST_ONE][P2 - CONST_ONE] == 'W') {
				array[P1 - CONST_ONE][P2 - CONST_ONE] = 'T';
			}
		}
		if (P1 != CONST_ZERO) {	 // W Above
			if (array[P1 - CONST_ONE][P2] == '_') {
				array[P1 - CONST_ONE][P2] = 'W';
			} else if (array[P1 - CONST_ONE][P2] == 'B') {
				array[P1 - CONST_ONE][P2] = 'W';
			} else if (array[P1 - CONST_ONE][P2] == 'W') {
				array[P1 - CONST_ONE][P2] = 'T';
			}
		}
		if (P1 != CONST_ZERO && P2 != CONST_NINE) {	 // W Above & right
			if (array[P1 - CONST_ONE][P2 + CONST_ONE] == '_') {
				array[P1 - CONST_ONE][P2 + CONST_ONE] = 'W';
			} else if (array[P1 - CONST_ONE][P2 + CONST_ONE] == 'B') {
				array[P1 - CONST_ONE][P2 + CONST_ONE] = 'W';
			} else if (array[P1 - CONST_ONE][P2 + CONST_ONE] == 'W') {
				array[P1 - CONST_ONE][P2 + CONST_ONE] = 'T';
			}
		}
		if (P2 != CONST_ZERO) {	 // W Left
			if (array[P1][P2 - CONST_ONE] == '_') {
				array[P1][P2 - CONST_ONE] = 'W';
			} else if (array[P1][P2 - CONST_ONE] == 'B') {
				array[P1][P2 - CONST_ONE] = 'W';
			} else if (array[P1][P2 - CONST_ONE] == 'W') {
				array[P1][P2 - CONST_ONE] = 'T';
			}
		}
		if (P2 != CONST_NINE) {	 // W Right
			if (array[P1][P2 + CONST_ONE] == '_') {
				array[P1][P2 + CONST_ONE] = 'W';
			} else if (array[P1][P2 + CONST_ONE] == 'B') {
				array[P1][P2 + CONST_ONE] = 'W';
			} else if (array[P1][P2 + CONST_ONE] == 'W') {
				array[P1][P2 + CONST_ONE] = 'T';
			}
		}
		if (P1 != CONST_NINE && P2 != CONST_ZERO) {	 // W Below & left
			if (array[P1 + CONST_ONE][P2 - CONST_ONE] == '_') {
				array[P1 + CONST_ONE][P2 - CONST_ONE] = 'W';
			} else if (array[P1 + CONST_ONE][P2 - CONST_ONE] == 'B') {
				array[P1 + CONST_ONE][P2 - CONST_ONE] = 'W';
			} else if (array[P1 + CONST_ONE][P2 - CONST_ONE] == 'W') {
				array[P1 + CONST_ONE][P2 - CONST_ONE] = 'T';
			}
		}
		if (P1 != CONST_NINE) {	 // W Below
			if (array[P1 + CONST_ONE][P2] == '_') {
				array[P1 + CONST_ONE][P2] = 'W';
			} else if (array[P1 + CONST_ONE][P2] == 'B') {
				array[P1 + CONST_ONE][P2] = 'W';
			} else if (array[P1 + CONST_ONE][P2] == 'W') {
				array[P1 + CONST_ONE][P2] = 'T';
			}
		}
		if (P1 != CONST_NINE && P2 != CONST_NINE) {	 // W Below & right
			if (array[P1 + CONST_ONE][P2 + CONST_ONE] == '_') {
				array[P1 + CONST_ONE][P2 + CONST_ONE] = 'W';
			} else if (array[P1 + CONST_ONE][P2 + CONST_ONE] == 'B') {
				array[P1 + CONST_ONE][P2 + CONST_ONE] = 'W';
			} else if (array[P1 + CONST_ONE][P2 + CONST_ONE] == 'W') {
				array[P1 + CONST_ONE][P2 + CONST_ONE] = 'T';
			}
		}
	} else if (array[P1][P2] == 'T') {
		if (P1 != CONST_ZERO && P2 != CONST_ZERO) {	 // T Above & left
			if (array[P1 - CONST_ONE][P2 - CONST_ONE] == '_') {
				array[P1 - CONST_ONE][P2 - CONST_ONE] = 'T';
			} else if (array[P1 - CONST_ONE][P2 - CONST_ONE] == 'B') {
				array[P1 - CONST_ONE][P2 - CONST_ONE] = 'W';
			} else if (array[P1 - CONST_ONE][P2 - CONST_ONE] == 'W') {
				array[P1 - CONST_ONE][P2 - CONST_ONE] = 'T';
			}
		}
		if (P1 != CONST_ZERO) {	 // T Above
			if (array[P1 - CONST_ONE][P2] == '_') {
				array[P1 - CONST_ONE][P2] = 'W';
			} else if (array[P1 - CONST_ONE][P2] == 'B') {
				array[P1 - CONST_ONE][P2] = 'W';
			} else if (array[P1 - CONST_ONE][P2] == 'W') {
				array[P1 - CONST_ONE][P2] = 'T';
			}
		}
		if (P1 != CONST_ZERO && P2 != CONST_NINE) {	 // T Above & right
			if (array[P1 - CONST_ONE][P2 + CONST_ONE] == '_') {
				array[P1 - CONST_ONE][P2 + CONST_ONE] = 'W';
			} else if (array[P1 - CONST_ONE][P2 + CONST_ONE] == 'B') {
				array[P1 - CONST_ONE][P2 + CONST_ONE] = 'W';
			} else if (array[P1 - CONST_ONE][P2 + CONST_ONE] == 'W') {
				array[P1 - CONST_ONE][P2 + CONST_ONE] = 'T';
			}
		}
		if (P2 != CONST_ZERO) {	 // T Left
			if (array[P1][P2 - CONST_ONE] == '_') {
				array[P1][P2 - CONST_ONE] = 'W';
			} else if (array[P1][P2 - CONST_ONE] == 'B') {
				array[P1][P2 - CONST_ONE] = 'W';
			} else if (array[P1][P2 - CONST_ONE] == 'W') {
				array[P1][P2 - CONST_ONE] = 'T';
			}
		}
		if (P2 != CONST_NINE) {	 // T Right
			if (array[P1][P2 + CONST_ONE] == '_') {
				array[P1][P2 + CONST_ONE] = 'W';
			} else if (array[P1][P2 + CONST_ONE] == 'B') {
				array[P1][P2 + CONST_ONE] = 'W';
			} else if (array[P1][P2 + CONST_ONE] == 'W') {
				array[P1][P2 + CONST_ONE] = 'T';
			}
		}
		if (P1 != CONST_NINE && P2 != CONST_ZERO) {	 // T Below & left
			if (array[P1 + CONST_ONE][P2 - CONST_ONE] == '_') {
				array[P1 + CONST_ONE][P2 - CONST_ONE] = 'W';
			} else if (array[P1 + CONST_ONE][P2 - CONST_ONE] == 'B') {
				array[P1 + CONST_ONE][P2 - CONST_ONE] = 'W';
			} else if (array[P1 + CONST_ONE][P2 - CONST_ONE] == 'W') {
				array[P1 + CONST_ONE][P2 - CONST_ONE] = 'T';
			}
		}
		if (P1 != CONST_NINE) {	 // T Below
			if (array[P1 + CONST_ONE][P2] == '_') {
				array[P1 + CONST_ONE][P2] = 'W';
			} else if (array[P1 + CONST_ONE][P2] == 'B') {
				array[P1 + CONST_ONE][P2] = 'W';
			} else if (array[P1 + CONST_ONE][P2] == 'W') {
				array[P1 + CONST_ONE][P2] = 'T';
			}
		}
		if (P1 != CONST_NINE && P2 != CONST_NINE) {	 // T Below & right
			if (array[P1 + CONST_ONE][P2 + CONST_ONE] == '_') {
				array[P1 + CONST_ONE][P2 + CONST_ONE] = 'W';
			} else if (array[P1 + CONST_ONE][P2 + CONST_ONE] == 'B') {
				array[P1 + CONST_ONE][P2 + CONST_ONE] = 'W';
			} else if (array[P1 + CONST_ONE][P2 + CONST_ONE] == 'W') {
				array[P1 + CONST_ONE][P2 + CONST_ONE] = 'T';
			}
		}
	}

	return;
}