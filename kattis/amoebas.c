#include <stdio.h>
#include <string.h>

/*
	To count the number of amoeba, I look for any instance of '#' in the grid, then erase every adjacent 
	instance until I fully loop back. This removes the amoeba from the grid so it doesn't get counted again.

	The grid has some modifications to ensure there's always a series of '.' along the edges of the grid so I don't have
	to worry about out-of-bounds errors
*/
char grid[102][102];
// traverse the trail of '#' and erase them all
void erase(int i, int j){
	while(1){
		if(grid[i][j+1] == '#'){
			j++;
			grid[i][j] = '.';
		}
		else if(grid[i+1][j] == '#'){
			i++;
			grid[i][j] = '.';
		}
		else if(grid[i-1][j] == '#'){
			i--;
			grid[i][j] = '.';
		}
		else if(grid[i][j-1] == '#'){
			j--;
			grid[i][j] = '.';
		}
		else if(grid[i+1][j+1] == '#'){
			i++;
			j++;
			grid[i][j] = '.';
		}
		else if(grid[i+1][j-1] == '#'){
			i++;
			j--;
			grid[i][j] = '.';
		}
		else if(grid[i-1][j+1] == '#'){
			i--;
			j++;
			grid[i][j] = '.';
		}
		else if(grid[i-1][j-1] == '#'){
			i--;
			j--;
			grid[i][j] = '.';
		}
		else{
			break;
		}
	}
}
int main(){
	int r,c,i,j, count = 0;
	scanf("%d %d", &r, &c);
	// buffer above and below the grid to avoid out-of-bounds issues
	memset(grid[0], '.', sizeof(char)*(c+2));
	memset(grid[r+1], '.', sizeof(char)*(c+2));

	for(i = 1; i <= r; i++){
		// buffers to left and right of grid
		grid[i][0] = '.';
		grid[i][c+1] = '.';
		scanf("%s", &(grid[i][1]));
	}
	for(i = 1; i <= r;i++){
		for(j = 1; j <= c; j++){
			if(grid[i][j] == '#'){
				erase(i,j);
				count++;
			}			
		}
	}
	printf("%d\n", count);
}