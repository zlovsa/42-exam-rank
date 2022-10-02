#include <unistd.h>
#include <stdio.h>

int error(char *s)
{
	while (*s)
		write(1, s++, 1);
	return (1);
}

int in(int x, int y, char r, float rx, float ry, float rw, float rh)
{
	if (x < rx || x > rx + rw || y < ry || y > ry + rh)
		return (0);
	return (r == 'r' ? (x - rx < 1 || rx + rw - x < 1 || y - ry < 1 || ry + rh - y < 1) : 1);
}

int process(FILE *f)
{
	if (!f)
		return (0);
	int h, w, cnt, x, y = -1;
	char field[300][300], c, r;
	if (fscanf(f, "%d %d %c\n", &w, &h, &c) != 3 || w < 1 || w > 300 || h < 1 || h > 300)
		return (0);
	while (++y < h && (x = -1))
		while (++x <= w)
			field[y][x] = x == w ? '\n' : c;
	float rx, ry, rw, rh;
	while ((cnt = fscanf(f, "%c %f %f %f %f %c\n", &r, &rx, &ry, &rw, &rh, &c))
		== 6 && rw > 0 && rh > 0 && (r == 'r' || r == 'R') && (y = -1))
		while (++y < h && (x = -1))
			while (++x < w)
				if (in(x, y, r, rx, ry, rw, rh))
					field[y][x] = c;
	if (cnt != EOF)
		return (0);
	y = -1;
	while (++y < h)
		write(1, field[y], w+1);
	fclose(f);
	return (1);
}

int main(int ac, char *av[])
{
	if (ac != 2)
		return (error("Error: argument\n"));
	if (!process(fopen(av[1], "r")))
		return (error("Error: Operation file corrupted\n"));
	return (0);
}