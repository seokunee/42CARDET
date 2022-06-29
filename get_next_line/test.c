#include "get_next_line.h"
#include <stdio.h>
int main()
{
	char *a = malloc(4);
	a[0] = '1';
	a[1] = '\0';
	char *b;

	b = a;
	free(b);
	b[0] = '2';
	// b = NULL;
	//free(a);
	printf("%s", b);
}