#include <stdio.h>
/*
	Given a grid of '.' and '*', mirror it from left-to-right, top-to-bottom
*/
int main(){
	// this will store the original grid
	char grid[20][21];
	// this will sotre the mirrored grid
	char rev[20][21];

	int numCases;
	// row and column
	int r,c;
	// incremetors
	int i,j,k;
	scanf("%d\n", &numCases);

	for(i = 1; i <= numCases;i++){
		scanf("%d %d\n", &r,&c);
		r--;
		c--;
		// fill in the original grid
		for(j = 0; j <= r;j++){
			scanf("%s\n", grid[j]);
		}
		// mirror it to rev
		for(j = 0; j <= r;j++){
			for(k=0;k <= c;k++){
				// if I hadn't decremented j and k earlier, I'd have to do r-j-1 and c-k-1
				rev[r-j][c-k] = grid[j][k];
			}
			// while working on it, add the null terminators
			rev[j][c+1] = '\0';
		}
		// print the results
		printf("Test %d\n", i);
		for(j = 0; j <= r;j++){
			printf("%s\n", rev[j]);
		}
	}
}