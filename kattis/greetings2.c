#include <stdio.h>
#include <string.h>

// given a string of "hey" with 1 or more e's in it, print "hey" with twice ans many e's

// approach taken: remove the y at the end of the greeting.
// Then pass the greeting, concatenated with the greeting starting at the first e, concatenated with y
int main(){
	char greeting[1010];
	scanf("%s", greeting);
	int len = strlen(greeting);
	greeting[len - 1]= '\0'; // remove the 'y' at the end
	printf("%s%sy\n", greeting, &(greeting[1]));
}