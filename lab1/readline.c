#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "readline.h"

int read_line(char *str)
{
	int i = 0;
	while (i < strlen(str))
	{
		if (isdigit(str[i]))
			return 1;
		i++;
	}
	return 0;
}
