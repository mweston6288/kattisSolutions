#include <stdio.h>
/*
	Determine if a hotel has any rooms available.

	You are given the total number of rooms r and the number of roomes booked n.
	If there is an available room, print any of them. Otherwise print "too late"

	For this problem, I used bits to store 100 booleans.
	I used an array of 13 chars because a char = 1 byte = 8 bits. 13 bytes = 104 bits
*/
int main(){
	int r,n,i,j,m;
	char rooms[13];
	
	scanf("%d %d", &r, &n);
	// if this is true, all rooms are booked. No need to check any further
	if(n >= r){
		printf("too late\n");
		return 0;
	}
	// intiialize each byte
	for(i = 0; i < 13; i++){
		rooms[i] = 0;
	}
	// write each boolean in the array using bitshift and bitwise OR
	for(i = 0; i < n; i++){
		scanf("%d", &m);
		rooms[m / 8] |= 1 << (m % 8);
	}
	// 0 is an invalid number so the 0th bit in rooms[0] is an invalid entry
	// easiest way I could work around it was to check through the byte
	// separately from the rest
	for(i = 1; i < 8; i++){
		if(!(rooms[0] & (1 << i))){
			printf("%d\n", i);
			return 0;
		}
	}
	// check through the rest of the bits to find a 0
	for(i = 1; i < 13; i++){
		for(j = 0; j < 8; j++){
			if(!(rooms[i] & (1 << j))){
				printf("%d\n", 8*i + j);
				return 0;
			}
		}
	}
}