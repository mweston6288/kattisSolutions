#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
	A palindrome can have at-most 1 letter that shows up an odd number of times
	To make a peragram out of a pool of letters, you need to remove letters so that only one letter at-most appears
	an odd number of times
*/	
int main(){
	int freq[26];
	memset(freq, 0, sizeof(int)*26);
	int res=0,i;
	char c = getc(stdin);
	// count the frequencies
	while (isalpha(c)){
		freq[c-'a']++;
		c = getc(stdin);
	}
	for(i = 0; i < 26;i++){
		// count how many are odd
		if(freq[i] & 1){
			res++;
		}
	}
	// if there were odd counts, remove 1 less
	if(res){
		printf("%d\n", res-1);
	}
	// otherwise, you don't need to remove any
	else{
		printf("0\n");
	}
}