#include <stdio.h>
/*
	Determine how often a number is bigger than the previous number in sequence
*/
int main(){
	int n;
	int prev,curr;
	int res = 1;
	scanf("%d", &n);
	int nums[100000];
	
	scanf("%d", &nums[0]);	
	for(int i = 1; i < n;i++){
		scanf("%d", &nums[i]);
		if(nums[i] > nums[i-1]){
			res++;
		}
	}
	printf("%d\n", res);
}