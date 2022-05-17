#include <stdio.h>
#include <stdlib.h>
/*
	The marketability coefficient of a person is defined as their popularity factor - their success factor
	Popularity factor is defined as how popular they are compared to other people in a group
	Success factor is the number of friends they have in the group

	Given n people with m friendships between them, determine their marketability coefficient
	People represented with a smaller number are more successful. Person 1 is more successful than person 2

	If person 3 has 5 friends, they have a marketability coefficient of 2.

	The problem essentially wants me to find out how many times a certain number appears
	and then print that result minus the number itself.


*/
int main(){
	int n, m, l, k, i;
	int *pop;
	scanf("%d %d", &n, &m);
	pop = malloc(sizeof(int) * (n+1));
	
	// read in each pair of connections and increment the person
	for(i = 0; i < m; i++){
		scanf("%d %d", &l, &k);
		pop[l]++;
		pop[k]++;
	}

	// print their marketability 
	printf("%d", pop[1] - 1);
	for(i = 2; i<= n; i++){
		printf(" %d", pop[i] - i);
	}
	printf("\n");
	free(pop);
}