#include <stdio.h>
/*
	Given an image of land, water, and clouds, determine the minimum number of islands possible
	A cloud could be obscuring land or water

	TO solve, I search through the grid for any land. Then I recursively travel up, down, left, and
	right on the grid. 
	Any land is converted into a water tile so it does not get marked again. If I find another land
	or cloud tile while doing a recursive search, I mark them into a water tile because they are
	definitely or possibly part of the island I found.
*/
char grid[50][51];
int r,c;
// convert the cells that are part of a found island into water tiles
void clearLand(int i, int j){
	// check for out-of-bounds
	if (i < 0 || i >= r || j < 0 || j >= c){
		return;
	}
	// convert and check the adjacent tiles
	if(grid[i][j] != 'W'){
		grid[i][j] = 'W';
		clearLand(i, j-1);
		clearLand(i-1, j);
		clearLand(i+1, j);
		clearLand(i, j+1);
	}

}
int main(){
	int i,j;
	int res = 0;
	scanf("%d %d", &r, &c);
	// read in the grid
	for(i = 0; i < r; i++){
		scanf("%s", grid[i]);
	}
	// search each tile for land
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			if(grid[i][j] == 'L'){
				res++;
				clearLand(i,j);
			}
		}
	}
	printf("%d\n", res);
}