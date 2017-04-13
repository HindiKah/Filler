#include "../includes/filler.h"

t_map			*nearest_to(t_map *map, t_piece *piece, t_coord dest)
{
	int			v;

	v = map->p;
	map = go_to_vs(map, piece, dest);
	return (map);
}

t_map			*go_to_vs(t_map *map, t_piece *piece, t_coord coord)
{
	int x;
	int y;
	t_coord dest;

	y = 0;
	map->zone->x = -1;
	while (y < map->h)
	{
		x = 0;
		dest.y = y;
		while (x < map->w)
		{
			dest.x = x;
			if (map->zone->x == -1)
				map = check_zone(map, piece, dest);
			else if ((calc_prox(coord, dest) < calc_prox(*map->zone, coord)))
				map = check_zone(map, piece, dest);
			x++;
		}
		y++;
	}
	return (map);
}

int				calc_prox(t_coord c1, t_coord c2)
{
	return (val_abs(c1.x - c2.x) + val_abs(c1.y - c2.y));
}

t_map			*check_zone(t_map *map, t_piece *piece, t_coord coord)
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	t_coord ret;

	x1 = coord.x - (piece->w - 1) >= 0 ? coord.x - (piece->w - 1): 0 ;
	y1 = coord.y - (piece->h - 1) >= 0 ? coord.y - (piece->h - 1): 0 ;
	x2 = coord.x + (piece->w - 1);
	y2 = coord.y + (piece->h - 1);
	while (y1 <= y2)
	{
		x1 = coord.x - (piece->w - 1);
		while (x1 <= x2)
		{
			ret.x = x1;
			ret.y = y1;
			if (can_iplace(map, piece, ret) == 1)
			{
				map->zone->x = x1;
				map->zone->y = y1;
				return (map);
			}
				/*debug("y/x =");
				ft_putstr_fd(ft_itoa(y1), 2);
				ft_putstr_fd("/", 2);
				ft_putstr_fd(ft_itoa(x1), 2);
				ft_putstr_fd("\n", 2);
				*/
			x1++;
		}
		y1++;
	}
	ret.x = -1;
	return (map);
}
