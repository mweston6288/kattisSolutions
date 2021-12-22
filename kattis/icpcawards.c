#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Given a list of schools and teams, print, in-order, the first twelve schools and teams that have unique school names

// gonna use a linked list for this one. No particular reason why
typedef struct school{
	char name[22];
	struct school *next;
} school;

// make a new school node
school *addSchool(char *name){
	school *new = malloc(sizeof(school));
	strcpy(new->name, name);
	new->next = NULL;
	return new;
}

// searches for if a team's school was already used
// uses pointers to handle linked list connections
int noPreviousWin(school **s, char *name){
	// if we hit null, the school doesn't have a previous winner
	if(*s == NULL){
		*s = addSchool(name);
		return 1;
	}
	// if we find a match, there was a previous winner
	if(!strcmp(name, (*s)->name)){
		return 0;
	}
	return noPreviousWin(&((*s)->next), name);
}
void freeAll(school *s){
	if(s == NULL){
		return;
	}
	freeAll(s->next);
	free(s);
}
int main(){
	// even though we're given the total number of schools, we're told exactly how many winners there are
	// once we have twelve winners, we can ignore the rest of the list. numSchools is useless
	int numSchools;
	scanf("%d", &numSchools);
	int numWinners = 0;
	char schoolName[22], teamName[22];
	school *s = NULL;
	// We'll stop once we have our twelve winners
	while (numWinners < 12){
		scanf("%s %s", schoolName, teamName);
		if(noPreviousWin(&s, schoolName)){
			printf("%s %s\n", schoolName, teamName);
			numWinners++;
		}
	}
	freeAll(s);
}