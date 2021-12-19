#include <stdio.h>
#include <ctype.h>
#include <string.h>
// reads a string and gets the percent of capital, lowercase, spaces, and symbols
int main(){
	char spam[100010];
	int cap, low, sym, white;
	white = cap = low = sym = 0;
	scanf("%s", spam);
	int len = strlen(spam);
	int i;
	for(i = 0; i < len; i++){
		if (isupper(spam[i]))
			cap++;
		else if (islower(spam[i]))
			low++;
		// space is replaced with _
		else if (spam[i] == '_')
			white++;
		// all other items
		else
			sym++;
	}
	printf("%lf\n%lf\n%lf\n%lf\n", (double)white/len, (double)low/len, (double)cap/len, (double)sym/len );
}