#include <stdio.h>
/*
	Given a series of events that are taking place over several days, determine how many days in the year
	at least one event is happening

	Solution was found by storing 365 booleans using a series of long long ints and counting them after

	A long long has 64 bits so I used ceiling(365 / 64) = 6 long longs in an array

	Since I'm working with long long instead of int, I have to use 1LL as a constant
*/
// This function counts how many days an event happened
int eval(unsigned long long *days){
	int res = 0;
	for (int i = 0; i < 6; i++){
		while(days[i] != 0){
			// check if it's true or false
			res += days[i] & 1LL;
			days[i] >>= 1LL;
		}
	}
	return res;
}
int main(){
	int numEvents, i,j;
	int start, end;
	// initialize my 6 long longs
	long long days[] = {0,0,0,0,0,0};
	// b stands for block, d stands for day
	// b will determine what index to access
	// d will determine what bit
	int b,d;
	scanf("%d", &numEvents);
	for(i = 0; i < numEvents;i++){
		scanf("%d %d", &start, &end);
		// find the bit and set it to 1. 
		// bitwise OR is the safest way to set the bit without impacting anything else
		for(j = start; j <= end; j++){
			b = j / 64;
			d = j % 64;
			days[b] |= (1LL << d);
		}
	}
	printf("%d\n", eval(days));
}