#include <stdio.h>
/*
	Given a sequence of correct answers, determine which pattern was closest to matching it
	
	Adrian - ABCABCABCABC
	Bruno -  BABCBABCBABC
	Goran -  CCAABBCCAABB
*/
const char a[12] = "ABC";
const char b[12] = "BABC";
const char g[12] = "CCAABB";

int main(){
	int numQ;
	scanf("%d\n", &numQ);
	int i;
	char c;
	int ar=0,br=0,gr=0;
	int best;
	// compare each answer to the corresponding guess and store successes
	for(i = 0; i < numQ;i++){
		scanf("%c", &c);
		if(c == a[i%3]){
			ar++;
		}
		if(c == b[i%4]){
			br++;
		}
		if(c == g[i%6]){
			gr++;
		}
	}
	// determine which one had the most correct guesses
	if(ar > br && ar > gr){
		best = ar;
	}
	else if(br > gr){
		best = br;
	}
	else{
		best = gr;
	}
	// print which pattern was closest
	printf("%d\n", best);

	if(ar == best){
		printf("Adrian\n");
	}
	if(br == best){
		printf("Bruno\n");
	}
	if(gr == best){
		printf("Goran\n");
	}
}