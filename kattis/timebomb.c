#include <stdio.h>
#include <string.h>
/*
	***   * *** *** * * *** *** *** *** ***
	* *   *   *   * * * *   *     * * * * *
	* *   * *** *** *** *** ***   * *** ***
	* *   * *     *   *   * * *   * * *   *
	***   * *** ***   * *** ***   * *** ***
	12   5  11  11   9  11  12   7  13  12   - number of stars in each int

	if numStars = 5 -> 1
				= 7 -> 7
				= 9 -> 4
				= 13-> 8
				= 11
					If row 3, col 0 = "*" -> 2
					   row 1, col 2 = " " -> 5
					   				 else -> 3
				= 12
					If row 3, col 0 = " " -> 9
					   row 1, col 2 = " " -> 6
					   				 else -> 0
	
	Input is at-most, 8 digits
	numRows = 5
	numCols = 4*8 = 32

	If 6|n, then n is even and the sum of n's digits is divisible by 3
	So instead of actually parsing what the number is, I'm going to check if it is even
	and add all the digits up as I parse them
*/

char grid[5][33];

// returns the integer value if valid
// returns -1 if not valid
// n is the leftmost column of the ascii sequence we're checking
// n, n+1, and n+2 should be the columns of the whole "number"
int isValid(int n){
	int numStars = 0;
	int i,j;
	// Some quick checks that are guaranteed to be invalid
	// These spots should always have the opposite char we're checking, so if any of these are true
	// it's definitely invalid
	if (grid[1][n+1] == '*' || grid[3][n+1] == '*'|| grid[0][n+2] == ' ' || grid[2][n+2] == ' ' || grid[4][n+2] == ' '){
		return -1;
	}
	// instead of checking each remaining cell, I'm going to count how many stars there are
	// Then for each count, I'll just check if the remaining spots are space
	for(i = 0; i < 5;i++){
		for(j = n + 2; j >=n;j-- ){
			if(grid[i][j] == '*'){
				numStars++;
			}
		}

	}
	
	switch(numStars){
		case 5:
			// faster to check if all the stars in '1' are in the right place
			if(grid[1][n+2] == '*' && grid[3][n+2] == '*'){
				return 1;
			}
		// for everything else, faster to check if the spaces are right
		// already checked the two spots that should always be spaces earlier so no need to check them again
		case 7:
			if(grid[1][n] == ' ' && grid[2][n] == ' ' && grid[2][n+1] == ' ' && grid[3][n] == ' ' && grid[4][n] == ' ' && grid[4][n+1] == ' '){
				return 7;
			}
			return -1;
		case 9:
			if(grid[0][n+1] == ' ' && grid[3][n] == ' ' && grid[4][n] == ' ' && grid[4][n+1] == ' '){
				return 4;
			}
			return -1;
		case 13:
			return 8;
		case 11:
			if(grid[1][n] == ' ' && grid[3][n+2] == ' '){
				return 2;
			}
			else if(grid[1][n] == ' ' && grid[3][n] == ' '){
				return 3;
			}
			else if (grid[1][n+2] == ' ' && grid[3][n] == ' '){
				return 5;
			}
			return -1;
		case 12:
			if(grid[3][n] == ' '){
				return 9;
			}
			else if(grid[1][n+2] == ' '){
				return 6;
			}
			else if (grid[2][n+1] == ' '){
				return 0;
			}
			return -1;
		default:
			return -1;
	}
}
int main(){
	int i, n, len;
	int res,sum;
	for(i = 0; i < 5;i++){
		fgets(grid[i], 33, stdin);
	}
	len = strlen(grid[0]);

	// if 6|n, n is even
	// check for even before proceeding
	sum = isValid(len - 4);
	if(sum & 1 ){
		printf("BOOM!!\n");
		return 0;		
	}

	for(i = len - 8; i >= 0; i -=4){
		res = isValid(i);
		if (res == -1){
			printf("BOOM!!\n");
			return 0;
		}
		sum += res;
	}
	// if n|6, 3|sum of n's digits
	// check for that here
	if(sum % 3 == 0){
		printf("BEER!!\n");
	}
	else{
		printf("BOOM!!\n");
	}
}