/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:13:20 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/28 11:31:32 by ybenoit          ###   ########.fr       */
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
	init_intab(line, map);
	return (map);
}

void		init_intab(char *line, t_map *map)
{
	int		w;
	int		h;

	h = 0;
	map->tab = (int**)malloc(sizeof(int*) * map->h);
	if (!map->tab)
		exit(0);
	ft_putchar_fd('\n', 2);
	while (line[0] != ' ')
		get_next_line(0, &line);
	while ((get_next_line(0, &line)) > 0)
	{
		w = 0;
		map->tab[h] = (int*)malloc(sizeof(int) * map->w);
		if (!map->tab[h])
			exit(0);
		init_line(line, map->tab[h], map->w);
		h++;
		if (h == map->h)
			break;
	}
}

int			*init_line(char *line, int *l, int w)
{
	int i;

	i = 5;
	while ((i - 4) < w)
	{
		l[i - 4] = (line[i] == '.') ? 0 : ((line[i] == 'X' || line[i] == 'x') 
				? 2 : 1);
		i++;
	}
		return (l);
}
