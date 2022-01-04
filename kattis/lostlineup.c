#include <stdio.h>
#include <stdlib.h>
/*
	A group of people are forming a line. Each person only knows who's at the front and 
	how many people are between them and who is at front.
	Determine the line order.

	1 is always first.
*/
int main(){
	int numLine;
	int i,j;
	// order stores the order of everyone behind the person at front
	int *order;

	scanf("%d", &numLine);
	order = malloc(sizeof(int)*(numLine-1));
	// for each person, read their distance from the first and store that person in
	// the appropriate index
	for(i = 2; i <=numLine;i++){
		scanf("%d", &j);
		order[j] = i;
	}
	numLine--;
	printf("1");
	// print the people in order
	for(i = 0; i < numLine;i++){
		printf(" %d", order[i]);
	}
	printf("\n");
	free(order);
}