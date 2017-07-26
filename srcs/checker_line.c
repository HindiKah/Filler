/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:01:35 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 17:04:30 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			check_horiz_start(int line, t_map *map)
{
	int x;
	int ret;

	ret = 0;
	x = 0;
	if (line > map->h - 1)
		return (-1);
	while (x < map->w)
	{
		if (x - 1 >= 0 && !ret)
		{
			if (!map->tab[line][x - 1] && map->tab[line][x] == -map->p)
				ret = x - 1;
		}
		else if (!map->tab[line][x])
			ret = -1;
		x++;
	}
	return (ret);
}

int			check_vert_start(int col, t_map *map)
{
	int y;
	int ret;

	ret = 0;
	y = 0;
	if (col > map->h - 1)
		return (-1);
	while (y < map->h)
	{
		if (y - 1 >= 0 && !ret)
		{
			if (!map->tab[y - 1][col] && map->tab[y][col] == -map->p)
				ret = y - 1;
		}
		else if (!map->tab[y][col])
			ret = -1;
		y++;
	}
	return (ret);
}

int			check_horiz_end(int line, t_map *map)
{
	int x;
	int ret;

	ret = 0;
	x = map->w - 1;
	if (line > map->h - 1)
		return (-1);
	while (x > 0)
	{
		if (x + 1 < map->w && !ret)
		{
			if (!map->tab[line][x + 1] && map->tab[line][x] == -map->p)
				ret = x + 1;
		}
		else if (!map->tab[line][x])
			ret = -1;
		x--;
	}
	return (ret);
}

int			check_vert_end(int col, t_map *map)
{
	int y;
	int ret;

	ret = 0;
	y = map->h - 1;
	if (col > map->h - 1)
		return (-1);
	while (y > 0)
	{
		if (y + 1 < map->h && !ret)
		{
			if (!map->tab[y + 1][col] && map->tab[y][col] == -map->p)
				ret = y + 1;
		}
		else if (!map->tab[y][col])
			ret = -1;
		y--;
	}
	return (ret);
}

t_map		*check_touch(t_map *map)
{
	map->touchx1 = 0;
	map->touchx2 = 0;
	map->touchy1 = 0;
	map->touchy2 = 0;
	map->touchx1 = touch_vert(0, map);
	map->touchx2 = touch_vert(map->w - 1, map);
	map->touchy1 = touch_horiz(0, map);
	map->touchy2 = touch_horiz(map->h - 1, map);



	return (map);
}
