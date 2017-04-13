#include "../includes/filler.h"

t_map		*init_upndown(t_map *map)
{
	int w;
	int h;

	h = 0;
	while (h < map->h)
	{
		w = 0;
		while (w < map->w)
		{
			if (map->tab[h][w] != 0)
			{
				if (map->tab[h][w] == map->p)
					map->up_down = 1;
				else
					map->up_down = -1;
				return (map);
			}
			w++;
		}
		h++;
	}
	return (map);
}

t_map			*init_rightnleft(t_map *map)
{
	int w;
	int h;

	w = 0;
	while (w < map->w)
	{
		h = 0;
		while (h < map->h)
		{
			if (map->tab[h][w] != 0)
			{
				if (map->tab[h][w] == map->p)
					map->right_left = -1;
				else
					map->right_left = 1;
				return (map);
			}
			h++;
		}
		w++;
	}
	return (map);
}
