#include <stdio.h>
/*
	m - Number of mosquito adults
	p - number of pupae
	l - number of larvae
	e - number of eggs laid
	r - survival rate of larvae
	s - survival rate of pupae
	n - number of weeks

	Apparantly, mosquitos can reproduce asexually because every mosquito lays eggs in this problem
*/

int main(){
	int m, p, l, e, r, s, n;
	int i, temp;
	while (scanf("%d %d %d %d %d %d %d", &m, &p, &l, &e, &r, &s, &n) == 7){
		for (i = 0; i < n;i++){
			temp = m;
			// new mosquito population made from surviving pupae
			m = p / s;
			// new pupae population made from surviving larvae
			p = l / r;
			// new larvae population made from mosquito eggs
			l = temp  * e;
		}
		printf("%d\n", m);
	}

}