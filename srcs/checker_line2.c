/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_line2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:59:59 by ybenoit           #+#    #+#             */
/*   Updated: 2017/08/02 14:57:38 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		touch_horiz(int line, t_map *map)
{
	int x;

	x = 0;
	if ((line > map->h - 1 && map->w > 50) ||
			(map->w < 50 && line > map->w - 1) || line < 0)
		return (666);
	while (x < map->w)
	{
		if (map->tab[line][x] == map->p)
			return (1);
		x++;
	}
	return (0);
}

int		touch_vert(int col, t_map *map)
{
	int y;

	y = 0;
	if ((col > map->w - 1 && map->w > 50) ||
			(map->w < 50 && col > map->h - 1) || col < 0)
		return (666);
	while (y < map->h)
	{
		if (map->tab[y][col] == map->p)
			return (1);
		y++;
	}
	return (0);
}
