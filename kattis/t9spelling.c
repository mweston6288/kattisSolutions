#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
	2 - ABC
	3 - DEF
	4 - GHI
	5 - JKL
	6 - MNO
	7 - PQRS
	8 - TUV
	9 - WXYZ
	0 - Space

	char c = a to r = (c-'a') / 3 + 2   (0 - 17)
	char c = s to y = (c-'a' - 1) / 3 + 2   (18 - 24)
	char c = z = 25
*/
// determines what keys to press to get c and stores result in ans
void getKeys(char c, char *ans){
	// num stores which key to press
	// freq stores the number of times to press - 1
	int i, num, freq;
	// check for space
	if(isalpha(c)){
		c -= 'a';
		// a - r
		if(c < 18){
			num = c / 3 + 2;
			freq = c % 3;
		}
		// s - y
		else if (c < 25){
			num = (c-1) / 3 + 2;
			freq = (c-1) % 3;
		}
		// z
		else {
			num = 9;
			freq = 3;
		}
		// special case for s
		if (c == 18){
			freq = 3;
		}
		// fill in ans
		for(i = 0; i <= freq;i++){
			ans[i] = num + '0';
		}
		ans[i] = '\0';
	}
	// space
	else{
		ans[0] = '0';
		ans[1] = '\0';
	}
}
int main(){
	int numCases;
	char s[1001];
	// stores the string to press for a letter
	char res[5];
	int len;
	int i,j;
	// stores the previous key pressed. Let's us know whether there needs to be a pause
	char prev;
	// gotta be delicate with how we get the case number because a string could start with ' '
	// this will consume the number
	scanf("%d", &numCases);
	// this will consume the '\n'
	// if the first string starts with ' ', the file pointer will be on it now
	getc(stdin);
	for(i = 1; i <= numCases;i++){
		fgets(s, 1002, stdin);
		len = strlen(s);
		// ignore any consumed line breaks
		if(s[len-1] == '\n'){
			len--;
		}
		
		getKeys(s[0], res);
		prev = res[0];
		printf("Case #%d: %s", i, res);
		for(j = 1; j < len;j++){
			getKeys(s[j], res);
			printf("%s%s", res[0] == prev ? " " : "", res);
			prev = res[0];			
		}
		printf("\n");
	}
}