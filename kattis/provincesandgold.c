#include <stdio.h>
/*
	Given a number of gold, silver, or copper pieces with their own worth, 
	determine the costliest property and coin you can buy by printing "<building> or <coin>"
	If you cannot afford a building, just print the coin

	Gold: cost 6 worth 3
	Silver: cost 3 worth 2
	Copper: cost 0 worth 1
	Province: cost 8 worth 6
	Duchy: cost 5 worth 3
	Estate: cost 2 worth 1 
*/

int main(){
	int g,s,c;
	scanf("%d %d %d", &g,&s,&c);
	int buyingPower = 3*g + 2*s + c;
	// I can always get a copper no matter what but not always a building
	// so the building print will always have " or " after it
	if(buyingPower >= 8){
		printf("Province or ");
	}
	else if(buyingPower >= 5){
		printf("Duchy or ");
	}
	else if(buyingPower >= 2){
		printf("Estate or ");
	}

	// get coin
	if(buyingPower >= 6){
		printf("Gold\n");
	}
	else if(buyingPower >= 3){
		printf("Silver\n");
	}
	else{
		printf("Copper\n");
	}
}