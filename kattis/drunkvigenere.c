#include <stdio.h>
#include <string.h>
/*
	Decrypt messages encrypted with a midifed Vigenere cipher
	Every even index is shifted up but every odd index is shifted down during encryption
*/
int main(){
	char ciphertext[202];
	char key[202];
	scanf("%s\n%s", ciphertext, key);
	int len = strlen(key);

	for(int i = 0; i < len; i++){
		// Alternate way to check for odd
		if (i & 1){
			printf("%c", (ciphertext[i]+key[i]) % 26 +'A');
		}
		else{
			printf("%c", (ciphertext[i] + 26 - key[i]) % 26 + 'A');
		}
	}
	printf("\n");
}