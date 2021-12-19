#include <stdio.h>

// we want to biggest rectangle possible given that we draw lines with four given lengths
// the biggest possible rectangle happens when the smallest two are parallel to each other
// and the largest two are parallel to each other
// So the biggest rectangle has a length = the smallest value and height = second largest

// we're working with only 4 numbers so insertion sort is fine
void sort(int *arr){
	int i,j,temp;
	for(i = 0; i < 3; i++){
		for(j = i+1; j > 0; j--){
			if(arr[j] < arr[j-1]){
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
			else{
				break;
			}
		}
	}
}

int main(){
	int arr[4];
	scanf("%d %d %d %d", &arr[0],&arr[1],&arr[2],&arr[3]);
	sort(arr);
	printf("%d\n", arr[0]*arr[2]);
}