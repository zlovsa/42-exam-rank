#include <unistd.h>
#include <stdio.h>
#include <math.h>

int error(char *s)
{
	while (*s)
		write(1, s++, 1);
	return (1);
}

int in(int x, int y, char r, float cx, float cy, float cr)
{
	float d = sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
	if(d>cr)
		return (0);
	return (r == 'c' ? (d > cr-1) : 1);
}

int process(FILE *f)
{
	if(!f)
		return (0);
	char field[300][300], c, r;
	int w, h, x, y, rv;
	if(fscanf(f,"%d %d %c\n",&w,&h,&c)!=3 || w<1 || w>300 || h<1 || h>300)
		return (0);
	y = -1;
	while(++y<h && (x=-1))
		while(++x<w)
			field[y][x] = c;
	float cx, cy, cr;
	while ((rv = fscanf(f, "%c %f %f %f %c\n", &r, &cx, &cy, &cr, &c))==5
		&& (r=='c' || r=='C') && cr>0 && (y=-1))
		while(++y<h && (x=-1))
			while (++x<w)
				if(in(x,y,r,cx,cy,cr))
					field[y][x] = c;
	if (rv != EOF)
		return (0);
	y = -1;
	while(++y<h)
	{
		write(1, field[y], w);
		write(1, "\n", 1);
	}
	return (1);
}

int main(int ac, char *av[])
{
	if(ac!=2)
		return (error("Error: argument\n"));
	if(!process(fopen(av[1],"r")))
		return (error("Error: Operation file corrupted\n"));
	return (0);
}