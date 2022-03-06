#include <stdio.h>
/*
	Earth takes 365 days to revolve around the sun. Mars takes 687 days.
	On day 0 of either planent, they are beginning a new year.
	Given the day of the year for Earth and Mars, determine how many days it would take for them
	to simultaneously be on day 0 of their years again.

	Both years are coprime so at worst, it will take 365 Mars years or 687 Earth years for them to both align

	Since Mars years is the smaller number, I calculated based on it

	First step was determining how many days it woul take for Mars to complete its current orbit
	so it's back at day 0 of the year.
	Then I add full Mars years to Earth's rotation until Earth is at day 0 of its year
*/
#define EARTH 365
#define MARS 687

int getDays(int earth, int mars){
	// Figure out how many days it takes Mars to complete its current rotation
	int res = (MARS - mars) % MARS;
	// add those days to Earth's rotation
	earth = (earth + res) % EARTH;

	// do a full Mars rotation until Earth is at a full rotation
	while (earth != 0){
		res += MARS;
		earth = (earth + MARS) % EARTH;
	}
	return res;
}
int main(){
	int earth,mars;
	int count = 1;
	while(scanf("%d %d\n", &earth, &mars) == 2){
		printf("Case %d: %d\n", count, getDays(earth, mars));
		count++;
	}
}