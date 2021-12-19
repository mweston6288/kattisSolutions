#include <stdio.h>

// I'm supposed to scan a 3 letter abbreviation of a month
// and check if it is OCT or DEC, but those are the only months
// that start with an O or D so I'm just checking the first letter.
int main(){
	char month[4];
	int day;
	scanf("%s %d", month, &day);
	if((month[0] != 'O' || day != 31) && (month[0] != 'D' || day != 25)){
		printf("nope\n");
	}
	else{
		printf("yup\n");
	}
}