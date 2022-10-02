#include "get_next_line.h"

int len(char *s)
{
	int l = 0;
	while(s[l])
		l++;
	return (l);
}

char *cat(char *s1, char *s2)
{
	char *r;
	if(!(r=(char*)malloc(len(s1)+len(s2)+1)))
		return (r);
	int j = -1;
	while(s1[++j])
		r[j] = s1[j];
	int i = -1;
	while(s2[++i])
		r[j + i] = s2[i];
	r[j + i] = 0;
	return (r);
}

int red(char *c)
{
	static int pos, len;
	static char buf[BUF_SIZE];

	if(pos==len)
	{
		if((len = read(0, buf, BUF_SIZE))<1)
			return (len);
		pos = 0;
	}
	*c = buf[pos++];
	return (1);
}

int get_next_line(char **line)
{
	char *t, c[2];
	int r;
	if (!line || !(*line = cat("", "")))
		return (-1);
	c[1] = 0;
	while (*line && (r = red(c)) == 1 && c[0]!='\n')
	{
		t = cat(*line, c);
		free(*line);
		*line = t;
	}
	if(r<0)
		free(*line);
	return (*line && r > -1 ? r : -1);
}