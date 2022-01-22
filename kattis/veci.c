#include <stdio.h>
/*
	Given an int n, find the next number that would have the exact same digits
	Process:
		Start at 10s place digit. If it is less than 1s place, swap and return
		Else, check if 100s place digit is less than the 10s place digit.
		If it is, find the smallest digit greater than the current 100s place digit and swap them.
		Then sort all the digits after the 100s place.
		Repeat process, comparing the 10^n's place digit with the 10^(n-1)s place digit until success or all have failed

	The number is stored as a char array to make it easier to manipulate each digit
*/
void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}
// find which digit should be placed in num[n]
// sort the remaining digits and print the number
void getNextNum(char *num, int n, int len){
	int i,j, smallest = n+1;
	// get smallest digit > num[n]
	for(i = n+2; i < len;i++){
		if(num[i] < num[smallest] && num[i] > num[n]){
			smallest = i;
		}
	}
	// set that digit into num[n]
	swap(&num[n], &num[smallest]);
	// sort every index after n using insertion sort
	for(i = n+2; i < len;i++){
		for(j = i; j > n+1; j--){
			if(num[j] < num[j-1]){
				swap(&num[j], &num[j-1]);
			}
		}
	}
	// print
	for(i = 0; i < len;i++){
		printf("%c", num[i]);
	}
	printf("\n");
}
// takes an int and char array and creates a char array equivalence of n
// returns the length of the array
int intToChar(int n, char *arr){
	// base case: insert into index 0 and return length of 1
	if(n < 10){
		arr[0] = n+'0';
		return 1;
	}
	// get the next index to insert a value into
	int i = intToChar(n/10, arr);
	// insert next digit
	arr[i] = n % 10 + '0';
	// return length
	return i + 1;
}
int main(){
	char num[7];
	int len = 0;
	int i = 0;
	scanf("%d", &len);
	len = intToChar(len, num);

	for(i = len - 2; i >= 0; i--){
		if(num[i] < num[i+1]){
			getNextNum(num, i , len);
			return 0;
		}		

	}
	printf("0\n");
}