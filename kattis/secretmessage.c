#include <stdio.h>
#include <string.h>
#include <math.h>
/*
	encrypt a message by storing the message in the smallest possible NxN square and reading it bottom-to-top,
	left-to-right
*/
int main(){
	char message[10001];
	char cipher[10022];
	int numCases,i,j,k,l,len, ciLen;
	
	scanf("%d", &numCases);

	for(i = 0; i < numCases;i++){
		scanf("%s\n", message);
		len = strlen(message);
		// calculates the dimensions of the square
		ciLen = (int)ceil(sqrt(len));
		/*
			j iterates through each letter in the plaintext
			k determines what row to put message[j], higher k means it goes more downward
			l determines what column to put it in, higher l means more leftward

			if ciLen is 4, the fill pattern is
			4,8,12,16,3,7,11,15,...
			
		*/
		for(j = 0,k = 1,l = 0; j < len;j++){
			cipher[ciLen*k - l] = message[j];
			if(++k > ciLen){
				l++;
				k = 1;
			}
		}
		// for the excess spaces, pad with '*'
		for(j = ciLen*ciLen; j > len;j--){
			cipher[ciLen*k - l] = '*';
			if(++k > ciLen){
				l++;
				k = 1;
			}
		}
		// I don't need the square root anymore so now I'll get the full length of the ciphertext
		ciLen *= ciLen;
		// print all non-'*' chars
		for(j = 1; j <= ciLen;j++){
			if(cipher[j] != '*'){
				printf("%c", cipher[j]);
			}
		}
		printf("\n");

	}
}