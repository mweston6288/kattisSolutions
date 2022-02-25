#include <stdio.h>
/*
	The a word starting at the first 'a' in it
*/
int main(){
	char s[1001];
	int i;
	scanf("%s", s);
	// loop through the string until it finds an 'a'
	for(i = 0; s[i] !='a';i++);
	// print the string starting at the address of that 'a'
	printf("%s\n", &(s[i]));
}