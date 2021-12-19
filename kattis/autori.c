#include <stdio.h>
#include <string.h>
// we're printing the first letter of each name passed in
// Since the format is Name1-Name2-Name3...
// I'm going to check for - rather than if the letter is capitalized
int main(){
	char names[100];
	scanf("%s", names);
	int len = strlen(names);
	
	// First letter of the string needs to be printed
	printf("%c", names[0]);
	int i;

	for(i = 0; i < len; i++){
		// If I find a -, the next char is the first letter of a name
		if (names[i] == '-'){
			printf("%c", names[++i]);
		}
	}
	printf("\n");
}