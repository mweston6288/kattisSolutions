#include <stdio.h>
#include <string.h>

/*
	Given a string, determine if any character appears multiple times
*/

int main(){
	char s[52];
	// will use an array to track the characters seen
	short count[26];
	int i, len;
	for(i=0; i < 26;i++){
		count[i] = 0;
	}
	scanf("%s", s);
	len = strlen(s);

	// for each character, check if it's appeared previously and mark that it's been used
	for(i=0;i<len;i++){
		// if true, the character was previously seen
		if(count[s[i]-'a'] > 0){
			printf("0\n");
			return 0;
		}
		count[s[i]-'a']++;

	}
	printf("1\n");
}