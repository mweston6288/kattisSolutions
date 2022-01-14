#include <stdio.h>
/*
	player control shifts after n rounds. Each round awards 1 point
	After 2n rounds, control shifts back to player 1.
	(p+q) % (2n) tells us how far we are in the cycle
	Dividing that result by n will give us 
		0 if we're in the first half (Paul is serving)
		1 if we're in the second half (opponent is serving)
*/
int main(){
	int n,p,q;
	scanf("%d %d %d", &n, &p, &q);
	p += q;
	p %= (n*2);
	p /= n;
	if(p){
		printf("opponent\n");	
	}
	else{
		printf("paul\n");
	}
}