#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
	Check if a string is a pangram, a sentence that uses every letter in the alphabet
	If it is not a pangram, print all the missing letters

	For this problem I used bitwise OR to store a boolean of each letter
*/
// this is 2^26 - 1 which you'd get if all 26 letters appear
#define ALL 67108863

int main(){
	char s[105];
	int numCases, len, res, i,j;

	scanf("%d\n", &numCases);
	for(i = 0; i < numCases;i++){

		fgets(s, 102, stdin);
		len = strlen(s);
		res = 0;
		// read each char. If it's a letter, update res using bitshifting
		for(j = 0; j < len;j++){
			if(isalpha(s[j])){
				res |= (1 << tolower(s[j]) - 'a');
			}
		}
		if(res == ALL){
			printf("pangram\n");
		}
		else{
			// use bitshifting and bitwise AND to print the missing letters
			printf ("missing ");
			for (j = 0; j < 26; j++){
				if(!(res & (1 << j))){
					printf("%c", j+'a');
				}
			}
			printf("\n");
		}
	}
	
}