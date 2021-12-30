#include <stdio.h>

/*
	Given an adjacency matrix, print every node that is not part of a triangle

	For this problem, I stored everything using bitwise operators to reduce size and number of checks to make

	If I determined two indices were connected, I'd do a bitwise & on them. If I got anything 
	other than 0, that meant there was a third index they're connected to, which means they can form a triangle
*/
int main(){
	int matrix[20];
	int num,i,j,temp,flag;

	while(1){
		scanf("%d", &num);
		if(num == -1){
			break;
		}
		// read in each connection
		// I use left shifting to store each connection as a bit
		for(i=0;i<num;i++){
			matrix[i] = 0;
			for(j=0;j<num;j++){
				scanf("%d", &temp);
				matrix[i]+= (temp << j);
			}
		}
		temp = 0;
		// for each node...
		for(i=0;i<num;i++){
			flag = 1;
			// compare it to each other node...
			for(j=0;j<num;j++){
				// if it connects to a node...
				if(matrix[i] & (1 << j)){
					// check if they both connect to a third one
					if(matrix[i] & matrix[j]){
						// if they do, we're not evaluating node i anymore
						flag = 0;
						break;
					}
				}
			}
			// if node i isn't part of a triangle
			if(flag)
				printf("%s%d", temp++ > 0 ? " " : "", i);
		}
		printf("\n");

	}
}