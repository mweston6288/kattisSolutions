#include <stdio.h>

// Given a 5-card poker hand, determine how often the most recurring value is in the hand

int main(){
	char vals[5];
	char junk; // suit value is worthless and will go in this junk variable
	int i,j;
	// The input is 5 pairs of chars for each cards' value and suit separated by a space
	// I'm scanning the first value here since it's scan is slightly different format-wise
	scanf("%c%c", &vals[0], &junk);

	for(i = 1; i < 5; i++){
		// for the other cards, I'm using a space so scanf skips over them
		scanf(" %c%c", &vals[i], &junk);
	}
	// for each card, compare its value to each other value
	// Save the largest recurrence found
	int recurrence, highest = 0;
	for(i = 0; i < 4;i++){
		recurrence = 1;
		for(j = i+1; j < 5; j++){
			if (vals[i] == vals[j]){
				recurrence++;
			}
		}
		if(recurrence > highest){
			highest = recurrence;
		}
	}
	printf("%d\n", highest);
}