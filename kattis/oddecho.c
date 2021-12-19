#include <stdio.h>
// given a number of strings, print every other string starting at the first one
int main(){
	int n,i;
	scanf("%d", &n);
	// since I'm just going to print the first word and loop over
	// every other, I need n to be one less
	n--;
	char word[100];
	// get and print the first word
	scanf("%s", word);
	printf("%s\n",word);
	// scan two words and print only the second one
	for(i = 1; i < n; i+=2){
		scanf("%s %s", word, word);
		printf("%s\n",word);
	}
}