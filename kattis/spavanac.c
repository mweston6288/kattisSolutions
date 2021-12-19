#include <stdio.h>

// given a time on a 24-hour format, find the time 45 minutes earlier
int main(){
	int h,m;
	scanf("%d %d", &h, &m);
	// if true, we have to decrement the hour
	if (m < 45){
		m += 15; // m + 60 - 45 = m+15
		// if true, we have to loop back to hour 23
		if(h == 0){
			h = 23;
		}
		else h--;
	}
	else
		m -= 45;

	printf("%d %d\n", h, m);
}