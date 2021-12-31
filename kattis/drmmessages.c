#include <stdio.h>
#include <string.h>
/*
	A given encrypted message requires the following steps to decrypt it:
		1) split the message in two even halves
		2) sum the values of each character in each half (A=0, B=1, etc)
		3) increment each character by that half's sum from step 2
		4) increment each character in the first half by the number value of the corresponding character in the second half
		5) The first half is the plaintext
	Decrypt the message.

	Several action in this solution are for the sake of reducing the amount of work done
*/
int main(){
	char message[15003];
	scanf("%s", message);

	// I keep the entire message in one string,
	// so I use halflen to determine where the first half ends
	// Now I don't have to do any math work to keep track of things
	int len = strlen(message);
	int halflen = len / 2;

	int rot1=0,rot2=0, i;

	// initially, I'm just going to get the raw ASCII values of each char
	// Because of how mod equivalence works, I don't have to actually subtract 'A'
	// along the way cause the end values of rot1 and rot2 will be equivalent under mod 26
	// to whatever I would have gotten if I did
	for(i = 0; i < halflen;i++){
		rot1 += message[i];
	}
	// since i is guarateed to be at the first index of the second half
	// I'm not going to initialize it here
	for(;i<len;i++){
		rot2 += message[i];
	}

	// Now I add the rotation to each char
	// If I added 'A' at this point, I'd have to remove it again in the next step
	// so I just keep each char in whatever junk value state it's in and fix it later
	for(i = 0; i < halflen;i++){
		message[i] = (message[i] + rot1) % 26;
	}

	for(;i<len;i++){
		message[i] = (message[i] + rot2) % 26;
	}
	// Now I add the values of the two halves together.
	// At this point, I'm going to add 'A' to put the chars in range of ASCII's uppercase chars
	for(int j = halflen, i = 0; i < halflen; i++, j++){
		message[i] = (message[i] + message[j]) % 26 + 'A';
	}
	// Only the first half of the encrypted message is the final message
	message[halflen] = '\0';

	printf("%s\n", message);
}