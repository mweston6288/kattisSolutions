#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct city{
	char name[22];
	struct city *left;
	struct city *right;
} city;

city *buildNode(char *name){
	city *new = malloc(sizeof(city));
	new->left = new->right = NULL;
	strcpy(new->name, name);
	return new;
}

city *addToList(char *name, city *root, int *res){
	if(root == NULL){
		city *new = buildNode(name);
		(*res)++;
		return new; 
	}
	int cmp = strcmp(name, root->name);
	if (!cmp)
		return root;
	if (cmp > 0){
		root->right = addToList(name, root->right, res);
		return root;
	}
	root->left = addToList(name, root->left, res);
	return root;
}

city *freeNodes(city *root){
	if (root == NULL){
		return NULL;
	}
	freeNodes(root->left);
	freeNodes(root->right);
	free(root);
	return NULL;
}

int main(){
	int numCases;
	scanf("%d", &numCases);
	int i,j, numCities, res;
	char temp[22];
	city *c = NULL;
	for(i = 0; i < numCases; i++){
		res = 0;
		scanf("%d", &numCities);
		for(j = 0; j < numCities; j++){
			scanf("%s", temp);
			c = addToList(temp, c, &res);
		}
		printf("%d\n", res);
		c = freeNodes(c);
	}

}