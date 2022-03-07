#include <stdio.h>
#include <string.h>
/*
	Calculate a ragedness score of a paragraph
	The score is equal to the (Sigma)_{j=0} ^{i-2} (m-n_j)^2
	where i is the total number of lines in the paragraph, m is the longest line in the paragraph
	and n_j is the length of a particular line

	The very last line of the paragraph is not considered in the raggedness scale, hence why
	it only goes to i-2

	Since I only care about the lengths of the lines and not the actual content,
	I only stored the string lengths and discarded each line when I was done.
*/
int main(){
	int numChars[100];
	char s[85];
	int max = 0, i = 0, j, res = 0, len;

	// get each string length and the max length
	while(fgets(s, 85, stdin) != NULL){
		len = strlen(s);
		// because fgets() will also get linebreaks, I have to check for and remove them
		// no need to edit the string itself, I just adjust the result of strlen()
		if(s[len-1] == '\n'){
			len--;
		}
		numChars[i] = len;
		// check for new max
		if (numChars[i] > max){
			max = numChars[i];
		}
		i++;
	}
	// quicker to start from the end so I don't have to keep calculating i-2
	for(j = i-2; j >= 0; j--){
		numChars[j] = max - numChars[j];
		numChars[j] *= numChars[j];
		res += numChars[j];
	}

	printf("%d\n", res);
}