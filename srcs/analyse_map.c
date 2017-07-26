/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:01:03 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 17:01:13 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_map		*init_upndown(t_map *map)
{
	if (map->player == 'o')
		map->up_down = 1;
	else
		map->up_down = -1;
	if (map->w > 50)
		map->up_down = -map->up_down;
	return (map);
}

t_map		*init_rightnleft(t_map *map)
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
