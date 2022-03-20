#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
	Get the number of vowels in a string
*/
int main(){
	char s[85];
	int len, res = 0;

	fgets(s, 85, stdin);
	len = strlen(s);
	for(int i = 0; i < len; i++){
		s[i] = tolower(s[i]);
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			res++;
		}
	}
	printf("%d\n", res);
}