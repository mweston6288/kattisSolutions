#include <stdio.h>
#include <string.h>
/*
	Process to find the lexiconally shortest word in this grid:
		scan in the grid and create the transverse of it
		For each instance of '#', replace it with the null terminal
		scan through both grids the find words
*/
int main(){
	char grid[20][21];
	char gridT[20][21];
	char res[21];
	int r,c;
	int i,j,k;

	scanf("%d %d\n", &r,&c);
	
	// initialize res with the worst possible answer
	for(i = 0; i < 20;i++){
		res[i] = 'z';
	}
	res[20] = '\0';

	for(i = 0; i < r;i++){
		for(j = 0; j < c;j++){
			scanf("%c\n", &grid[i][j]);
			// Replace each '#' with null terminator to find the strings better
			if(grid[i][j] == '#'){
				grid[i][j] = '\0';
			}
			// copy into the transverse
			gridT[j][i] = grid[i][j];
		}
		grid[i][c] = '\0';
	}
	// put null terminals at the end of each row in the transverse
	for(i = 0; i < c;i++){
		gridT[i][r] = '\0';
	}
	// find all the strings in grid and find the one we want
	for(i = 0; i < r; i++){
		// grid[i] can have multiple independent strings in it so j will track which index the next
		// string would start at
		j = 0;
		while(j < c){
			k = strlen(&(grid[i][j]));
			// string must have at least 2 chars and come before the current best
			if(k > 1 && strcmp(&(grid[i][j]), res) < 0) {
				strcpy(res, &(grid[i][j]));
			}
			j += k + 1;
		}
	}
	// same as above but now with gridT
	for(i = 0; i < c; i++){
		j = 0;
		while(j < r){
			k = strlen(&(gridT[i][j]));
			if(k > 1 && strcmp(&(gridT[i][j]), res) < 0) {
				strcpy(res, &(gridT[i][j]));
			}
			j += k + 1;
		}
	}
	printf("%s\n", res);
}