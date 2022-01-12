#include <stdio.h>
#include <string.h>
/*
	Determine if a number passes Luhn's checksum.
	For every other digit of n, add the sum of the digits you get from multplying di * 2
	For the other digits, just add them together
	If the result is divisible by 10, it passes the checksum

	Because the numbers passed in can go up to 10^51 - 1, I have to read numbers in as strings.
*/
int checkValid(char *n){
	int res = 0;
	int len = strlen(n);
	int m,i;
	// this will just add the odd indices to res
	for(i = len - 1; i >= 0; i-=2){
		res += n[i]-'0';
	}
	// this will multipply the even indices by 2 and add their digit values
	for(i = len - 2; i >= 0; i-=2){
		m = (n[i] - '0') * 2;
		res += (m % 10 + m / 10);
	}
	return res % 10 == 0;
}
int main(){
	int numCases;
	// stores the number as a string
	char n[51];
	scanf("%d", &numCases);
	for(int i = 0; i < numCases;i++){
		scanf("%s\n", n);
		if(checkValid(n)){
			printf("PASS\n");
		}
		else{
			printf("FAIL\n");
		}
	}	
}