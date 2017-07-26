/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:05:22 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/15 20:56:03 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_map		*init_playernmap(char **line, t_map *map)
{
	map = (t_map*)malloc(sizeof(t_map));
	get_next_line(0, line);
	while (!ft_strstr(*line, "ybenoit"))
	{
		get_next_line(0, line);
		sleep(1);
	}
	if (ft_strstr(*line, "p1"))
	{
		map->p = 1;
		map->player = 'o';
	}
	else
	{
		map->p = -1;
		map->player = 'x';
	}
	while (!ft_strstr(*line, "Plateau"))
		get_next_line(0, line);
	map = init_touch(map);
	map = init_map_param(map, line);
	return (map);
}

t_map		*init_map_param(t_map *map, char **line)
{
	map->h = ft_atoi(*line + 7);
	map->w = ft_atoi(*line + ft_num_count(map->h) + 8);
	map->tab = init_intab(map->w, map->h, map->tab, line);
	map->zone = (t_coord*)malloc(sizeof(t_coord));
	map->zone->x = map->w / 2;
	map->zone->y = map->h / 2;
	return (map);
}

int			**init_intab(int x, int y, int **tab, char **line)
{
	int		w;
	int		h;

	h = 0;
	get_next_line(0, line);
	tab = (int**)malloc(sizeof(int*) * (y));
	while (h < y)
	{
		w = 0;
		get_next_line(0, line);
		tab[h] = (int*)malloc(sizeof(int) * x);
		while (w < x)
		{
			if (line[0][w + 4] == 'o' || line[0][w + 4] == 'O')
				tab[h][w] = 1;
			else if (line[0][w + 4] == 'x' || line[0][w + 4] == 'X')
				tab[h][w] = -1;
			else
				tab[h][w] = 0;
			w++;
		}
		h++;
	}
	return (tab);
}

t_piece		*init_piece(char **line, t_piece *piece)
{
	int		x;
	int		y;

	y = 0;
	if (!piece)
		return (NULL);
	piece->value = 0;
	piece->h = ft_atoi(*line + 6);
	piece->w = ft_atoi(*line + 6 + ft_num_count(piece->h));
	while (y < piece->h)
	{
		x = 0;
		get_next_line(0, line);
		while (x < piece->w)
		{
			piece->form[y][x] = (line[0][x] == '*') ? 1 : 0;
			piece->value += piece->form[y][x];
			x++;
		}
		y++;
	}
	return (piece);
}

t_map		*maj_tab(char **line, t_map *map)
{
	if (map->tab)
		free(map->tab);
	map->tab = init_intab(map->w, map->h, map->tab, line);
	return (map);
}
