/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:13:20 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/26 18:11:35 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_map		*init_playernmap(char *line, t_map *map)
{
	map = (t_map*)malloc(sizeof(t_map));
	if (!map)
		exit(0);
	while ((get_next_line(0, &line)) < 0)
	{
		if (ft_strstr(line, "ybe"))
			break;
	}
	if (line[10] == '1')
		map->player = 'o';
	else
		map->player = 'x';
	while (!ft_strstr(line, "Plateau"))
		get_next_line(0, &line);
	ft_putstr_fd(line, 2);
	map->h = ft_atoi(line + 7);
	map->w = ft_atoi(line + (ft_num_count(map->h) + 8));
	init_intab(map);
	return (map);
}

void		init_intab(t_map *map)
{
	int		w;
	int		h;

	h = 0;
	map->tab = (int**)malloc(sizeof(int*) * map->h);
	if (!map->tab)
		exit(0);
		ft_putchar_fd('\n', 2);
	while (h < map->h)
	{
		w = 0;
		map->tab[h] = (int*)malloc(sizeof(int) * map->w);
		if (!map->tab[h])
			exit(0);
		while (w < map->w)
		{
			map->tab[h][w] = 0;
			w++;
		}
		h++;
	}
}
