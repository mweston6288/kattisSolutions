#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*
	Runners have to run along a circular perimeter divided into 28 segments that have a letter, space, or apostrophe on them
	Each runner is given a sentence and must run from their current location to the next letter in order
	The runners will take the shortest path to their next destination

	The running speed is 15 feet per second and they take 1 second to pick up a letter

	Determine the runtime for a given sentence
*/
// the circle is 60 feet in diameter and divided into 28 segments
// THis calculates how long each segment is
const double segLength = 60*M_PI / 28;

int main(){
	int numCases;
	scanf("%d\n", &numCases);

	char message[122];
	int activePoint, nextPoint, len, j;
	double res;
	for(int i = 0 ; i < numCases;i++){
		// get each message
		fgets(message, 121, stdin);
		len = strlen(message);
		// fgets will pick up '\n' if there is one, so I have to remove it
		if(message[len-1] == '\n'){
			message[len-1] = '\0';
			len--;
		}
		// each runner starts at the first character of their message
		if(message[0] >= 'A'){
			activePoint = message[0] - 'A';
		}
		else if(message[0] == ' '){
			activePoint = 26;
		}
		else{
			activePoint = 27;
		}
		
		res = 0;
		for(j = 1; j < len;j++){
			// determine the next segment to go to
			if(message[j] >= 'A'){
				nextPoint = message[j] - 'A';
			}
			else if(message[j] == ' '){
				nextPoint = 26;
			}
			else{
				nextPoint = 27;
			}
			// At most, every runner should only move 14 segments
			// so if going forward would make you travel more than 14 spaces, go backward instead
			res += segLength * (abs(nextPoint - activePoint) > 14 ? 28 - abs(nextPoint - activePoint) : abs(nextPoint - activePoint)) / 15;
			activePoint = nextPoint;
		}
		// each runner picks up each letter and it takes 1 second so add them all in at the end
		res += len;
		printf("%lf\n", res);
	}
}