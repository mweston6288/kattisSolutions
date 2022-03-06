#include <stdio.h>
/*
	Given n orders for x-shot espressos and x-shot lattes and a container with s ounces of water,
	determine how many times the container gets refilled.

	The container is refilled every time an order requires more water than in currently in the container
	
	an x-shot espresso uses x ounces of water
	an x-shot latte uses x+1 ounces

	All espresso orders are represented by the number of shots
	All latte orders are represented by the number of shots followed immediately by 'L'
*/
int main(){
	int n, s, x, res, used, i;
	char c;

	scanf("%d %d", &n, &s);
	res = 0;
	used = 0;

	for(i = 0; i < n; i++){
		// scan the number of shots and the next immediate char
		// if the order is an espresso, then c will be either '\n' or EOF
		scanf("%d%c", &x, &c);
		// it's a latte. Increment x
		if (c == 'L'){
			x++;
		}
		// if there's not enough water, refill the container and then take out the amount needed
		if(used + x > s){
			res++;
			used = x;
		}
		// there's enough water so just take what is needed
		else{
			used += x;
		}
	}
	printf("%d\n", res);
}