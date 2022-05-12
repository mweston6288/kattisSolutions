#include <stdio.h>
/*
	Get the ASCII value that represents the average value of the characters in a string
*/
int main(){
	char c;
	int av = 0;
	int total = 0;
	// scan each char and make sure it's not end of the line
	while (scanf("%c", &c) == 1 && c != '\n'){
		av += c;
		total++;

	}
	printf("%c\n", av / total);
}