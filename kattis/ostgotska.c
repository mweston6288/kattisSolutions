#include <stdio.h>
#include <string.h>
/*
	Get the percent of words which have the substring "ae". Print one result if the result is >= 40%
*/
int main(){
	char s[16];
	double numWords = 0, numOst = 0;
	int i, len;
	while(scanf("%s", s) == 1){
		numWords++;
		len = strlen(s);
		for(i = 1; i < len; i++){
			if(s[i-1] == 'a' && s[i] == 'e'){
				numOst++;
				break;
			}
		}
	}
	if(numOst / numWords >= .4){
		printf("dae ae ju traeligt va\n");
	}
	else{
		printf("haer talar vi rikssvenska\n");
	}
}