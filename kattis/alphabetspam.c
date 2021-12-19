#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
		else if (spam[i] == '_')
			white++;
		else
			sym++;
	}
	printf("%lf\n%lf\n%lf\n%lf\n", (double)white/len, (double)low/len, (double)cap/len, (double)sym/len );
}