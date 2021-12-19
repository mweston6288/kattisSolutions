#include <stdio.h>

// the game involves taking two consecutive stones until there are no consectuive stones
// Alice wins if the remaining stones are odd and Bb wins if they're even

// There is no actual strategy to win. If the initial number is odd, Alice wins. Otherwise Bob wins

int main(){
	int n;
	scanf("%d", &n);
	printf("%s\n", n % 2 == 1 ? "Alice" : "Bob");
}