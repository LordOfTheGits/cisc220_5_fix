# include <stdio.h>
# include <stdlib.h>
# include "udll.h"

int main()
{
	union Data d0;
	union Data d1;
	union Data d2;

	d0.i = 3;
	d1.f = 6.9;
	d2.c = 'c';
	
	insert(0,d2);
	insert(0,d1);
	insert(0,d0);

	printf("The length of the list is %d\n", length());

	removeNode (1);

	printf("The length of the list is after a removal of node 1 is %d\n", length());
	
	union Data dayta = get(0);
	printf("The value in the first position is %d\n", dayta.i);

	return 0;
}