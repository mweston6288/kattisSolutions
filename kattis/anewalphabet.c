#include <stdio.h>
#include <ctype.h>
/*
	Convert into 1337speak. THe actual convertion process is broken down into somewhat smaller problems
	so that there are fewer checks needed to be made
*/
void print1337(char c){
	// a - m
	if(c-'a' < 13){
		// a - f
		if (c-'a' < 6){
			if (c == 'a'){
				printf("@");
			}
			if (c == 'b'){
				printf("8");
			}
			if (c == 'c'){
				printf("(");
			}
			if (c == 'd'){
				printf("|)");
			}
			if (c == 'e'){
				printf("3");
			}
			if (c == 'f'){
				printf("#");
			}
		}
		// g - m
		else{
			if (c == 'g'){
				printf("6");
			}
			if (c == 'h'){
				printf("[-]");
			}
			if (c == 'i'){
				printf("|");
			}
			if (c == 'j'){
				printf("_|");
			}
			if (c == 'k'){
				printf("|<");
			}
			if (c == 'l'){
				printf("1");
			}
			if (c == 'm'){
				printf("[]\\/[]");
			}

		}
	}
	// n - z
	else{
		// n - s
		if (c-'a' < 19){
			if (c == 'n'){
				printf("[]\\[]");
			}
			if (c == 'o'){
				printf("0");
			}
			if (c == 'p'){
				printf("|D");
			}
			if (c == 'q'){
				printf("(,)");
			}
			if (c == 'r'){
				printf("|Z");
			}
			if (c == 's'){
				printf("$");
			}
		}
		// t - z
		else{
			if (c == 't'){
				printf("']['");
			}
			if (c == 'u'){
				printf("|_|");
			}
			if (c == 'v'){
				printf("\\/");
			}
			if (c == 'w'){
				printf("\\/\\/");
			}
			if (c == 'x'){
				printf("}{");
			}
			if (c == 'y'){
				printf("`/");
			}
			if (c == 'z'){
				printf("2");
			}

		}
	}
}

int main(){
	char s[10010];
	int i = 0;
	fgets(s,10010, stdin);
	while(s[i] != '\0'){
		if(!isalpha(s[i])){
			printf("%c", s[i]);
		}
		else{
			print1337(tolower(s[i]));
		}
		
		i++;
	}
}