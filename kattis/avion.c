#include <stdio.h>
#include <string.h>

// Receive 5 strings and check if the substring "FBI" is in any

#define NUM_PLANES 5

int main(){
	char name[12];
	int i, j,len;
	short numAns = 0; // used as a boolean to check if any strings had "FBI" in them
	for(i = 1; i <= NUM_PLANES; i++){
		scanf("%s", name);
		len = strlen(name) - 2; // Don't bother checking if a 3-char sequence begins in the last two indices
		
		for(j=0;j<len;j++){
			if(name[j] != 'F' || name[j+1] != 'B' || name[j+2] != 'I'){
				continue;
			}
			printf("%s%d", numAns ? " " : "", i);
			numAns++;
		}
	}
	if(!numAns){
		printf("HE GOT AWAY!\n");
		return 0;
	}
}