#include <stdio.h>
#include <string.h>

// given a word, check if it has two consecutive s's
int main(){
	char word[33];
	scanf("%s", word);
	int i = 0, len = strlen(word);

	while(i < len){
		// look for the first s
		if (word[i] != 's'){
			i++;
			continue;
		}
		// check if there's an adjacent s
		else if(word[i+1] != 's'){
			i +=2;
			continue;
		}
		// found them
		else{
			printf("hiss\n");
			return 0;
		}
	}
	// nothing found
	printf("no hiss\n");
	return 0;
}