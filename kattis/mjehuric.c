#include <stdio.h>
/*
	Show the progress of bubble sorting a 5-int array
*/
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int *arr){
	for(int i = 0; i < 4;i++){
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[4]);
}
int main(){
	int arr[5];
	scanf("%d %d %d %d %d", &arr[0],&arr[1],&arr[2],&arr[3],&arr[4]);
	int i,j;
	for(i = 0; i < 4;i++){
		for(j = 0; j < 4-i;j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				printArr(arr);
			}
		}
	}
}