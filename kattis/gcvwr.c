#include <stdio.h>
/*
	Given a truck's carrying capacity, its wieght and the weight of a set of items,
	determine the maximum weight of a trailer that could be attached while keeping the carrying capacity 
	at or below 90%
*/
int main(){
	int g,t,n;
	int trailer, temp;
	scanf("%d %d %d", &g, &t, &n);
	// first off, subtract the truck's weight from the capaicty
	trailer = g-t;
	// set aside 10% for non-use
	trailer = trailer * 9 / 10;
	// subtract out the weight of the items
	for (int i = 0; i < n; i++){
		scanf("%d", &temp);
		trailer -= temp;
	}
	printf("%d\n", trailer);
}