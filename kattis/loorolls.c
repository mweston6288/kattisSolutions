#include <stdio.h>
/*
	Nick is a stupid idiot. Instead of buying TP in bulk and then buying another pack when 
	he's down to 3 rolls, he's using some overly complex system to determine how many rolls to buy
	and when.

	Each roll has length l centimeters and he uses n centimeters each use. When a roll runs out, he goes out
	and gets a new roll of length l to replace it. He has several backup rolls, as you should, but instead of
	doing the sensible thing of replacing the current used roll with the backup roll, he takes what he needs
	from the backup roll, then gets a new roll and makes that the main roll. If the backup roll didn't have enough
	paper, he takes from another backup roll and will buy a new roll to act as the first backup roll.I don't even want
	to imagine what the kth backup roll is like by the time he actually needs to use it.

	Anyway, r is the minimum number of rolls needed to ensure you can always get n centimeters of paper with this
	system. The very first roll will always have n centimeters removed and there will be l%n centimeters excess.
	The backup roll will always have n1 = n-(l%n) taken off because paper is only taken off when the main roll runs out.
	Backup 2 will always have n2 = n1-(l%n1) taken off with each use, etc. r is the roll where l%nr = 0

	Again, Nick is a stupid idiot and he's also wasting money by buying rolls individually instead of in bulk. This system
	also wouldn't be desirable in the real world because those backup rolls would degrade over time and using those last
	few rolls would not be a pleasent experience.
*/
int main(){
	long long l, n, r = 1;
	scanf("%lld %lld", &l, &n);

	// determine how much excess paper each roll has
	// until there is no excess
	while (l % n != 0){
		r++;
		n -= (l % n);
	}
	printf("%lld\n", r);
}