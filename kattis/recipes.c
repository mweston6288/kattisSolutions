#include <stdio.h>
/*
	Find the scaled weight of recipe ingredients when you want to make a different number of portions


*/
typedef struct ingredient{
	char name[21];
	double weight;
	double percent; 
} ingre;

int main(){
	int numCases;
	int numIngre, i,j;
	double numPor, numDes;
	ingre ingredients [20];

	double scaleFactor, scaleWeight;
	scanf("%d", &numCases);

	for(i = 1; i <= numCases;i++){
		printf("Recipe # %d\n", i);
		// scan in each ingredient
		scanf("%d %lf %lf\n", &numIngre, &numPor, &numDes);
		for(j = 0; j < numIngre;j++){
			scanf("%s %lf %lf\n", ingredients[j].name, &ingredients[j].weight, &ingredients[j].percent);
		}
		// determine the ratio of normal portions to desired
		scaleFactor = numDes / numPor;
		// find the main ingredient and get the scaled weight of how much to use 
		for(j = 0; j < numIngre;j++){
			if(ingredients[j].percent == 100.0){
				scaleWeight = ingredients[j].weight * scaleFactor;
				break;
			}
		}
		// calculate each ingredients' scaled weight based on the main ingredients weight
		for(j = 0; j < numIngre;j++){
			printf("%s %.1lf\n", ingredients[j].name, ingredients[j].percent * scaleWeight / 100.0);
		}
		printf("----------------------------------------\n");
	}
}