#include <stdio.h>
#include <stdlib.h>

// given an m X n grid with ., X, or #, 
// determine how many 2x2 spaces there are and how many X's are in each
// if a sector has a #, do not count it

int main(){
	int r,c, i,j;
	int res[] = {0,0,0,0,0};
	// read in the dimensions and read the grid
	scanf("%d %d", &r, &c);
	char **grid = malloc(sizeof(char *)* r);
	for(i = 0; i < r; i++){
		grid[i] = malloc(sizeof(char)*c + 1);
		scanf("%s", grid[i]);
	}
	// I'll start at the top-left cornerfor each space
	// therefore, I don't want to begin at last element in each row or column
	r--;
	c--;
	int count;
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			count = 0;
			// Can't use this space
			if(grid[i][j] == '#' || grid[i+1][j] == '#'|| grid[i][j+1] == '#'|| grid[i+1][j+1] == '#')
				continue;
			// check how many X's are in this space
			if(grid[i][j] == 'X')
				count++;
			if(grid[i+1][j] == 'X')
				count++;
			if(grid[i][j+1] == 'X')
				count++;
			if(grid[i+1][j+1] == 'X')
				count++;
			res[count]++;
		}
	}
	for(i = 0; i < 5; i++){
		printf("%d\n", res[i]);
	}
	// free memory
	for(i = 0; i < c; i++){
		free(grid[i]);
	}
	free(grid);
}