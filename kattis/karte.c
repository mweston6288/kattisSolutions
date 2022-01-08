#include <stdio.h>
/*
	Determine how many cards of each suit are missing or if there are duplicate cards
	Letters for the suits are H,K,P, and T

	If you subtract the ASCII value of 'G' and divide the result by 4, you get a unique integer for each suit letter
	'P' = 2, K = '1', 'H' = 0, 'T' = 3
	This will reduce the number of jumps necessary to solve the problem

	the cards are stored in a boolean array. Because I need 52 booleans, I'm using longs for this

*/
int main(){
	char c;
	int n, i,j, res;
	long bools = 0;
	while (scanf("%c%d", &c, &n) == 2){
		// Before adding, I have to ckeck if the card is already saved
		// If there's a match, I just print GRESKA and quit early
		if(bools & 1l << ((c-'G') / 4)*13 + n){
			printf("GRESKA\n");
			return 0;
		}
		bools += 1l << ((c-'G') / 4)*13 + n;
	}
	// Get missing cards in 'P' suit.
	// Since ('P' -'G') / 4 = 2, the booleans for 'P' are [2*13+1, 2*13+13] = [27, 39] 
	//
	for(i = 27, j = 39, res = 13; i <= j;i++){
		if(bools & 1l << i){
			res--;
		}
	}
	printf("%d ", res);
	// Get 'K'
	// ('K' -'G') / 4 = 1, so [14, 26] 
	for(i = 14, j = 26, res = 13; i <= j;i++){
		if(bools & 1l << i){
			res--;
		}
	}
	// Get 'H'
	printf("%d ", res);
	for(i = 1, j = 13, res = 13; i <= j;i++){
		if(bools & 1l << i){
			res--;
		}
	}
	// Get 'T'
	printf("%d ", res);
	for(i = 40, j = 52, res = 13; i <= j;i++){
		if(bools & 1l << i){
			res--;
		}
	}
	printf("%d\n", res);
}