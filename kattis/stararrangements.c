#include <stdio.h>
/*
	n = number of stars
	c = number of stars in first row
	r = number of rows

	if each row has the same number of stars, then if cr = n, it is good
	if the number of stars alternate, then if (c+c-1)*r = n or (c+c-1)*r = n-c, it is good

	For the alternating row type, there can be an odd number of rows (which means the even amount should have n-c stars)
	If there would be an even number of rows, (c+c-1)*r should equal n 
*/

// Checks for if a flag with alternating numbers is appealing
int isAppealingDiff(int n, int c){
	return (n % (c+c-1) == 0) || (n % (c+c-1) == c);
}
// checks if a flag with constant numbers is appealing
int isAppealingEq(int n, int c){
	return n % c == 0;
}
int main(){
	int n;
	scanf("%d", &n);
	int c;
	// At most, you can have two rows with half the stars
	c = n/2;
	// if n is odd, the above needs one more star on the first line
	if(n & 1){
		c++;
	}
	printf("%d:\n", n);
	for(int i = 2; i <= c;i++){
		// check if a pattern of i,i-1 is appealing
		if(isAppealingDiff(n,i)){
			printf("%d,%d\n", i, i-1);
		}
		// check if a pattern of i,i is appealing
		if(isAppealingEq(n,i)){
			printf("%d,%d\n", i, i);
		}
	}
}