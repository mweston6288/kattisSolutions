#include <stdio.h>
/*
	Given a set of intevals, find the largest subset that has no overlaps

	The algorithm for this problem is to first sort the list by completion time.
	Then take the first interval that finishes, then find the next interval that starts after it finishes.
	Then find the next interval that starts after that one finishes, etc.

	I used radix sort for this one just cause I wanted to get the runtime as low as possible. 
	This solution got .03 runtime on kattis
*/
// I'm just going to make this a global
int intervals[100000][2];

void sort(int n, int max){
	int output[n][2];
	int i, count[10];

	for (int exp = 1; max / exp > 0; exp *= 10){
		// initialize counting array
		for(i = 0; i < 10;i++){
			count[i] = 0;
		}
		// count how many elements have particular values at particular digits
		for (i = 0; i < n; i++)
			count[(intervals[i][1] / exp) % 10]++;
	
		// set count value
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		// the same formula would happen so often that I might as well save it in a variable to save time
		int x;
		// copy array to an aux array
		for (i = n - 1; i >= 0; i--) {
			x = intervals[i][1] / exp % 10;
			output[--count[x]][0] = intervals[i][0];
			output[count[x]][1] = intervals[i][1];
		}
		// copy it back in
		for (i = 0; i < n; i++){
			intervals[i][0] = output[i][0];
			intervals[i][1] = output[i][1];
		}
	}
}


int getRes(int n){
	// the first element will be the first to finish
	int next = intervals[0][1];
	int res = 1;
	int i,j;
	// find the next interval that starts after the current one
	for(int i = 1; i < n; i++){
		if(intervals[i][0] >= next){
			res++;
			next = intervals[i][1];
		}
	}
	return res;
}

int main(){

	int num,i;
	int max = 0;
	scanf("%d", &num);

	for(i = 0; i < num;i++){
		scanf("%d %d", &intervals[i][0], &intervals[i][1]);
		// get the max ending index for radix sort
		if(intervals[i][1] > max){
			max = intervals[i][1];
		}
	}
	sort(num,max);

	printf("%d\n",getRes(num));
}