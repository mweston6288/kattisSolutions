#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
	Given a sequence of names and real numbers, get the average of the numbers, then print the names
	in order they appeared

	At most there are 25 names with max length 10 per test case but there can be multiple test cases per file
	A test case ends at either '\n' or EOF

	Since I don't have to organize the names in any way, I stored them all in a continuous string
*/
int main(){
	char names[300];
	char c;
	char s[15];
	double d = 0;
	int i = 0;
	// some initial finagling. names is now an empty string and s has a leading ' '
	// so I don't have to concatenate a space each time I add a name
	names[0] = '\0';
	s[0] = ' ';
	// I store each token starting at s[1] so I can always concatenate a space
	while(scanf("%s", &(s[1])) == 1){
		// token was a name so store that in the string
		if(isalpha(s[1])){
			strcat(names, s);
		}
		// token was a number so add that to the running total
		else{
			d += atof(s);
			i++;
		}
		// after each token, I need to check if its the end of a line
		// if c == ' ', then that means there's another token
		// otherwise this test case is finished and I have to print results
		c = getc(stdin);
		if(c != ' '){
			printf("%lf%s\n", d / i, names);
			// reset everything
			d = 0;
			i = 0;
			names[0] = '\0';
		}

	}
}