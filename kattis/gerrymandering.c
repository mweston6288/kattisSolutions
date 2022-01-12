#include <stdio.h>
#include <stdlib.h>
/*
	For a set of votes across districts, determine the winner, the wasted votes of both parties,
	and the efficiency gap of the wasted votes

	efficiency gap = abs(wastedVotesA - wastedVotesB) / totalVotes
*/

int main(){
	int p,d,i;
	int votes[1001][2];
	// these will have multiple uses through the program
	int x,a,b;
	scanf("%d %d", &p,&d);
	// initialize each districts vote count
	for(i = 1; i <= d;i++){
		votes[i][0] = votes[i][1]= 0;
	}
	// read in the votes
	for(i = 0; i < p; i++){
		// for now, use x,a,and b to store the inputs
		scanf("%d %d %d", &x,&a,&b);
		votes[x][0] += a;
		votes[x][1] += b;		
	}
	// a will now be used to track the number of wasted votes for party a
	// b will be used to track the wasted votes for party b
	a = 0;
	b = 0;
	for(i = 1; i <= d;i++){
		// x stores the threshold needed to win
		// excess above that is wasted
		x = (votes[i][0]+votes[i][1]) / 2 + 1;
		// a wins
		if(votes[i][0] > votes[i][1]){
			// excess votes when A wins
			printf("A %d %d\n", votes[i][0] - x, votes[i][1]);
			// total excess votes;
			a += votes[i][0] - x;
			b += votes[i][1];
		}
		// b wins
		else{
			printf("B %d %d\n", votes[i][0], votes[i][1] - x);
			a += votes[i][0];
			b += votes[i][1] - x;
		}
	}
	// now x will be used to track total votes;
	x = 0;
	for(i = 1; i <= d;i++){
		x += votes[i][0]+votes[i][1];
	}
	printf("%.10lf\n", abs(a - b) / (x*1.0));
}