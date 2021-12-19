#include <stdio.h>


// there are exactly 10 elements and we're comparing to mod 42
// I'm just going to get everything, mod them and then compare everything
#define SIZE 10
#define MOD 42

int main(){

	int set[SIZE];
	int i,j;
	int res = SIZE; // will start at max possible number and decrease as needed
	// get everything and mod them
	for(i = 0; i < SIZE; i++){
		scanf("%d", &set[i]);
		set[i] %= MOD;
	}

	for(i = 0; i < SIZE - 1; i++){
		if(set[i] == -1)
			continue;
		for(j = i+1; j < SIZE; j++){
			if(set[i] == set[j]){
				set[j] = -1;
				res--;
			}

		}
	}
	printf("%d\n", res);
}