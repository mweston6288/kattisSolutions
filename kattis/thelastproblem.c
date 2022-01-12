#include <stdio.h>

int main(){
	char s[51];
	printf("Thank you,");
	// The input string could have spaces
	// while I don't like this solution, it ensured I got every word without possible issues with '\n'
	while (scanf("%s",s) == 1){
		printf(" %s", s);
	}
	printf(", and farewell!\n");
}