#include <stdio.h>
#include <stdlib.h>
/*
	I'm no chess savant so I had to bruteforce this

	I created a queue system and checked all locations in-order, then went thtrough the whole
	board and printed whatever had the greatest number of jumps to reach
*/

// rows are denoted 1-8
// columns are denoted a-h
int board[9][8];
// list of coordinates that have been systematically reached
// next[n][0] is the row
// next[n][1] is the col
int next[64][2];

void hunt(){
	// i iterates through all of next
	// j tracks which index to add the next coordinate to the queue
	int i,j;

	/*
		plan:
			Make sure a piece at next[i] can move in a certain direction
			If it can, and it wasn't previously reached, add it to the queue
			Also set the board space next[i] can move to the number of jumps needed to 
			reach next[i] + 1
	*/
	for(i = 0, j = 1; i < 64;i++){
		// down 2, left 1
		if(next[i][0] > 2 && next[i][1] > 0 && board[next[i][0] - 2][next[i][1] - 1] == -1){
			next[j][0] = next[i][0] - 2;
			next[j][1] = next[i][1] - 1;
			board[next[j][0]][next[j][1]] = board[next[i][0]][next[i][1]] + 1;
			j++;
		}
		// down 2, right 1
		if(next[i][0] > 2 && next[i][1] < 7 && board[next[i][0] - 2][next[i][1] + 1] == -1){
			next[j][0] = next[i][0] - 2;
			next[j][1] = next[i][1] + 1;
			board[next[j][0]][next[j][1]] = board[next[i][0]][next[i][1]] + 1;
			j++;
		}
		// up 2, left 1
		if(next[i][0] < 7 && next[i][1] > 0 && board[next[i][0] + 2][next[i][1] - 1] == -1){
			next[j][0] = next[i][0] + 2;
			next[j][1] = next[i][1] - 1;
			board[next[j][0]][next[j][1]] = board[next[i][0]][next[i][1]] + 1;
			j++;
		}	
		// up 2, right 1
		if(next[i][0] < 7 && next[i][1] < 7 && board[next[i][0] + 2][next[i][1] + 1] == -1){
			next[j][0] = next[i][0] + 2;
			next[j][1] = next[i][1] + 1;
			board[next[j][0]][next[j][1]] = board[next[i][0]][next[i][1]] + 1;
			j++;
		}		

		// down 1, left 2
		if(next[i][0] > 1 && next[i][1] > 1 && board[next[i][0] - 1][next[i][1] - 2] == -1){
			next[j][0] = next[i][0] - 1;
			next[j][1] = next[i][1] - 2;
			board[next[j][0]][next[j][1]] = board[next[i][0]][next[i][1]] + 1;
			j++;
		}
		// down 1, right 2
		if(next[i][0] > 1 && next[i][1] < 6 && board[next[i][0] - 1][next[i][1] + 2] == -1){
			next[j][0] = next[i][0] - 1;
			next[j][1] = next[i][1] + 2;
			board[next[j][0]][next[j][1]] = board[next[i][0]][next[i][1]] + 1;
			j++;
		}
		// up 1, left 2
		if(next[i][0] < 8 && next[i][1] > 1 && board[next[i][0] + 1][next[i][1] - 2] == -1){
			next[j][0] = next[i][0] + 1;
			next[j][1] = next[i][1] - 2;
			board[next[j][0]][next[j][1]] = board[next[i][0]][next[i][1]] + 1;
			j++;
		}	
		// up 1, right 2
		if(next[i][0] < 8 && next[i][1] < 6 && board[next[i][0] + 1][next[i][1] + 2] == -1){
			next[j][0] = next[i][0] + 1;
			next[j][1] = next[i][1] + 2;
			board[next[j][0]][next[j][1]] = board[next[i][0]][next[i][1]] + 1;
			j++;
		}	
	}
	
	// the very last spot in next would obviously have taken the highest number of moves to reach
	int maxJumps = board[next[63][0]][next[63][1]];
	printf("%d", maxJumps);
	// print everything from top to bottom left to right starting at a8
	// that took the most moves to reach
	for(i = 8; i >0; i--){
		for(j = 0; j < 8; j++){
			if(board[i][j] == maxJumps){
				printf(" %c%d", j+'a', i);
			}
		}
	}
	printf("\n");
}
int main(){
	int i,j,k;
	int numCases;
	int row;
	char col;
	scanf("%d\n", &numCases);
	for(i = 0; i < numCases;i++){
		for(j = 1; j < 9; j++){
			for(k = 0; k < 8; k++){
				board[j][k] = -1;
			}
		}

		scanf("%c%d\n", &col, &row);
		// initialize the starting point
		board[row][col-'a'] = 0;
		next[0][0] = row;
		next[0][1] = col-'a';
		hunt();
	}
}