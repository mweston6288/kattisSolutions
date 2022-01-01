#include <stdio.h>
#include <stdlib.h>
/*
	An autokey cipher is a figenere cipher, but the plaintext is appended to the key as well

	Given a ciphertext and the last few letters of the plaintext, which is the exact length of the key,
	decrypt the message

	Since this cipher uses the plaintext to encrypt, finding the key used to encrypt a plaintext letter
	into a ciphertext letter is the same thing as decrypting an earlier plaintext
*/

int main(){
	int keyLength, cipherLength;
	char *plaintext,*cipherText;
	scanf("%d %d\n", &keyLength, &cipherLength);
	// The plaintext is the same length as the ciphertext
	plaintext = malloc(sizeof(char)*(cipherLength+1));
	cipherText = malloc(sizeof(char)*(cipherLength+1));
	// store the known plaintext at the end of the plaintext string
	scanf("%s\n%s", &(plaintext[cipherLength - keyLength]), cipherText);
	char c;
	for (int i = cipherLength - 1; i >= keyLength; i--){
		// get the cipherKey that encrypted this letter
		// this key letter is part of the unknown plaintext
		c = (cipherText[i] + 26 - plaintext[i]) % 26 + 'a';
		plaintext[i - keyLength] = c;
	}
	printf("%s\n", plaintext);
}