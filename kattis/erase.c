#include <stdio.h>
#include <string.h>
/*
	Idiot boss thinks performing a bunch of not operators is enough to erase a file
	However 2 consecutive nots just reverts back to the original file
*/
int main(){
	int numRuns;
	char init[1001];
	char fin[1001];
	int len;
	scanf("%d\n%s\n%s", &numRuns, init, fin);
	len = strlen(init);

	// odd number of runs: every bit should be flipped
	if(numRuns & 1){
		for(int i = 0; i < len;i++){
			if(init[i] == fin[i]){
				printf("Deletion failed\n");
				return 0;
			}
		}
	}
	// even number of runs: every bit should be unflipped
	else{
		for(int i = 0; i < len;i++){
			if(init[i] != fin[i]){
				printf("Deletion failed\n");
				return 0;
			}
		}		
	}
	printf("Deletion succeeded\n");
}