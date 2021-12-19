#include <stdio.h>

int main(){
	int a,b, res = 1;
	char c;
	// taking advantage of how no spaces are used
	// will read ints until EOF

	// The first thing is guaranteed to be a number
	// res starts at 1 because of this as well
	scanf("%d", &b);
	// after each int is read, there is either a semicolon, hyphen or linebreak directly after it
	while(1){
		// case 1: semicolon. That means there's a gap in numbers
		// Next value is guaranteed to be an integer
		// Will scan it in and increment res
		if((c = getc(stdin)) == ';'){
			scanf("%d", &b);
			res++;
		}
		// case 2: hyphen. That means we have a range of numbers
		// Next value is guaranteed to be an integer
		// scan it in and add the difference between the new and previous numbers to res
		else if (c == '-'){
			a = b;
			scanf("%d", &b);
			res += (b-a);
		}
		// case 3: \n or invalid character. Exit
		else{
			break;
		}
	}
	printf("%d\n", res);
}