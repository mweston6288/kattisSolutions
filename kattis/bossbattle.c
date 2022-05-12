/*
	A boss is hiding behind one of n pillars in a circular room. You'll kill the boss if you bomb
	either the pillar it's hiding behind or one of the adjacent pillars. The boss might move to an
	adjacent pillar if you don't kill them.
	What's the minimum of bombs necessary to beat the boss assuming optimal play?

	The most optimal approach is to choose one pillar and bomb it. If the boss doesn't die, move
	two pillars down and bomb that one. This ensures all three pillars you hit are pillars the boss
	might be behind.
	If you use this strategy, it will take n-2 bombs to successfully kill the boss. This is because
	you will hit 3 pillars with each blast and the two outer pillars might now hide the boss if they
	were right outside the blast. If you stick to the optimal strategy, the number of pillars the boss
	could potentially be behind is reduced by 1 each round. Once you only have 3 adjacent pillars the
	boss could be behind, you win when you bomb the middle pillar.
*/
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	// If there are 3 or fewer pillars, you're guaranteed to hit on the first try
	if (n <= 3){
		printf("1\n");
		return 0;
	}
	printf("%d\n", n-2);
}