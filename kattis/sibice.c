#include <stdio.h>
#include <math.h>

int main(){
	int numMatches, wid, i, match;
	double len;

	scanf("%d %lf %d", &numMatches, &len, &wid);
	len = sqrt(len*len + wid*wid);
	for(i=0;i<numMatches;i++){
		scanf("%d", &match);
		if (match <= len){
			printf("DA\n");
		}
		else{
			printf("NE\n");

		}
	}
}