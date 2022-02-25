#include <stdio.h>
/*
	Lights on a road of distance l units long cycle between being red for r seconds and green for g seconds
	It takes a car 1 second to move 1 unit. If it arrives at a red light, it must wait until it turns green

	The color of the light can be determined by taking time t and modding it by a full cycle
	m = t % (r+g). if the result is less than r, the light is red. Otherwise, it is green.
	If the light at point d is red at time t when the car reaches it, the car waits r-m seconds

	In this solution, instead of using t as the total travel time, it is used just for the wait time.
	It would take d seconds to reach a light so the actual time (including wait time) would be d+t
*/
int main(){
	// number of lights and length of road
	int n,l;
	// distance from start, red cycle, and green cycle of a light
	int d,r,g;
	// wait time and determiner of light color at time t
	int t = 0, mod;
	scanf("%d %d\n", &n, &l);

	for(int i = 0; i < n; i++){
		scanf("%d %d %d\n", &d, &r, &g);
		// use mod to determine whether you arrive at the light when it's red or green
		// if mod < r, the light is red and must wait the difference between them
		mod = (d+t) % (r+g);
		// hit the red light. Gotta wait
		if( mod < r){
			t += (r - mod);
		}
	}
	printf("%d\n", t+l);
}