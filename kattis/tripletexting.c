#include <stdio.h>
#include <string.h>
/*
	Given a string repeated 3 times where some letters might be replaced, determine the intended string
*/
int main(){
	char s[100];
	scanf("%s", s);
	// the string is repeated 3 times so len should be divided by 3
	int len = strlen(s) / 3;
	int i,j,k;
	for(i = 0, j = len, k = 2*len; i < len;i++,j++,k++){
		// if any two instances repeat the same char, it's understood that was the intended letter
		if (s[i] == s[j] || s[i] == s[k]){
			printf("%c", s[i]);
		}
		else{
			printf("%c", s[j]);
		}
	}
	printf("\n");
}