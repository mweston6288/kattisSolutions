#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	I used a binary search tree to store each person who should be in the building
	An anomaly occurs when I find a match while adding or when I don't find a match when deleting
*/
typedef struct list list;

struct list{
	char name [21];
	list *left;
	list *right;
};

list *create(char *name){
	list *new = malloc(sizeof(list));
	strcpy(new->name, name);
	new->left = new->right = NULL;
	return new;
}
// res stores what happens
// if res is set to 0, something got added; no anomaly
// if res is set to 1, the thing to add was already there; anomaly
list *addToList(list *root, char *name, int* res){
	if (root == NULL){
		*res = 0;
		return create(name);
	}
	int dir = strcmp(root->name, name);
	if(dir < 0){
		root->left = addToList(root->left, name, res);
	}
	else if(dir > 0){
		root->right = addToList(root->right, name, res);
	}
	else{
		*res = 1;
	}
	return root;
}
// get the max node on a left subtree
// node is not NULL and neither are its children
// Also, link the max node's parent to max node's child
list *getMaxLeft(list *node){
	list *tmp = node->left;
	list *tmp2;
	// initial case: check if node's left child was already the greatest value
	if(tmp->right == NULL){
		node->left = tmp->left;
		return tmp;
	}
	// find the biggest one
	// we need to stay one level back because we need to link
	// max's parent to max's child
	while (tmp->right->right != NULL){
		tmp = tmp->right;
	}
	// find, link, return
	tmp2 = tmp->right;
	tmp->right = tmp2->left;
	return tmp2;

}
// delete the node to delete
list *delete(list *node){
	if(node == NULL){
		return NULL;
	}
	// no children; node can be safely removed
	if(node->left == NULL && node->right == NULL){
		free(node);
		return NULL;
	}
	list *new;
	// two children; replace with rightmost-left child
	if (node->left != NULL && node->right != NULL){
		new = getMaxLeft(node);
		new->left = node->left;
		new->right = node->right;
		free(node);
		return new;
	}
	// one child; just replace with that child
	new = node->left == NULL ? node->right : node->left;
	free(node);
	return new;
	
}
// if res is set to 1, something got deleted; no anomaly
// if res is set to 0, the thing to delete was not there; anomaly
// search for the node to delete
list *deleteFromList(list *root, char *name, int* res){
	if(root == NULL){
		*res = 1;
		return NULL;
	}
	int dir = strcmp(root->name, name);
	if(dir < 0){
		root->left = deleteFromList(root->left, name, res);
	}
	else if(dir > 0){
		root->right = deleteFromList(root->right, name, res);
	}
	else{
		*res = 0;
		return delete(root);
	}
	return root;
}
// return what was borrowed
void freeAll(list *root){
	if(root == NULL){
		return;
	}
	freeAll(root->left);
	freeAll(root->right);
	free(root);
}
int main(){
	int n, res;
	scanf("%d\n", &n);
	char action[6];
	char name[21];
	list *names = NULL;

	for(int i = 0; i < n; i++){
		scanf("%s %s\n", action, name);
		// action is only "enter" or "exit". Faster to compare 1 letter than the whole string
		if(action[1] == 'n'){
			// list enters. Add to list and print ANOMALY if they're already there
			printf("%s entered", name);
			names = addToList(names, name, &res);
			if(res){
				printf(" (ANOMALY)");
			}
			printf("\n");
		}
		else{
			// list exits. Remove from list and print ANOMALY if they we're there
			printf("%s exited", name);
			names = deleteFromList(names, name, &res);
			if(res){
				printf(" (ANOMALY)");
			}
			printf("\n");
		}
	}

	freeAll(names);
}