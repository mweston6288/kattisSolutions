#include <stdio.h>

int main(){
	// we're trying to get the final coordinate of a rectangle parallel to the axes
	// two of the three x and y coordinates passed in will be the same
	// the answer will be the third unpaired values
	// we can just use bitwise XOR to find the fourth coordinate
	int finalX, finalY,x,y;

	scanf("%d %d", &finalX, &finalY);
	scanf("%d %d", &x, &y);
	finalX ^= x;
	finalY ^= y;
	scanf("%d %d", &x, &y);
	finalX ^= x;
	finalY ^= y;

	printf("%d %d\n", finalX, finalY);
}