#include <stdio.h>
/*
	Determine all possible ways to make a wood plank that is n meters using only 1,2 or 3 meter planks

	Solution:
		Recursively add 1, 2, or 3 until I reach n.
		If I get exactly n, it's a solution. If I go over, it's not a solution
*/
int add(int curr, int n){
	
	if(curr > n){
		return 0;
	}
	if (curr == n){
		return 1;
	}
	// check if adding 1 or 2 or 3 leads to a solution
	// return all solutions found
	int a = add(curr+1, n);
	a += add(curr+2, n);
	a += add(curr+3, n);
	return a;

}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", add(0, n));
}