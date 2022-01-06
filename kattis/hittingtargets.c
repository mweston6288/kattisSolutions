#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
	Given a set of rectangles and circles on an xy plane, determine how many of them overlap on a given coordinate

	For circles, the xy coordinate of the center and the radius are passed in
	For rectangles, the coordinate of the bottom-left corner and top-right corner are passed in


	For my solution, I used function pointers so every shape struct has a direct reference to the function that 
	determines if a coordinate is within its boundaries. It's a bit complex, but it greatly reduces how often I have to check
	what shape I'm working with.
*/
typedef struct shape shape;
struct shape{
	// dimensions might be 3 or 4 elements
	int *dimensions;
	// the function pointer that will store which function to use
	int (*doesHit)(shape *, int *);
};
// the function that determines if a coordinate is in a circle
// If the distance from the center of the circle to the coordinate is less than or equal to the radius,
// the coordinate is in the circle
int hitCircle(shape *self, int *coordinates){
	double distX = self->dimensions[0] - coordinates[0];
	double distY = self->dimensions[1] - coordinates[1];
	return (sqrt(distX*distX + distY*distY) <= self->dimensions[2]); 
}
// the function that determines if a coordinate is in a rectangle
// if the x-coordinate is between the leftmost and right most x-coordinates on the rectangle
// and the y-coordinate is between the uppermost and bottommost y-coordinates on the rectangle
// the coordinate is in the rectangle
int hitRectangle(shape *self, int *coordinates){
	return (self->dimensions[0] <= coordinates[0]) && (coordinates[0] <= self->dimensions[2]) && (self->dimensions[1] <= coordinates[1]) && (coordinates[1] <= self->dimensions[3]);
}
// creates each shape by passing in an array of the dimensions and
// the address of the coordinate calculator that will be used for that shape
shape * createObject(int *dimensions, int (*function)()){
	shape *new = malloc(sizeof(shape));
	new->dimensions = dimensions;
	new->doesHit = function;
	return new;
}

int main(){
	int numShapes, numShots, i,j,res;

	scanf("%d\n", &numShapes);
	shape **objects = malloc(sizeof(shape*) * numShapes);
	char type[10];
	int *dimensions;
	
	// read in each shape and build it
	for(i = 0; i < numShapes;i++){
		scanf("%s", type);
		// literally the only time you have to check if it's a circle or rectangle
		// despite what it looks like, this is true if the type is a rectangle
		if (strcmp(type,"circle")){
			dimensions = malloc(sizeof(int) * 4);
			scanf(" %d %d %d %d\n", &dimensions[0],&dimensions[1],&dimensions[2],&dimensions[3]);
			objects[i] = createObject(dimensions, &hitRectangle);
		}
		// here's where I build a circle
		else{
			dimensions = malloc(sizeof(int) * 4);
			scanf(" %d %d %d\n", &dimensions[0],&dimensions[1],&dimensions[2]);
			objects[i] = createObject(dimensions, &hitCircle);			
		}
	}
	// Might as well recycle this variable to store the coordinates
	dimensions = malloc(sizeof(int) * 2);

	scanf("%d\n", &numShots);
	
	// Now I read each coordinate and determine the number of shapes it's in
	for(i = 0; i < numShots;i++){
		scanf("%d %d\n", &dimensions[0],&dimensions[1]);
		res = 0;
		for(j = 0; j <numShapes;j++){
			res += objects[j]->doesHit(objects[j], dimensions);
		}
		printf("%d\n", res);

	}

	// free all the memory
	for(i = 0; i < numShapes;i++){
		free(objects[i]->dimensions);
		free(objects[i]);
	}
	free(objects);
	free(dimensions);


}