#include <stdio.h>
#include <string.h>
/*
	Given a series of commands, print on the commands that start with "Simon says" and remove
	"Simon says" from the beginning
	
	Since I'm looking for a specific starting sequence, I would modify the string so I only
	look at the first 11 chars since that's the length of "Simon says".
	If those first 11 match to the string, I print the rest of the string
*/
int main(){
	char s[103];
	int num;
	scanf("%d\n", &num);
	for(int i = 0;i < num;i++){
		// get the whole command
		fgets(s, 101, stdin);
		// cut off the point where "Simon says" would definitely end
		s[10] = '\0';
		if(!strcmp(s, "Simon says")){
			// if true, print out the rest of the string
			printf(" %s", &s[11]);
		}
	}
}