#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
	In each day, determine what items were ordered on a menu and who ordered them.
	Print the items in alphabetic order followed by the customers that ordered them in
	alphabetic order

	There are at-most 20 customers per cycle who order at-most 10 items each
	In a worse case scenario, there are 200 total menu items ordered per cycle
*/
#define MENU_SIZE 200
typedef struct menuItem{
	char name[16];
	int numOrders;
	char customers[20][16];
} menuItem;
// find which index has a menuItem with name = item
// return -1 if no index found
int inMenu(menuItem **menu, char *item, int high){
	int low = 0, mid;
	int comp;
	while( high >= low){
		mid = (low+high) / 2; 
		comp = strcmp(item, (menu[mid])->name);
		if (!comp){
			return mid;
		}
		else if(comp < 0){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return -1;
}
// update an existing menuItem with a new customer name and sort the names
// alphabetically
void updateItem(menuItem *item, char *name){
	int i;
	char temp[16];
	strcpy(item->customers[(item->numOrders)], name);
	for(i = item->numOrders; i > 0; i--){
		if(strcmp(item->customers[i - 1], item->customers[i]) > 0){
			strcpy(temp, item->customers[i - 1]);
			strcpy(item->customers[i - 1], item->customers[i]);
			strcpy(item->customers[i], temp);
		}
		else{
			break;
		}
	}
	item->numOrders++;
}
// add a new item to the menu and then place it in sorted order
void insert(menuItem **menu, char *name, char *item, int numItems){
	int i;
	menuItem *temp = malloc(sizeof(menuItem));
	temp->numOrders = 1;
	strcpy(temp->name, item);
	strcpy(temp->customers[0], name);
	
	menu[numItems] = temp;
	for(i = numItems; i > 0; i--){
		if(strcmp(menu[i-1]->name, menu[i]->name) > 0){
			temp = menu[i-1];
			menu[i-1] = menu[i];
			menu[i] = temp;
		}
		else{
			break;
		}
	}
}
// add an item and customer purchase to the menu
int addToMenu(menuItem **menu, char *name, char *item, int numItems){
	int index = inMenu(menu, item, numItems - 1);
	// itm already registered. Just update customers who ordered it
	if(index != -1){
		updateItem(menu[index], name);
		return numItems;
	}
	// add a new item to the menu
	insert(menu, name, item, numItems);
	return numItems + 1;
}
void printResults(menuItem **menu, int numItems){
	int i,j;
	for(i = 0; i < numItems; i++){
		printf("%s", menu[i]->name);
		for(j = 0; j < menu[i]->numOrders;j++){
			printf(" %s", menu[i]->customers[j]);
		}
		printf("\n");
	}
	printf("\n");
}
void cleanup(menuItem **menu, int numItems){
	for(int i = 0; i < numItems; i++){
		free(menu[i]);
	}
}
int main(){
	int num,i, numItems;
	char name[16];
	char item[16];
	menuItem *menu[MENU_SIZE];

	scanf("%d", &num);
	// read in each customer and each of their orders until end of input
	do{
		numItems = 0;
		for(i = 0; i < num; i++){
			scanf("%s", name);
			// read in each item ordered
			do{
				scanf("%s", item);
				numItems = addToMenu(menu, name, item, numItems);
				// if this is the last item the customer ordered, it will be followed by '\n'
				// otherwise, it is followed by ' '
				item[0] = getc(stdin);
			} while(item[0] == ' ');

		}
		// print results, free memory, and get next number of customers
		printResults(menu, numItems);
		cleanup(menu, numItems);
		scanf("%d", &num);

	} while(num != 0);
}