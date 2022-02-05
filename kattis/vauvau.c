#include <stdio.h>
/*
	Determine how many dogs are active at time p,m, and g when one dog cycles active for a and inactive for b
	and dog 2 is active for c to d
*/
void calc(int a,int b, int c, int d, int e){
	// a+b and c+d are a full cycle for the dogs
	int f = e % (a+b);
	int g = e % (c+d);
	// both are active
	if(f <= a && g <= c && f > 0 && g > 0){
		printf("both\n");
	}
	// one is active
	else if((f <= a && f > 0) || (g <= c && g > 0)){
		printf("one\n");
	}
	else{
		printf("none\n");
	}
}
int main(){
	int a,b,c,d,p,m,g;
	scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&p,&m,&g);

	calc(a,b,c,d,p);
	calc(a,b,c,d,m);
	calc(a,b,c,d,g);
}