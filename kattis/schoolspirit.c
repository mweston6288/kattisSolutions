#include <stdio.h>
#include <math.h>
/*
	Determine the kattis score of a given group and the average of the kattis scores if any one person leaves
*/
// This gets the score when person i leaves
// index i will be skipped
double getPartialScore(int *scores, int n, int i){
	double res = 0;
	int j;
	// get every score before the missing one
	for(j = 0; j < i;j++){
		res += scores[j] * pow(.8, j) *.2;
	}
	// get every score after the missing one
	for(j += 1; j < n; j++){
		res += scores[j] * pow(.8, j-1) *.2;
	}
	return res;	
}

double getKattisScore(int *scores, int n){
	double res = 0;
	for(int i = 0; i < n;i++){
		res += scores[i] * pow(.8, i) *.2;
	}
	return res;
}

int main(){
	int n,i;
	int scores[50];
	double res = 0;
	scanf("%d", &n);

	for(i = 0; i < n;i++){
		scanf("%d", &scores[i]);
	}
	printf("%.8lf\n", getKattisScore(scores, n));

	for(i = 0; i < n;i++){
		res += getPartialScore(scores, n, i);
	}
	printf("%.8lf\n", res / n);
}