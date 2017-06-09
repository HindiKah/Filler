/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:47:16 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 16:55:45 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			else_up(t_coord start, int line, t_map *map, int p);
int			else_lr(t_coord start, int line, t_map *map, int p);

int			can_i_go_up(t_coord start, int line, t_map *map, int p)
{
	int			dir;

	dir = (line - start.y > 0) ? -1 : 1;
	if (start.y == line)
		return (1);
	else if (!start.x || start.x == map->w - 1)
		return (0);
	else
		return (else_up(start, line, map, p));
}

int			else_up(t_coord start, int line, t_map *map, int p)
{
	t_coord		tmp;
	int			dir;
	t_direction	n;

	dir = (line - start.y > 0) ? -1 : 1;
	n = neighbour(start, map);
	if ((n.yu == 1 && dir == -1) || (n.yd == 1 && dir == 1))
	{
		tmp.x = start.x;
		tmp.y = start.y - dir;
		return (can_i_go_up(tmp, line, map, 0));
	}
	if (n.xr && p != 1)
	{
		tmp.x = start.x + 1;
		tmp.y = start.y;
		return (can_i_go_up(tmp, line, map, -1));
	}
	if (n.xl && p != -1)
	{
		tmp.x = start.x - 1;
		tmp.y = start.y;
		return (can_i_go_up(tmp, line, map, 1));
	}
	return (0);
}

int			can_i_go_lr(t_coord start, int col, t_map *map, int p)
{
	int			dir;

	dir = (col - start.x > 0) ? -1 : 1;
	if (start.x == col)
		return (1);
	else
		return (else_lr(start, col, map, p));
	return (0);
}

int			else_lr(t_coord start, int col, t_map *map, int p)
{
	t_coord		tmp;
	int			dir;
	t_direction	n;

	dir = (col - start.x > 0) ? -1 : 1;
	n = neighbour(start, map);
	if ((n.xl == 1 && dir == -1) || (n.xr == 1 && dir == 1))
	{
		tmp.x = start.x + dir;
		tmp.y = start.y;
		return (can_i_go_up(tmp, col, map, 0));
	}
	if (n.yd && p != 1)
	{
		tmp.x = start.x;
		tmp.y = start.y + 1;
		return (can_i_go_up(tmp, col, map, -1));
	}
	if (n.yu && p != -1)
	{
		tmp.x = start.x;
		tmp.y = start.y - 1;
		return (can_i_go_up(tmp, col, map, 1));
	}
	return (0);
}
