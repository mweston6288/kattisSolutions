#include <stdio.h>
#include <ctype.h>

/*
	Determine the possible major scale of a song given a set of notes

	THe notes are stored in scales[]. lowercase refer to the note's sharp. upper case is the note
	Example: 'a' refers to A#, while 'A' refers to A

	major stores which notes are in each major

*/
#define SCALELEN 12
#define MAJORLEN 7

char scales[] = "AaBCcDdEFfGg";
int major[] = {2,4,5,7,9,11,0};

int main(){
	int n,i,j,k;
	char s[2];
	int bools = 4095;
	scanf("%d", &n);
	for(i = 0; i < n;i++){
		scanf("%s ", s);
		if(s[1] == '#'){
			s[0] = tolower(s[0]);
		}
		for(j = 0; j < SCALELEN;j++){
			for(k = 0; k < MAJORLEN;k++){
				if(scales[(major[k]+j) % SCALELEN] == s[0]){
					break;
				}
			}
			if(k == MAJORLEN){
				bools &= (4095 - (1 << j));
			}
		}
	}
	if (bools == 0){
		printf("none\n");
		return 0;
	}
	for (i = 0; i < SCALELEN;i++){
		if(bools & (1 << i)){
			printf("%c%s", isupper(scales[i]) ? scales[i] : toupper(scales[i]), isupper(scales[i]) ? "" : "#");
			break;
		}
	}
	for (i++; i < SCALELEN;i++){
		if(bools & (1 << i)){
			printf(" %c%s", isupper(scales[i]) ? scales[i] : toupper(scales[i]), isupper(scales[i]) ? "" : "#");
		}
	}
	printf("\n");
}