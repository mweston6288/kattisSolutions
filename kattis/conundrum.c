#include <stdio.h>
#include <string.h>

// Given a string, how many changes have to occur before the
// string is just "PER" repeated over and over
int main(){
	char message[303];
	scanf("%s", message);
	int i, res = 0, len = strlen(message);

	// The string is evaluated in 3-char blocks
	// If each index already has the necessary char, ignore it
	for(i = 0; i< len; i +=3){
		if (message[i] != 'P')
			res++;
		if (message[i+1] != 'E')
			res++;
		if (message[i+2] != 'R')
			res++;			
	}
	printf("%d\n", res);
}