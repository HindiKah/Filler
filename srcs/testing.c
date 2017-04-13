#include "../includes/filler.h"

int			can_iplace(t_map *map, t_piece *piece, t_coord coord)
{
	if (is_not_out(map, piece, coord))
	{
		if (p_can_enter(map, piece, coord) && add_tab_value(map, piece, coord) == 1)
		return (1);
	}
	return (0);
}

t_direction	neighbour(t_coord coord, t_map *map)
{
	int			x;
	int			y;
	t_direction	ret;

	x = coord.x;
	y = coord.y;
	ret.x = 0;
	ret.y = 0;
	if (x + 1 < map->w)
		ret.x += (map->tab[y][x + 1] == map->p) ? 1 : 0;
	if (x - 1 >= 0)
		ret.x -= (map->tab[y][x - 1] == map->p) ? 1 : 0;
	if (y + 1 < map->h)
		ret.y += (map->tab[y + 1][x] == map->p) ? 1 : 0;
	if (y - 1 >= 0)
		ret.y -= (map->tab[y - 1][x] == map->p) ? 1 : 0;
	return (ret);
}

t_map		*init_touch(t_map *map)
{
	map->touchx1 = 0;
	map->touchx2 = 0;
	map->touchy1 = 0;
	map->touchy2 = 0;
	return (map);
}
