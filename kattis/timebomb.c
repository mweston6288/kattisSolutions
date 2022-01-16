#include <stdio.h>
#include <string.h>
/*
	***   * *** *** * * *** *** *** *** ***   8 1 1
	* *   *   *   * * * *   *     * * * * *   4 4 2
	* *   * *** *** *** *** ***   * *** ***   1 2 7
	* *   * *     *   *   * * *   * * *   *   3 6 1
	***   * *** ***   * *** ***   * *** ***   7 3

	
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
	for(i = 0; i < 5;i++){
		grid[i][n+3] = '\0';
	}
	/*
		I'll attempt to divide this as much as possible to reduce comparisons and jumps
		row 1 has the most even diversity so I'll first split there

		Then each check will open with something unique to that specific subset along with everything
		that subset would have in common within itself. That way, I won't potentially check the smae row
		multiple times after I've already confirmed it's correct
	*/
	
	// 0,4,8,9
	if(!strcmp(&grid[1][n], "* *")){
		// 4,9
		if(!strcmp(&grid[3][n], "  *") && !strcmp(&grid[2][n], "***") ){
			// 4
			if(!strcmp(&grid[0][n], "* *")&& !strcmp(&grid[4][n], "  *")){
				return 4;
			}
			// 9
			else if(!strcmp(&grid[0][n], "***") && !strcmp(&grid[4][n], "***")){
				return 9;
			}
		}
		// 0,8
		else if(!strcmp(&grid[0][n], "***") && !strcmp(&grid[3][n], "* *") && !strcmp(&grid[4][n], "***")){
			// 8
			if(!strcmp(&grid[2][n], "***")){
				return 8;
			}
			// 0
			else if(!strcmp(&grid[2][n], "* *")){
				return 0;
			}
		}
	}
	// 1,2,3,7
	else if(!strcmp(&grid[1][n], "  *")){
		// 2,3
		if(!strcmp(&grid[2][n], "***") && !strcmp(&grid[0][n], "***") && !strcmp(&grid[4][n], "***")){
			// 2
			if(!strcmp(&grid[3][n], "*  ")){
				return 2;
			}
			else if(!strcmp(&grid[3][n], "  *")){
				return 3;
			}
		}
		// 1,7
		else if(!strcmp(&grid[2][n], "  *") && !strcmp(&grid[3][n], "  *") && !strcmp(&grid[4][n], "  *")){
			// 1
			if(!strcmp(&grid[0][n], "  *")){
				return 1;
			}
			// 7
			else if(!strcmp(&grid[0][n], "***")){
				return 7;
			}
		}

	}
	// 5,6
	else if(!strcmp(&grid[1][n], "*  ") && !strcmp(&grid[0][n], "***") && !strcmp(&grid[2][n], "***") && !strcmp(&grid[4][n], "***")){
		// 5
		if(!strcmp(&grid[3][n], "  *")){
			return 5;
		}
		// 6
		else if(!strcmp(&grid[3][n], "* *")){
			return 6;
		}
	}
	return -1;
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