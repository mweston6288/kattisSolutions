#include <stdio.h>
#include <string.h>
#include <math.h>

/*
	This problem is standard base convertion with the twist that the numbers may not follow standard
	numbering conventions. For example, I might have to convert from base 3 to base 7 but the number systems
	might be oF7 to R{h/}04

	Standard steps for base conversion still apply, but now I have to refer to a given table of each number
	system to determine what the conversions look like.

	Standard process:
		1) Convert the source number from base b to base 10
			a) get the length of the number
			b) cross reference each digit with its equivalent arabaic value
			c) get the sum of each digit value times b raised to the power of its significance
				ex: Foo = 1*3^2 + 0*3^1 + 0*3^0
		2) Convert the above calculated number, i, from base 10 to base c
			a) calculate i = qc + r, the quotient and remainder of i / c
			b) cross reference r with the target language to determine what character it is. r is the LSD
			c) repeat the process using i = c, until i = 0
*/

// convert the "number" in string to an equivalent number in base 10
int base10(char *string, char *source, int len, int base){
	int i, j, res = 0;
	for(i = 0; i < len; i++){
		// will have to check every value in the source language to find its arabic vale
		for(j = 0; j < base; j++){
			if(string[i] == source[j]){
				// get its base value
				res += j * pow(base, (len - i - 1));
				break;
			}
		}
	}
	return res;
}
// recursively determine each digit of the new language's number equivalence
void printToBase(int val, char *language, int base){
	if(val == 0){
		return;
	}
	// since the process find the lsd first, we recursively call the function to calculate
	// every digit before we start printing them
	printToBase(val / base, language, base);
	printf("%c", language[val % base]);
}
int main(){
	int t, val;
	char string[32];
	char source[100];
	char target[100];
	int lenString, lenSource, lenTarget;

	scanf("%d", &t);

	for(int i = 1; i <= t; i++){
		scanf("%s %s %s\n", string, source, target);
		// get length of the "number" and how many values are in the source and target number systems
		lenString = strlen(string);
		lenSource = strlen(source);
		lenTarget = strlen(target);
		// convert to base 10
		val = base10(string, source, lenString, lenSource);
		printf("Case #%d: ", i);
		// convert to target value
		printToBase(val, target, lenTarget);
		printf("\n");
	}
}