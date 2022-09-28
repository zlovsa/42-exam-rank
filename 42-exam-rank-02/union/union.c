#include <unistd.h>

int chr(char *s, char c)
{
	int i = -1;
	while (s[++i])
		if (s[i]==c)
			return (i);
	return (-1);
}

int main(int ac, char *av[])
{
	if (ac==3)
	{
		char *s1 = av[1], *s2 = av[2];
		int i = -1;
		while (s1[++i])
			if (chr(s1,s1[i])==i)
				write(1, s1 + i, 1);
		i = -1;
		while (s2[++i])
			if (chr(s1,s2[i])<0 && chr(s2,s2[i])==i)
				write(1, s2 + i, 1);
	}
	write(1, "\n", 1);
	return (0);
}