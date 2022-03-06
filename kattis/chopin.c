#include <stdio.h>

/*
	Given a series of musical scales, print their alternate names if there are any
	All scales with alternate names end with either a flat ('b') or a sharp ('#')
	so if the scale name has a string length of 2, there's an alt name

	The letter names go from A to G and loop back to A.

	When the scale is a sharp, the alt name is the next letter followed by a flat.
	When the scale is a flat, the alt is one letter down followed by a sharp
*/


void getAlt(char *s1){
	// if it's a sharp, convert from char to int, add 1, loop back if necessary, then convert back to char
	if (s1[1] == '#'){
		s1[0] = (s1[0] - 'A' + 1) % 7 + 'A';
		s1[1] = 'b';
	}
	// if it's a flat, convert from char to int, add 6 (7 to give a positive mod equivalence minus 1 to lower the scale letter), 
	// loop back if necessary, then convert back to char
	else{
		s1[0] = (s1[0] - 'A' + 6) % 7 + 'A';
		s1[1] = '#';		
	}
}

int main(){
	char s1[3], s2[6];
	int count = 1;
	while(scanf("%s %s\n", s1, s2) == 2){
		// s1 is either 1 or two characters long so just check the second space for string length
		if(s1[1] == '\0'){
			printf("Case %d: UNIQUE\n", count);
		}
		else{
			getAlt(s1);
			printf("Case %d: %s %s\n", count, s1, s2);
		}
		count++;
	}
}