#include "logicfunctions.h"

// Compute xor
// xor is true as long as x and y are not equal
void exclusive(bool x, bool y, bool& ans){
	ans = (x != y);
}

// Compute implication
// implication is false when x is true while y is false
// if x is false or y is true, implication is guaranteed to be true
void implies(bool x, bool y, bool& ans){
	ans = (x == false || y == true);
}

// Compute equivalence
// equivalence is true when x and y are equal
void equivalence(bool x, bool y, bool& ans){
	ans = (x == y);
}
