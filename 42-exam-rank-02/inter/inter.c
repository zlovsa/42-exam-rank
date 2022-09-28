#include <unistd.h>

int chr(char *s, char c)
{
	int i = -1;
	while (s[++i])
		if (s[i]==c)
			return (i);
	return (-1);
}

int main(int argc, char *argv[])
{
	if (argc==3)
	{
		char *s1 = argv[1], *s2 = argv[2];
		int i = -1;
		while (s1[++i])
			if (chr(s1,s1[i])==i && chr(s2,s1[i])>-1)
				write(1, s1 + i, 1);
	}
	write(1, "\n", 1);
	return (0);
}