#include <stdio.h>
#include <string.h>
/*
	Determine if a list of names is in ascneding order, descending order, or neither

	After compairing the first two names, I can determine if it could be descending or ascneding order

	In order to avoid using strcpy and reducing the amount of space used, I used a 2d char array.
	Two names are stored and I alternate which one gets written into and the order I pass them
	into strcmp.
	names[i & 1] will evaluate to 0 whenever i is even and 1 when it is odd
	names[!(i & 1)] will do the opposite
	With this, the program will alternate which char array to write into and the order to compare them.
*/

int main(){
	int n,i;
	char names[2][13];
	scanf("%d\n", &n);
	// read the first two names
	scanf("%s\n%s\n", names[0], names[1]);
	// first two names are in ascending order so either
	// INCREASING or NEITHER
	if(strcmp(names[0], names[1]) < 0){
		for(i = 2; i < n; i++){
			scanf("%s\n", names[i & 1]);
			// two names found in decreasing order
			if(strcmp(names[!(i & 1)], names[i & 1]) > 0){
				printf("NEITHER\n");
				return 0;
			}
		}
		printf("INCREASING\n");
	}
	// first two names are in decreasing order so either
	// DECREASING or NEITHER
	else{
		for(i = 2; i < n; i++){
			scanf("%s\n", names[i & 1]);
			if(strcmp(names[!(i & 1)], names[i & 1]) < 0){
				printf("NEITHER\n");
				return 0;
			}
		}
		printf("DECREASING\n");

	}
}