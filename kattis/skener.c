#include <stdio.h>
#include <stdlib.h>
/*
	Expand a given sequence by the given dimensions
	Duplicate each character in a row by zc
	duplicate each row by zr
*/
int main(){
	// r is initial rows
	// c is initial columns
	// zr is number of duplicate rows to print
	// zc is number of duplicate columns to print
	int r,c,zr,zc;
	scanf("%d %d %d %d\n", &r,&c,&zr,&zc);
	char *row = malloc(sizeof(char)*c*zc + 1);
	/*
		i - iterates through each original row
		j - iterates through each original column
		k - iterates for each duplicate column
		l - tracks which index we're writing into
	*/
	int i,j,k,l;
	// the read-in char
	char x;
	// all rows are equal length so I can just set this here
	row[c*zc] = '\0';

	for(i = 0; i < r;i++){
		l = 0;
		// build each expanded row
		for(j = 0; j < c; j++){
			scanf("%c\n", &x);
			for(k = 0; k < zc;k++){
				row[l] = x;
				l++;
			}
		}
		// print the new row the required number of times
		for(j = 0; j < zr;j++){
			printf("%s\n", row);
		}
	}
	free(row);
}