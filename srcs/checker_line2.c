#include "../includes/filler.h"

int touch_horiz(int line,  t_map *map)
{
	int x;

	x = 0;
	if (line > map->w - 1)
		return (666);
	while (x < map->w)
	{
		debug(ft_itoa(x));
		debug(ft_itoa(line));
		if (map->tab[line][x] == map->p)
			return (1);
		x++;
	}
	return (0);
}

int touch_vert(int col,  t_map *map)
{
	int y;

	y = 0;
	if (col > map->h - 1)
		return (666);
	while (y < map->h)
	{
		if (map->tab[y][col] == map->p)
			return (1);
		y++;
	}
	return (0);
}
