#include <stdio.h>
#include <string.h>
/*
	Given a word and a permuation of the alphabet, determine if you'd win a game of hangman
	by guessing letters in the order of the permutation

	You lose after making 1- bad guesses
*/
int main(){
	char word[20];
	// stores the frequency of each letter in the word
	int alpha[26];
	char c;
	int len,i, win=0, lose=0;

	for(i = 0; i < 26;i++){
		alpha[i] = 0;
	}

	scanf("%s\n", word);
	len = strlen(word);
	// set the frequency of each letter
	for(i = 0; i < len;i++){
		alpha[word[i]-'A']++;
	}

	// while you haven't won or lost
	// win stores the number of total revealed letters
	// lose stores the number of bad guesses
	while(win < len && lose < 10){
		c = fgetc(stdin);
		if(alpha[c-'A']){
			win += alpha[c-'A'];
		}
		else{
			lose++;
		}
	}
	if (lose == 10){
		printf("LOSE\n");
	}
	else{
		printf("WIN\n");
	}
}