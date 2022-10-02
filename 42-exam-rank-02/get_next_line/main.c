#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *line;
	while(get_next_line(&line)==1)
		printf("%s\n", line);
	printf("%s", line);
	return (0);
}