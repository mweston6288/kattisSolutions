#include <stdio.h>

// Givena day and month, determine what the day was in 2009
// Since C doesn't have any built-in features to handle this, a lot of things are hard coded
// Jan 1, 2009 was a Thursday so we'll work from there


// Fun fact: 2009 had 3 instances of Friday 13th due to one being in February

/*
	31 days: Jan, Mar, May, Jul, Aug, Oct, Dec
	30 days: Apr, Jun, Sep, Nov
	28 days: Feb

	From January to July, all odd months have 31 days, 
	but from August to December, all even months have 31 day.
	To compensate, I'm just going to check which block the month is in
	and set the day to Jan 1 or Aug 1. Then I'll calculate the offset from there.

	Since we also only want the day of the week, I'm running everything under mod 7
	31 % 7 == 3
	30 % 7 == 2
*/
int main(){
	int date, month;
	scanf("%d %d", &date, &month);
	int day; // Sunday is 0, Monday is 1, etc.
	
	
	// 2009 started on a Thursday
	// Aug 1,2009 was on a Saturday
	day = month < 8 ? 4 : 6;
	
	// From January to July, every odd month has 31 days
	if(month > 1 && month <= 7){
		// add the 31 day months
		day += 3*(month / 2);
		// add the 30 day months
		day += 2*((month - 3) / 2);
	}
	// From August to December, every even month has 31 days
	else if(month > 8) {
		day += 3*((month - 7) / 2);
		day += 2*((month - 8) / 2);
	}

	// add the date and mod to get weekday
	// minus 1 due to months starting at 1 rather than 0
	day = (date + day - 1) % 7;

	// print day
	if (day == 0)
		printf("Sunday\n");
	else if (day == 1)
		printf("Monday\n");
	else if (day == 2)
		printf("Tuesday\n");
	else if (day == 3)
		printf("Wednesday\n");
	else if (day == 4)
		printf("Thursday\n");
	else if (day == 5)
		printf("Friday\n");
	else
		printf("Saturday\n");

}