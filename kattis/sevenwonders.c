#include <stdio.h>
#include <string.h>

// Given a string of C, G, and T, count how many instances of each letter appears
// Then sum up the square of each plus 7 times the minimum value of the three

int getMin(int C, int G, int T){
	if(C <= G && C <= T)
		return C;
	// if we get here, we already know C is greater than G.
	else if (G <= T)
		return G;
	else 
		return T;
}

int main(){
	char x[52];
	int C,G,T, min;
	C=G=T=0;
	scanf("%s", x);
	int len = strlen(x);
	for(int i = 0; i < len; i++){
		if(x[i] == 'C')
			C++;
		else if(x[i] == 'G')
			G++;
		else
			T++;
	}
	min = getMin(C, G, T);
	printf("%d\n", C*C+G*G+T*T+7*min);
}