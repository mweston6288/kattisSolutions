#include <stdio.h>
#include <stdlib.h>
/*
	Process a series of requests to either relocate buildings along a line or find the ditance between two buildings
	When reading in requests, if the first number is 1, that means relocate a building
	If the first number is two, that means find the distance between buildings
*/
int main(){
	int numBuildings, numRequests;
	scanf("%d %d", &numBuildings, &numRequests);

	// building count starts at 1 so 0 index will be a junk field
	int *buildings = malloc(sizeof(int)*(numBuildings +1));
	int i;
	// get initial building locations
	for(i = 1; i <= numBuildings;i++){
		scanf("%d", &buildings[i]);
	}
	// Used to process requests
	int a,b,c;
	for(i = 0; i < numRequests;i++){
		scanf("%d %d %d", &a,&b,&c);
		// if a = 1, relocate building b to location c
		if(a == 1){
			buildings[b] = c;
		}
		// if a = 2, get the distance between building b and building c
		else{
			printf("%d\n", abs(buildings[b] - buildings[c]));
		}
	}
	free(buildings);
}