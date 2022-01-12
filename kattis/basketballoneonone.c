#include <stdio.h>
/*
	Return the winner of a basketball game based on the score history
	Despite there being special rules about when the game is won, the history is the entire score history
	until a victor was definitely decided, so just find the greater number
*/
int main(){
	int s[2]={0,0};
	char c;
	int n;

	while(scanf("%c%d", &c, &n) == 2){
		// since the players are denoted with 'A' or 'B', I can avoid an if statement using this
		s[c-'A'] += n;
	}
	printf("%c\n", s[0] > s[1] ? 'A' : 'B');
}