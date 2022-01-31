#include <stdio.h>
/*
	After being given a number n, find the first number m such that m % n == 0
	After finding m, the  next number rad becomes the new n

	I used a nested loop for this, however both loops are used to track how many scans were done. SO they both
	increment i. The outer loop reads in n, then the inner loop reads in m

*/
int main(){
	int num, i, n, m;
	scanf("%d", &num);

	// outer loop will read in n, then have the inner loop read m
	// since m will exit on a break command, i needs to be incremented each loop
	for(i = 0; i < num; i++){
		scanf("%d", &n);
		// start at i++ (since the outer loop did one read that hasn't been updated by i)
		// read numbers until we get a match
		for(i++; i < num; i++){
			scanf("%d", &m);
			if(!(m % n)){
				printf("%d\n", m);
				// this will skip the i++ command so the outer loop will take care of it
				break;
			}
		}
	}
}