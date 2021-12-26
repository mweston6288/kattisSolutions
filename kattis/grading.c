#include <stdio.h>
/*
	Given a grading scale and grade number, determine the grade letter
*/
int main(){
	int a,b,c,d,e, grade;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &grade);

	if(grade >= a){
		printf("A\n");
	}
	else if(grade >= b){
		printf("B\n");
	}
	else if(grade >= c){
		printf("C\n");
	}
	else if(grade >= d){
		printf("D\n");
	}
	else if(grade >= e){
		printf("E\n");
	}
	else{
		printf("F\n");
	}

}