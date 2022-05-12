#include <stdio.h>
#include <string.h>
/*
	Line up two words like a crossword puzzle.

	The wordsmust cross at the frst letter where they match. A is horizontal. B is vertical
*/

// find the first matching letter in A and B and store their indices into x and y
void findMatch(char A[], char B[], int lenA, int lenB, int *x, int*y){
	int i,j;
	for(i = 0; i < lenA; i++){
		for(j = 0; j < lenB; j++){
			if (A[i] == B[j]){
				*x = i;
				*y = j;
				return;
			}
		}
	}
}
int main(){
	char A[31], B[31];
	char grid[31][31];
	int x,y;
	int i,j;
	int lenA, lenB;
	scanf("%s %s", A,B);
	
	lenA = strlen(A);
	lenB = strlen(B);
	// initialize the grid
	for(i = 0; i < lenB; i++){
		for(j = 0; j < lenA; j++){
			grid[i][j] = '.';
		}
		grid[i][j] = '\0';
	}

	findMatch(A, B, lenA, lenB, &x, &y);
	// write each word into the grid
	for(i = 0; i < lenA; i++){
		grid[y][i] = A[i];
	}
	for(i = 0; i < lenB; i++){
		grid[i][x] = B[i];
	}
	// print result
	for(i = 0; i < lenB; i++){
		printf("%s\n", grid[i]);
	}
}