#include <stdio.h>

int main(){
	int n,i;
	scanf("%d", &n);
	n--;
	char word[100];
	scanf("%s", word);
	printf("%s\n",word);
	for(i = 1; i < n; i+=2){
		scanf("%s %s", word, word);
		printf("%s\n",word);
	}
}