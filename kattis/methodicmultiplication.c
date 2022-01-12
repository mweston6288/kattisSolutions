#include <stdio.h>
#include<string.h>
/*
	A Peano arithmatic natural number is defined as follows: 
		0 = 0
		x = S(x-1)
	For example 2 = S(S(0))

	A Peano arithmatic natural number for x would have a string length of x*3 + 1
	So given a Peano s, I can get the natural number using (s - 1) / 3

	So multiplying two Peanos involves finding the natural numbers, miltiplying them together
	and then printing them in Peano arithmatic form

	Printing would involve x instances of printing "S(", followed by a 0, followed by x instances of ")"
*/
int main(){
	char s1[1001];
	char s2[1001];
	int x,y,i;
	scanf("%s\n%s\n", s1,s2);

	// get the natural numbers
	x = (strlen(s1) - 1) / 3;
	y = (strlen(s2) - 1) / 3;
	// multiply them together
	x *= y;

	// print
	for(i = 0; i < x;i++){
		printf("S(");
	}
	printf("0");
	for(i = 0; i < x;i++){
		printf(")");
	}
	printf("\n");
}