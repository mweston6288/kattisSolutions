#include <stdio.h>
#include <string.h>
/*
	Given an integer, determine how many digits it has

	The possible numbers tested can far exceed even a long long int.
	The trick is to store the number as a string instead and just return strlen(num)
*/

int main(){
	int numCases, i; 
	char num[102];
	scanf("%d", &numCases);
	for(i = 0; i < numCases; i++){
		scanf("%s\n", num);
		printf("%ld\n", strlen(num));
	}
}