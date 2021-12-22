#include <stdio.h>

// given a string that represents an addition problem, parse the problem and solve it
// if a string instead says P=NP, print "skipped"

int main(){
	int numCases;
	scanf("%d", &numCases);

	char c;
	int a,b,i;
	// logic porcess: I can check the very first char in a line to determine if I shhould skip it or solve it
	for(i = 0; i < numCases;i++){
		scanf("%c", &c);
		// if the first char in the line is 'P', just move the exact number of characters needed to skip the line
		if(c == 'P'){
			fseek(stdin, 4, SEEK_CUR);
			printf("skipped\n");
			continue;
		}
		// if the char was not 'P', go back one space and read both ints in. Then solve
		fseek(stdin, -1, SEEK_CUR);
		scanf("%d+%d\n", &a, &b);
		printf("%d\n", a+b);
		
	}
}