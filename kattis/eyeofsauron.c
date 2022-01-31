#include <stdio.h>
/*
	Determine if the number of '|' on both ends of a "()" are the same.
	Instead of reading the string, I chose to read one char at a time and count how many times
	I rad them in.
*/

int main(){
	char s;
	int left = 0;
	int right = 0;
	// scan across the first set of vertical lines. Stop when scanf reads a '('
	while(scanf("%c", &s) && s == '|'){
		left++;
	}
	// read in the ')'
	scanf("%c", &s);
	// read in the remaining '|' until end of input
	while(scanf("%c", &s) == 1 && s == '|'){
		right++;
	}

	printf("%s\n", left == right ? "correct" : "fix");
}