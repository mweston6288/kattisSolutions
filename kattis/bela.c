#include <stdio.h>

int ans[2][90];

void init(){
	ans[0]['A'] = 11;
	ans[0]['K'] = 4;
	ans[0]['Q'] = 3;
	ans[0]['J'] = 20;
	ans[0]['T'] = 10;
	ans[0]['9'] = 14;
	ans[0]['8'] = 0;
	ans[0]['7'] = 0;
	ans[1]['A'] = 11;
	ans[1]['K'] = 4;
	ans[1]['Q'] = 3;
	ans[1]['J'] = 2;
	ans[1]['T'] = 10;
	ans[1]['9'] = 0;
	ans[1]['8'] = 0;
	ans[1]['7'] = 0;

}
int main(){
	int numHands, i, score = 0;
	char dom, c1,c2;
	
	scanf("%d", &numHands);
	numHands *=4;
	scanf(" %c\n", &dom);
	init();
	for(i=0; i<numHands;i++){
		scanf("%c%c\n", &c1,&c2);
		score += ans[c2!=dom][c1];
	}
	printf("%d\n", score);
}