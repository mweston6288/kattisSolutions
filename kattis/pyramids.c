#include <stdio.h>
/*
	Given a number of blocks, determine how high of a pyramid can be made
	where the top level is 1 block and every level is an (n+2) *(n+2) square 
	where n is the dimension of the previous level
*/
int main(){
	// i will track level, j will track dimension of each level
	int numBlocks, i,j;
	scanf("%d", &numBlocks);
	// keep going until there aren't enough blocks left
	for(i = 0, j = 1; numBlocks >= j*j; i++, j+=2){
		numBlocks -= j*j;
	}
	printf("%d\n", i);
}