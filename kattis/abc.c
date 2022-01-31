#include <stdio.h>
/*
	A < B < C; determine which of the three numbers is A,B, and C and then print them out in the given order

	Process:
		Store the numbers and the output order in an int array and string respectively
		Sort the int array
		Print the array based on the char values passed in
*/

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int a[3];
	char b[4];
	scanf("%d %d %d\n%s", &a[0], &a[1], &a[2], b);

	if(a[0] > a[1]){
		swap(&a[0], &a[1]);
	}
	if(a[1] > a[2]){
		swap(&a[1], &a[2]);
	}
	if(a[0] > a[1]){
		swap(&a[0], &a[1]);
	}

	printf("%d %d %d\n", a[b[0]-'A'], a[b[1]-'A'], a[b[2]-'A']);
}