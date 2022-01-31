#include <stdio.h>
#include <math.h>
/*
	Find all 6 digit numbers n in range l <= n <= h such that
		n has 6 different values in each digit
		n is divisible by each of its digits
		n does not contain a 0

	This is a general brute-force approach
	Process:
		For all values from 1 to 9:
			Check if that value is already in use. If not, insert it
			Check that the partial code could be in the value range
		Recursively insert the remaining values
		Check if the created code can be divided by each digit

	Checking if code is in range [l,h] is done by dividing l,h,and code by the index value a new digit
	was inserted into called pow10. If code / pow10 >= l / pow10, it's possible for code to still be in range.
	Likewise, if code / pow10 <= h / pow10, code is still potentially in range.
*/
int l,h;

// Recieves an integer representing the code and an integer representing the digits used to make the code
// Checks if each used digit value evenly divides code
// Returns 0 if any check fails, 1 otherwise
int isValid(int code, int bools){
	for(int i = 1; i < 10;i++){
		if(bools & (1 << i) && code % i != 0){
			return 0;
		}
	}
	return 1;
}

// Receives an int pointer *bools which points to an integer representation of what digits are in code
// int *code points to the partially completed code to test
// int index determines which digit to edit
// returns the number of voalid codes you can make with code
int getCount(int *bools, int *code, int index){
	// base case: all digits are filled in
	// check for validity
	if(index < 0){
		return isValid(*code, *bools);
	}
	int res = 0;
	// calculate the value of a number in this index
	int pow10 = (int)pow(10,index);
	// for every non-zero value...
	for(int i = 1; i < 10; i++){
		// ...check if it's already in use.
		if(!(*bools & (1 << i))){
			// If it's not, add it to code
			*code += i*pow10;
			// Then check if code could be in range [l,h]
			if((*code / pow10 >= l / pow10) && (*code / pow10 <= h / pow10)){
				// If it is, flag i as in-use
				*bools += 1 << i;
				// finish the code
				res += getCount(bools, code, index - 1);
				// unflag i
				*bools -= 1 << i;
			}
			// reset code for the next round
			*code -= i*pow10;
		}
	}
	return res;
}

int main(){
	scanf("%d %d", &l, &h);
	int bools = 0;
	int code = 0;
	printf("%d\n", getCount(&bools, &code, 5));
}