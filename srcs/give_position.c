/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:32:39 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/16 02:24:36 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coord			give_position(t_map *map)
{
	t_coord		ret;

	if (map->up_down == -1 && can_i_go_up(*map->zone,
				0, map, 0) && !map->touchy1)
	{
		ret.x = map->w / 4 * 3;
		ret.y = 0;
		return (ret);
	}
	else if (map->up_down == 1 && can_i_go_up(*map->zone,
				map->h - 1, map, 0)
			&& !map->touchy2)
	{
		ret.x = map->w / 4;
		ret.y = map->h - 1;
		return (ret);
	}
	if (!map->touchx1 && !map->touchx2 &&
			!map->touchy1 && !map->touchy2)
		return (give_start_position(map));
	else
		return (where_to_go(map));
}

t_coord			give_start_position(t_map *map)
{
	t_coord		ret;

	if (map->up_down && (ret.x = check_horiz_start(map->h - 1, map) != 0) &&
			can_i_go_up(*map->zone, map->w - 1, map, 0))
	{
		ret.y = map->h - 1;
		if (ret.x < 0)
			ret.x = 0;
		ret.x = map->tab[map->h][0] == -map->p ?
			map->w : 0;
	}
	else if (map->up_down == -1 && (ret.x = check_horiz_end(0, map)) != 0 &&
			can_i_go_up(*map->zone, 0, map, 0))
	{
		ret.y = 0;
		if (ret.x < 0)
			ret.x = map->tab[0][map->w] == -map->p ?
				0 : map->w;
	}
	else
		return (where_to_go(map));
	return (ret);
}

t_coord			where_to_go(t_map *map)
{
	t_coord		ret;

	if (map->up_down && map->touchy2)
		return (position_up(map));
	else if (map->up_down == -1 && map->touchy1)
		return (position_down(map));
	else if (map->up_down == -1)
	{
		ret.x = (!map->touchy1) ? 0 : map->w - 1;
		ret.y = (!map->touchy1) ? 0 : map->h / 2;
	}
	else
	{
		ret.x = (!map->touchy2) ? map->w - 1 : 0;
		ret.y = (!map->touchy2) ? map->h - 1 : map->h / 2;
	}
	return (ret);
}

t_coord			position_up(t_map *map)
{
	t_coord		ret;

	ret.x = ((map->p == 1 && map->w < 50) || map->w > 50) ? map->w - 1 : 0;
	ret.y = ((map->p == 1 && map->w < 50) || map->w > 50) ? map->h - 1 : 0;
	if (!map->touchy1 && can_i_go_up(*map->zone,
				0, map, map->p))
	{
		ret.x = check_horiz_start(0, map);
		ret.x = ret.x <= 0 ? map->w * 3 / 4 : 0;
		ret.y = 0;
	}
	else if (!map->touchx2 && can_i_go_lr(*map->zone,
				map->w - 1, map, 0))
	{
		ret.y = check_vert_start(map->w - 1, map);
		ret.y += ret.y <= 0 ? map->h / 4 : 0;
		ret.x = map->w - 1;
	}
	return (ret);
}

t_coord			position_down(t_map *map)
{
	t_coord		ret;

	ret.x = ((map->p == 1 && map->w < 50) || map->w > 50) ? 0 : map->w - 1;
	ret.y = ((map->p == 1 && map->w < 50) || map->w > 50) ? 0 : map->h - 1;
	if (!map->touchy2 && can_i_go_up(*map->zone,
				map->h - 1, map, map->p))
	{
		ret.x = check_horiz_start(0, map);
		ret.x += ret.x <= 0 ? map->w / 4 : 0;
		ret.y = map->h - 1;
	}
	else if (!map->touchx1 && can_i_go_lr(*map->zone,
				0, map, map->p))
	{
		ret.y = check_vert_start(0, map);
		ret.y += ret.y <= 0 ? map->h * 3 / 4 : 0;
		ret.x = 0;
	}
	return (ret);
}
