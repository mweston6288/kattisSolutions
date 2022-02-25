#include <stdio.h>

/*
	A valid Danish ID has the following characterisitics:
		It is 10 digits organized as xxxxxx-xxxx
		The first 6 digits represent the date of birth
		The ID number follows a ceretain modulo rule
	modulo rule:
		Each digit is multiplied by a certain number depending on what spot it's in
			4,3,2,7,6,5,4,3,2,1
		Then the products are added together and modded by 11.
		If the sum % 11 == 0, it's a valid ID number

	Determine if a given ID number is valid

	To make life easier, I read in each digit as a char
*/

int main(){
	char id[10];
	int modifier[] = {4,3,2,7,6,5,4,3,2,1};
	int n = 0;
	// read each digit as a char
	scanf("%c%c%c%c%c%c-%c%c%c%c", &id[0],&id[1],&id[2],&id[3],&id[4],&id[5],&id[6],&id[7],&id[8],&id[9]);

	// convert the char to int and multiply each one by it's appropriate modifier
	for(int i = 0; i < 10; i++){
		n += (id[i] -'0') * modifier[i];
	}

	// if true, n was not divisible by 11
	if (n % 11){
		printf("0\n");
	}
	else{
		printf("1\n");
	}
	
}