/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:13:28 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 17:13:58 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			is_not_out(t_map *map, t_piece *piece, t_coord coord)
{
	if (map->h >= coord.y + piece->h && map->w >= coord.x + piece->w &&
			coord.y >= 0 && coord.x >= 0)
		return (1);
	else
		return (0);
}

int			p_can_enter(t_map *map, t_piece *piece, t_coord coord)
{
	int x1;
	int y1;
	int x2;
	int y2;

	y1 = coord.y;
	x2 = coord.x + piece->w;
	y2 = coord.y + piece->h;
	while (y1 < y2)
	{
		x1 = coord.x;
		while (x1 < x2)
		{
			if (piece->form[y1 - coord.y][x1 - coord.x] && map->tab[y1][x1])
			{
				if (map->tab[y1][x1] != piece->p)
					return (0);
			}
			x1++;
		}
		y1++;
	}
	return (1);
}

int			add_tab_value(t_map *map, t_piece *piece, t_coord coord)
{
	int x;
	int y;
	int ret;

	y = coord.y;
	ret = 0;
	while (y < coord.y + piece->h)
	{
		x = coord.x;
		while (x < coord.x + piece->w)
		{
			ret += (piece->form[y - coord.y][x - coord.x] &&
					map->tab[y][x] == piece->p)
				? 1 : 0;
			x++;
		}
		y++;
	}
	return (ret);
}

int			val_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}
