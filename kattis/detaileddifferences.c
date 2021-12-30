#include <stdio.h>
#include <string.h>

/*
	Given a pair of strings, print '.' for each matching character and '*' for the non-matching chars
*/
int main(){
	int numCases;
	scanf("%d", &numCases);
	char s1[52],s2[52],res[52];
	int len, j;

	for(int i = 0; i < numCases;i++){
		scanf("%s\n%s", s1,s2);
		len = strlen(s1);
		for(j = 0; j < len; j++){
			if (s1[j] == s2[j]){
				res[j] = '.';
			}
			else{
				res[j] = '*';
			}
		}
		res[j] = '\0';
		printf("%s\n%s\n%s\n\n", s1,s2,res);
	}
}