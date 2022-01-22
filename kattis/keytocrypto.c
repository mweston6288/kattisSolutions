#include <stdio.h>
#include <string.h>
/*
	Decrypt an autokey cipher
*/
int main(){
	char ciphertext[501];
	char key[501];
	int cLen, kLen;
	scanf("%s\n%s", ciphertext, key);
	cLen = strlen(ciphertext);
	kLen = strlen(key);

	for (int i = 0; i < cLen; i++){
		// convert the ascii char to its cipher value
		// reverse rotate by the key cipher value
		// revert from cipher value to ascii value
		ciphertext[i] = (ciphertext[i] - 'A' + 26 - (key[i] - 'A')) % 26 + 'A';
		// add the decrypted letter to the end of the key
		if(kLen < cLen){
			key[kLen++] = ciphertext[i];
		}
	}
	printf("%s\n", ciphertext);
}