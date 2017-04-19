/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:38:38 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 16:47:09 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			init_check_coord(t_coord *begin, t_coord *end, t_piece *piece,
					t_coord coord);

t_map			*nearest_to(t_map *map, t_piece *piece, t_coord dest)
{
	int			v;

	v = map->p;
	map = go_to_vs(map, piece, dest);
	return (map);
}

t_map			*go_to_vs(t_map *map, t_piece *piece, t_coord coord)
{
	int			x;
	int			y;
	t_coord		dest;

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
	t_coord	start;
	t_coord	end;
	t_coord	ret;

	init_check_coord(&start, &end, piece, coord);
	while (start.y <= end.y)
	{
		start.x = coord.x - (piece->w - 1);
		while (start.x <= end.x)
		{
			ret.x = start.x;
			ret.y = start.y;
			if (can_iplace(map, piece, ret) == 1)
			{
				map->zone->x = start.x;
				map->zone->y = start.y;
				return (map);
			}
			start.x++;
		}
		start.y++;
	}
	ret.x = -1;
	return (map);
}

void			init_check_coord(t_coord *begin, t_coord *end, t_piece *piece,
		t_coord coord)
{
	begin->x = coord.x - (piece->w - 1) >= 0 ? coord.x - (piece->w - 1) : 0;
	begin->y = coord.y - (piece->h - 1) >= 0 ? coord.y - (piece->h - 1) : 0;
	end->x = coord.x + (piece->w - 1);
	end->y = coord.y + (piece->h - 1);
}
