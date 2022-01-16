#include <stdio.h>
#include <string.h>

/*
	Morse code with 1 char: E T
	Morse code with 2 char: A I M N
	Morse code with 3 char: D G K O R S U W
	Morse code with 4 char: B C F H J L P Q V X Y Z _ , . ?

	There's no pattern to morse code, meaning I have to hard-code and burte force
	
*/
char morse[][5] = {
	// A-Z
	{".-"},
	{"-..."},
	{"-.-."},
	{"-.."},
	{"."},
	{"..-."},
	{"--."},
	{"...."},
	{".."},
	{".---"},
	{"-.-"},
	{".-.."},
	{"--"},
	{"-."},
	{"---"},
	{".--."},
	{"--.-"},
	{".-."},
	{"..."},
	{"-"},
	{"..-"},
	{"...-"},
	{".--"},
	{"-..-"},
	{"-.--"},
	{"--.."},
	{"..--"}, // _
	{"---."}, // .
	{".-.-"}, // ,
	{"----"}  // ?
};

// take the ciphertext in s, convert each letter to morse and store each morse string into m
// Also write each corresponding morse code length into l
void getMorse(char *s, char *m, int *l, int n){
	int i;
	m[0] = '\0';
	for(i = 0; i < n; i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			strcat(m, morse[s[i]-'A']);
			l[i] = strlen(morse[s[i]-'A']);
		}
		else if (s[i] == '_'){
			strcat(m, morse[26]);
			l[i] = 4;
		}
		else if (s[i] == '.'){
			strcat(m, morse[27]);
			l[i] = 4;
		}
		else if (s[i] == ','){
			strcat(m, morse[28]);
			l[i] = 4;
		}
		else if (s[i] == '?'){
			strcat(m, morse[29]);
			l[i] = 4;
		}
	}
}
// start at the end of m
// use l to determine where the last char in m starts
// compare that string to each morse string
// on match, set the last char in s to that morse char
// repeate
void decode(char *s, char *m, int *l, int n){
	int i,j,k;
	// length of morse code
	int len = strlen(m);
	// i decrements across s
	// k increments across l
	for(i = n-1, k = 0; i >= 0; i--, k++){
		// j increments across morse[]
		for(j = 0; j < 30;j++){
			// len - l[k] will tell me where the last char starts
			// if there's a match, set s[i] to the appropriate char
			if(strcmp(&m[len-l[k]], morse[j]) == 0){
				if(j < 26){
					s[i] = j+'A';
				}
				else if(j == 26){
					s[i] = '_';	
				}
				else if(j == 27){
					s[i] = '.';	
				}
				else if(j == 28){
					s[i] = ',';	
				}
				else if(j == 29){
					s[i] = '?';	
				}
				// now we 'discard' the decoded morse
				len -= l[k];
				m[len] = '\0';
				break;
			}
		}
	}
}
int main(){
	char s[1001];
	char m[4001];
	int l[1000];
	int len;
	while (scanf("%s", s) == 1){
		len = strlen(s);
		getMorse(s, m, l, len);
		decode(s,m,l,len);
		printf("%s\n", s);
	}

}