#include <stdio.h>
#include <string.h>

/*
	Decode a message where after every vowel, a 'p' and another copy of the vowel is printed
*/

int main(){
	char s[101];
	int len,i;
	fgets(s, 101, stdin);
	len = strlen(s);
	i = 0;
	while (i <len){
		printf("%c", s[i]);
		// If I read a vowel, skipp the next two chars
		if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ){
			i+=3;
		}
		else{
			i++;
		}
	}
	printf("\n");
}