#include <stdio.h>
/*
	Determine whether each given participant is eligible to enter a competition
	Anyone who enrolled in 2010 or later is automatically eligible
	Anyone born in 1991 or later is automatically eligible
	Anyone who is not automatically eligible and has completed more than 40 courses is ineligible
	Anyone else can participate with a coach's petition
*/

int main(){
	int numCases;
	scanf("%d", &numCases);
	int i, entryYear, entryMon, entryDay, birthYear, birthMon,birthDay, numCourses;
	char name[32];

	for(i = 0; i< numCases;i++){
		// get all the details
		scanf("%s %d/%d/%d %d/%d/%d %d\n", name,&entryYear, &entryMon, &entryDay, &birthYear, &birthMon,&birthDay, &numCourses);
		// check for automatic eligibility
		if(entryYear - 2010 >= 0 || birthYear - 1991 >= 0){
			printf("%s eligible\n", name);
		}
		// check for automatic ineligibility
		else if(numCourses > 40){
			printf("%s ineligible\n", name);
		}
		// ask the coach
		else{
			printf("%s coach petitions\n", name);

		}
	}
}