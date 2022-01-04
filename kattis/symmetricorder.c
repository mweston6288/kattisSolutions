#include <stdio.h>
#include <string.h>
/*
	Organize a list of names organized in nondescending order of string length
	so that the longest names are in the middle and the names become shorter the closer they are to the ends
*/
int main(){
	int numNames;
	scanf("%d\n", &numNames);

	char name[26];
	char nameList[15][26];
	// j and k track the endpoints
	int i,j,k;
	int setNum = 0;
	while (numNames > 0){
		j = 0;
		k = numNames - 1;
		setNum++;
		for(i = 0; i < numNames;i++){
			scanf("%s\n", name);
			// the odd inputs are placed at the end and gradually get closer to the middle
			if (i & 1){
				strcpy(nameList[k], name);
				k--;
			}
			// even inputs start at the beginning and move toward the middle
			else{
				strcpy(nameList[j], name);
				j++;
			}
		}
		printf("SET %d\n", setNum);
		for(i = 0; i < numNames;i++){
			printf("%s\n", nameList[i]);
		}
		scanf("%d\n", &numNames);
	}
}