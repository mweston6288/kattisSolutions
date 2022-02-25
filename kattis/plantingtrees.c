#include <stdio.h>
/*
	Determine the minimum number of days needed to get a set of trees to grow to adulthood
	Only one tree is planted per day, growth doesn't begin until the day after it is planted
	and is not considered complete until the day after the growth period

	Solution: Sort all growth times in non-ascending order. Growth time is equal to which
	day a plant was planted + its growth time

	Answer is whichever sum is highest
*/
// helper function for radixsort, gets the max value of s
// to determine how many runs are necessary
int max(int *s, int n){
	int max = s[0];
	for(int i = 1; i < n; i++){
		if(s[i] > max){
			max = s[i];
		}
	}
	return max;
}
// radix sort
void sort(int *s, int n){
	int output[n];
	int i, count[10];
	int x;
	int maxValue = max(s,n);

	for (int exp = 1; maxValue / exp > 0; exp *= 10){
		// initialize counting array
		for(i = 0; i < 10;i++){
			count[i] = 0;
		}
		// count how many elements have particular values at particular digits
		for (i = 0; i < n; i++){
			count[(s[i] / exp) % 10]++;
		}
	
		// set count value
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		// copy array to an aux array
		for (i = n - 1; i >= 0; i--) {
			x = s[i] / exp % 10;
			output[--count[x]] = s[i];
		}
		// copy it back in
		for (i = 0; i < n; i++){
			s[i] = output[i];
		}
	}
}
int main(){
	int num, day = 0, tree, i;
	int seeds[100000];
	scanf("%d", &num);
	// read all values
	for(i = 0; i < num; i++){
		scanf("%d", &seeds[i]);
	}
	sort(seeds, num);
	// determine what day the last tree finishes growing
	for(i = 0; i < num; i++){
		if(day < seeds[num-i-1]+i){
			day = seeds[num-i-1]+i;
		}
	}
	// add 2 to compensate for using 0 indexing when counting and how the solution is the day
	// AFTER all plants finish growing
	printf("%d\n", day + 2);
}