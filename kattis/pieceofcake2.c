#include <stdio.h>

/*
	Given an n*n*4 cube that has been split into 4 pieces (l*w*4, l*(n-w)*4, (n-1)*w*4, (n-l)*(n-w)*4)
	determine the area of the largest piece
*/

int main(){
	int n, l,w;
	scanf("%d %d %d", &n, &l, &w);
	// if these are true, that means the larger dimension is the other partition
	if(l <= n / 2){
		l = n - l;
	}
	if (w <= n / 2){
		w = n - w;
	}
	printf("%d\n", l*w*4);
}