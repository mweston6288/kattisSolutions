#include <stdio.h>
#include <string.h>
/*
	Scan each string and print how many of them do not have a 'C' followed by a 'D'
*/
int main(){
	int numCases;
	int i, j, len, res = 0;
	char c[1001];

	scanf("%d\n", &numCases);
	for(i = 0; i < numCases;i++){
		scanf("%s", c);
		len = strlen(c);
		for(j = 1; j < len; j++){
			if(c[j-1] == 'C' && c[j] == 'D'){
				break;
			}
		}
		if(j == len){
			res++;
		}
	}
	printf("%d\n", res);
}