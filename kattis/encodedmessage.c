#include <stdio.h>
#include <math.h>
#include <string.h>

// read a message that has to be read top-to-bottom, right-to-left
// the input is a 1d char array that has to be parsed as if it were a 2d square array
int main(){
	int numCases;
	char message[10010];
	scanf("%d", &numCases);
	int i,j,k;
	int len;
	for(i = 0; i < numCases; i++){
		scanf("%s", message);
		len = sqrt(strlen(message));
		// j goes from right to left
		for(j = len - 1; j >= 0 ; j--){
			// k goes from top to bottom
			for(k = 0; k < len; k++){
				printf("%c", message[len*k+j]);
			}
		}
		printf("\n");
	}
}