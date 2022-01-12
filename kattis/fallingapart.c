#include <stdio.h>
/*
	Given a set of numbers, get the sum of the greatest number + third greatest + fifth...
	and get the sum of the second greatest + fourth + ...
*/
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// using insertions sort tactics but tweaked so it's in descending order
void sort(int *arr, int n){
	int i,j;
	for(i = 1; i < n;i++){
		for(j = i; j > 0; j--){
			if (arr[j] > arr[j-1]){
				swap(&arr[j], &arr[j-1]);
			}
			else{
				break;
			}
		}
	}
}

int main(){
	int n,i, res1 = 0,res2 = 0;
	int arr[15];
	scanf("%d", &n);
	// get the numbers
	for(i = 0; i < n;i++){
		scanf("%d", &arr[i]);
	}
	// sort them
	sort(arr,n);
	// get everything in the even indices
	for(i = 0; i < n; i += 2){
		res1 += arr[i];
	}
	// get everything in the odd indices
	for(i = 1; i < n; i += 2){
		res2 += arr[i];
	}
	printf("%d %d\n", res1,res2);
}