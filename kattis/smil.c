#include <stdio.h>
#include <string.h>

// given a string, find the indices that are the beginning of a smile emoji or winking smile emoji
// valid strings: :), :-), ;), ;-)
int main(){
	int i;
	char c[2050];
	fgets(c, 2049, stdin);
	int len = strlen(c);
	for(i = 0; i < len; i++){
		// Gotta look for these first
		if(c[i] == ':' || c[i] == ';'){
			// check wha comes after. If it's good, we have to increment i accordingly
			if(c[i+1] == '-' && c[i+2] == ')'){
				printf("%d\n", i);
				i+=2;
				continue;
			}
			if(c[i+1] == ')'){
				printf("%d\n", i);
				i++;
			}
		}
	}
}