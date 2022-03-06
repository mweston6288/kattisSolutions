#include <stdio.h>
#include <stdlib.h>

/*
	Given n combinations of 5 integers in range [100,499], determine how many of the combinations
	appear most frequently.

	The answer should equal b*t where b is the highest frequency of a combination and t is the total
	number of combinations that appeared b times. In other words, ties for first place are added together

	General Process:
		Scan all the values
		Use insertion sort to sort the 5 numbers in each combination
		Use Counting/Radix sort to sort each set
		Compare each set to the previous set
*/

// radix/counting sort
// classes is sorted using counting sort on the very last index of each combination
// then it is sorted based on the second last, etc
void superSort(int **classes, int n){
	int *output[n];
	// since the number range is [100, 499], I need 400 cells
	int i, count[400];

	for (int index = 4; index >= 0; index--){
		// initialize counting array
		for(i = 0; i < 400; i++){
			count[i] = 0;
		}
		// count how many elements have particular values at particular indices
		// subtract 100 because smallest possible value is 100
		for (i = 0; i < n; i++)
			count[classes[i][index] - 100]++;
	
		// set count value
		for (i = 1; i < 400; i++)
			count[i] += count[i - 1];


		// copy array to an aux array
		for (i = n - 1; i >= 0; i--) {
			output[--count[classes[i][index] - 100]] = classes[i];
		}
		// copy it back in
		for (i = 0; i < n; i++){
			classes[i] = output[i];
		}
	}
}
// insertion sort the numbers in each individual combination
// then pass to superSort to sort the combinations themselves
void sort(int **classes, int n){
	int i,j,k,temp;
	for(i = 0; i < n; i++){
		for(j = 1; j < 5; j++){
			for(k = j; k > 0; k--){
				if(classes[i][k] < classes[i][k-1]){
					temp = classes[i][k];
					classes[i][k] = classes[i][k-1];
					classes[i][k-1] = temp;
				}
			}
		}
	}

	superSort(classes, n);
}
// returns product of highest frequency of a combination * total number of combinations with that frequency
// assumes classes is in sorted order
int getMostCommon(int **classes, int n){
	// best: highest frequency
	// totalBest: number of combinations with that frequency
	// current: number of times the current combination was seen
	int best, totalBest, current, i;
	// initialize to 1 for the first element
	best = 1;
	totalBest = 1;
	current = 1;
	for(i = 1; i < n; i++){
		// all elements in classes[i] and classes[i-1] match
		if(classes[i][0] == classes[i-1][0] && classes[i][1] == classes[i-1][1] && classes[i][2] == classes[i-1][2] && classes[i][3] == classes[i-1][3] && classes[i][4] == classes[i-1][4]){
			current++;
		}
		// they did not match so classes[i] is a new combination to count
		else{
			current = 1;
		}
		// the current combination has reached the current max frequency so the total needs to be incremented
		if(current == best){
			totalBest++;
		}
		// the current has overtaken the previous best so this is now the only set with the best frequency
		else if(current > best){
			best = current;
			totalBest = 1;
		}
	}
	return best * totalBest;
}

int main(){
	int n, i;
	scanf("%d\n", &n);
	// It will be more practical to use int pointers to store the arrays since the arrays
	// will get moved around
	int **classes = malloc(sizeof(int*) * n);
	for(i = 0; i < n; i++){
		classes[i] = malloc(sizeof(int) * 5);
	}
	// scan values
	for(i = 0; i < n; i++){
		scanf("%d %d %d %d %d\n", &classes[i][0], &classes[i][1], &classes[i][2], &classes[i][3], &classes[i][4]);
	}
	sort(classes, n);

	printf("%d\n", getMostCommon(classes, n));
	// cleanup
	for(i = 0; i < n; i++){
		free(classes[i]);
	}
	free(classes);
}