#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
	Given a set of strings, determine how many have the substring "pink" or "rose"
	The strings can have a mix of capital and lowercase letters
*/

int main(){
	char word[32];
	int numWords, numRes = 0, i, j, len;
	scanf("%d", &numWords);

	for (i = 0; i < numWords;i++){
		scanf("%s", word);
		len = strlen(word);

		// preemptively lowercase everything
		for(j = 0; j < len;j++){
			word[j] = tolower(word[j]);
		}
		// there's no reason to check anything when there are 3 or fewer characters left
		len -= 3;
		for(j = 0; j < len;j++){
			// if we find a substring, note the success and go to the next word
			if((word[j] == 'p' && word[j+1] == 'i' && word[j+2] == 'n'&& word[j+3] == 'k') || (word[j] == 'r' && word[j+1] == 'o' && word[j+2] == 's'&& word[j+3] == 'e')){
				numRes++;
				break;
			}
		}
	}
	if(numRes == 0){
		printf("I must watch Star Wars with my daughter\n");
	}
	else{
		printf("%d\n", numRes);
	}
}