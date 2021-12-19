#include <stdio.h>
#include <string.h>
// removes repeating sequential characters in a string
// logic is to compare each char to the previous char
// if they match, do nothing, otherwise print it
int main(){
	char name[252];
	int i;
	scanf("%s", name);
	int len = strlen(name);
	
	// There's guaranteed to be one letter and it would have to be printed
	printf("%c", name[0]);
	for(i = 1; i < len; i++){
		if (name[i] == name[i-1]){
			continue;
		}
		printf("%c", name[i]);
	}
	printf("\n");

}