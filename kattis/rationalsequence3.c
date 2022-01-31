#include <stdio.h>

/*
	Given a node number in a binary tree, determine the rational number stored in it.
	
	I used a recursive function to start at node 1 and work my way to the one I'm looking for
*/

// stores p and q using pointers
void findNum(int n, int *p, int *q){
	// base case: node 1 = 1/1
	if (n == 1){
		*p = 1;
		*q = 1;
		return;
	}
	findNum(n/2, p, q);
	// every even n is a left child; every odd is a right child
	if (n & 1){
		*p += *q;
	}
	else{
		*q += *p;
	}
}

int main(){
	int numCases;
	int i,n,p,q;
	scanf("%d", &numCases);
	for(i = 1; i <= numCases;i++){
		scanf("%d %d", &n, &n);
		findNum(n, &p, &q);
		printf("%d %d/%d\n", i, p, q);
	}
}