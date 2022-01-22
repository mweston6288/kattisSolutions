#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
	Encrypt a message by reverising the string and rotating each char by a certain amount
	The string includes _ and .
*/
int main(){
	int r,i, len;
	char m[41];
	scanf("%d ", &r);

	while (r != 0){
		scanf("%s\n", m);
		len = strlen(m);
		// encryption process: convert each char into a number from 0 to 27
		// add the rotation, mod it by 28 and then reconvert to char
		for(i = 0; i <len;i++){
			// convert to rotation value and cipher value
			if(isalpha(m[i])){
				m[i] = (m[i] - 'A' + r) % 28;
			}
			else if(m[i] == '_'){
				m[i] = (26 + r) % 28;
			}
			else{
				m[i] = (27 + r) % 28;
			}
			// convert back to char
			if(m[i] < 26){
				m[i] += 'A';
			}
			else if(m[i] == 26){
				m[i] = '_';
			}
			else{
				m[i] = '.';
			}
		}
		// Don't bother actually inverting the string
		// just print it backward
		for(i = len - 1; i >= 0;i--){
			printf("%c", m[i]);
		}
		printf("\n");
		scanf("%d ", &r);
	}
}