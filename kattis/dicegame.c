#include <stdio.h>

/*
	When rolling two fair dice where one has values a-b, and the other has values c-d, 1<=a<=b, 1<-c<=d,
	the most likely sum will be the middle one (a+b+c+d)/2. 
	The probability of rolling less than the mid is equal to the probability of rolling greater than the mid

	So if two sets of different dice are rolled and they have the same mid value,
	the two dice are equally likely to roll a higher sum than the other

	doubles have to be used to calculate the mid because a+b+c+d could potentially be odd
*/

int main(){
	int a,b,c,d;
	double mid1,mid2;
	scanf("%d %d %d %d", &a,&b,&c,&d);
	mid1 = (a+b+c+d) / 2.0;
	scanf("%d %d %d %d", &a,&b,&c,&d);
	mid2 = (a+b+c+d) / 2.0;
	if (mid1 < mid2){
		printf("Emma\n");
	}
	else if (mid1 == mid2) {
		printf("Tie\n");
	}
	else{
		printf("Gunnar\n");
	}
}