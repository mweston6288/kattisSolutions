#include <stdio.h>
/*
	Given a time in 24-hour format, print what each digit would look like in binary
	Since the highest digit would be 9, the most bits needed is 4
*/
// checks if a given integer n would have a 1 at bit i
// returns * if true and . otherwise
char bitThere(int n, int i){
	if(n & (1 << i)){
		return '*';
	}
	return '.';
}

int main(){
	int time[4];
	int i,j;
	// read each digit
	scanf("%1d%1d%1d%1d", &time[0],&time[1],&time[2],&time[3]);

	// start at the most significant bit
	for(i = 3; i >= 0; i--){
		printf("%c %c   %c %c\n", bitThere(time[0], i),bitThere(time[1], i),bitThere(time[2], i),bitThere(time[3], i));
	}
}