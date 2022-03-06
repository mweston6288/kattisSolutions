#include <stdio.h>

int main(){
	int n, k, i, j, lowest, res;
	int seq[1001] = {0};
	// read in n and k
	scanf("%d %d", &n, &k);
	// read in each number and track the number of times they appear
	for(i = 0; i < n; i++){
		scanf("%d", &j);
		seq[j]++;
	}
	// initialize the search for least appearing number
	lowest = seq[1];
	res = 1;
	for(i = 2; i <= k; i++){
		// reset the count
		if(seq[i] < lowest){
			lowest = seq[i];
			res = 1;
		}
		// up the count
		else if(seq[i] == lowest){
			res++;
		}
	}
	printf("%d\n", res);
	// find and print the very first least-occuring number
	for(i = 1; i <= k; i++){
		if(seq[i] == lowest){
			printf("%d", i);
			break;
		}
	}
	// continue and print the rest
	for(i++; i <= k; i++){
		if(seq[i] == lowest){
			printf(" %d", i);
		}
	}
	printf("\n");
}