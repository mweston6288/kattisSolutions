#include <stdio.h>
#include <stdlib.h>
/*
	Each player starts with folded hands(count only once per player)
	When selected, change to two fists (player counted twice)
	When fist selected, change that to open palm (Still counted)
	When palm is selected, that hand is eliminated
	Player is eliminated when folded->fist 1->palm 1-> eliminated
									 \>fist 2->palm 2-> eliminated
	
	struct info:
		playerNum is the player's turn order number
		state is what state their hand is in:
			0 - folded hand
			1 - fist
			2 - palm
		next - player who comes next in the count
*/
typedef struct player{
	int playerNum;
	short state;
	struct player *next;
} player;

// create a circular linked list of the players
player *init(int n){
	player *head, *tail;

	// first one, head = tail
	head = malloc(sizeof(player));
	head->playerNum = 1;
	head->state = 0;
	head->next = head;
	tail = head;
	// build the other ones at the tail point
	for(int i = 2; i <= n;i++){
		tail->next = malloc(sizeof(player));
		tail->next->playerNum = i;
		tail->next->state = 0;
		tail = tail->next;
		tail->next = head;
	}
	// return tail because we want to count the head as we jump
	return tail;
}

int main(){
	int count;
	int numPlayers;
	int i;
	scanf("%d %d", &count, &numPlayers);
	player *p, *temp;

	p = init(numPlayers);
	while (p != p->next){
		// this will get us to the one right before the actual chosen
		for(i = 1; i < count;i++){
			p = p->next;
		}
		// folded fist to two fists
		// must add a new player with the same playerNum as p->next
		// don't jump to p->next counting begins on the same player
		if(p->next->state == 0){
			p->next->state++;
			temp = malloc(sizeof(player));
			temp->playerNum = p->next->playerNum;
			temp->state = 1;
			temp->next = p->next;
			p->next = temp;
		}
		// eliminate this player
		// don't jump to p->next because counting starts with them
		else if (p->next->state == 2){
			temp = p->next;
			p->next = temp->next;
			free(temp);
		}
		// increment p->next's state
		// jump to p->next because counting starts on the person after them
		else{
			p = p->next;
			p->state++;
		}
	}
	printf("%d\n", p->playerNum);
}