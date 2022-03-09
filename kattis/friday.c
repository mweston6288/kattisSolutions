#include <stdio.h>
/*
	Given a calendar that has a certain number of months per year and days per month, determine
	how times Friday 13 happens that year.
	Each year starts on a Sunday and has 7 days in a week.

	If a month starts on a Sunday (value is 0), then the 13th is guaranteed to be a Friday
	as long as that month has at least 13 days.

	Determining first day of the month:
		1) Get number of Days that month % 7
		2) Add to the value of that month's startday
		3) mod result by 7
*/
int main(){
	int numCases;
	int numDays, numMonths;
	int monthStart;
	int res, i, j;

	scanf("%d", &numCases);

	for(i = 0; i < numCases;i++){
		scanf("%d %d", &numDays, &numMonths);
		monthStart = 0;
		res = 0;
		for(j = 0; j < numMonths; j++){
			scanf("%d", &numDays);
			// If the month starts on a Sunday and has 13 or more days in it
			if(monthStart == 0 && numDays >= 13){
				res++;
			}
			// get next month's start day
			monthStart = (monthStart + (numDays % 7)) % 7;
		}
		printf("%d\n", res);
	}
}