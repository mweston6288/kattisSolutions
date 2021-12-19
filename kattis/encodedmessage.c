#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
	int numCases;
	char message[10010];
	scanf("%d", &numCases);
	int i,j,k;
	int len;
	for(i = 0; i < numCases; i++){
		scanf("%s", message);
		len = sqrt(strlen(message));
		for(j = len - 1; j >= 0 ; j--){
			for(k = 0; k < len; k++){
				printf("%c", message[len*k+j]);
			}
		}
		printf("\n");
	}
}