#include <stdio.h>
// given expected revenue without advertising, expected revenue with advertising, and cost of advertising,
// determine if it is best to advertise or not
int main(){
	int numCases;
	scanf("%d", &numCases);
	int i;
	int noAd, ad, cost;
	for(i = 0; i < numCases; i++){
		scanf("%d %d %d", &noAd, &ad, &cost);
		ad -= cost;
		if(noAd > ad){
			printf("do not advertise\n");
		}
		else if(noAd < ad){
			printf("advertise\n");
		}
		else{
			printf("does not matter\n");
		}
	}

}