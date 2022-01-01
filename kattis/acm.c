#include <stdio.h>
/*
	A coding time competion scores time as follows:
		Upon successful answer, submission time is added
		For each previously failed attempt, 20 is added to the score when a correct answer is made
		failed attempts that are never successfully answered are not counted
		resubmissions to an already passed answer are ignored

	Find the number of correct answers and the time score
*/

int main(){
	// The successful answers will be stored using bitwise operator
	int successes = 0;
	// No mention how many questions there are, but since they're represented by single letters
	// this should be enough
	// This will store all the penalties
	int scores[26];
	int i, ans = 0, numCorrect = 0;
	// initialize scores
	for(i = 0; i < 26;i++){
		scores[i] = 0;
	}
	// i stoes the time of submission, c stores which problem, and res is either "right" or "wrong"
	char c;
	char res[6];
	scanf("%d ", &i);
	while (i != -1){
		scanf("%c %s\n", &c, res);
		
		// why bother checking the whole string when res is guaranteed to start with 'w' or 'r'
		// if true, we're adding a penalty score
		if(res[0] == 'w'){
			scores[c-'A'] += 20;
		}
		// if the above was false, that must mean res = "right" so no need to check that
		// but we do need to check if this question was already successfully done
		// before adding it to the final score
		else if(!(successes & (1 << (c-'A')))){
			ans += (scores[c-'A'] + i);
			successes += (1 <<(c-'A'));
			numCorrect++;
		}
		// check if we're doing this again
		scanf("%d ", &i);
	}
	printf("%d %d\n", numCorrect, ans);
}