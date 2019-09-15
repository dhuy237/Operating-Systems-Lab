#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include "factorial.h"

int main()
{
	int b;
	char a[100];
	printf("Input a number: ");
	scanf("%[^\n]", a);
	if (read_line(a))
	{
		b = atoi(a);
		factorial(b);
		printf("\n");
	}
	else
		printf("%d", -1);
	return 0;
}
