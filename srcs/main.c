/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:37:26 by ybenoit           #+#    #+#             */
/*   Updated: 2017/08/02 17:17:11 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		print(int y, int x)
{
	char *yc;
	char *xc;

	yc = ft_itoa(y);
	xc = ft_itoa(x);
	ft_putstr(yc);
	ft_putstr_fd(yc, 2);
	ft_putchar(' ');
	ft_putchar_fd(' ', 2);
	ft_putstr(xc);
	ft_putstr_fd(xc, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar('\n');
	free(xc);
	free(yc);
}

static void		init_all(t_map **map, char *line, t_piece **piece)
{
	map[0] = (t_map*)malloc(sizeof(t_map));
	map[0]->tab = mem_intint(100, 100);
	*map = init_playernmap(&line, *map);
	map[0]->error = 0;
	*map = init_upndown(*map);
	*piece = (t_piece*)malloc(sizeof(t_piece));
	piece[0]->form = mem_intint(100, 100);
	piece[0]->resized = mem_intint(100, 100);
	init_piece_zero(*piece);
	if (!*piece || !*map || !piece[0]->form || !piece[0]->resized)
		map[0]->error = 1;
}

static void		main_think(t_piece *piece, t_map *map, char *line)
{
	init_piece_zero(piece);
	piece = init_piece(&line, piece);
	piece->p = map->p;
	resize_piece(piece);
	check_touch(map);
	map = nearest_to(map, piece, give_position(map));
	print(map->zone->y - piece->ratio_y, map->zone->x -
			piece->ratio_x);
}

static void		cleaning(t_piece **piece, t_map **map)
{
	int i = 0;

	while (i < 100)
	{
		free(map[0]->tab[i]);
		free(piece[0]->form[i]);
		free(piece[0]->resized[i]);
		i++;
	}
	free(map[0]->tab);
	free(piece[0]->form);
	free(piece[0]->resized);
	free(map[0]->zone);
	free(*piece);
	free(*map);
}

int				main(void)
{
	char		*line;
	t_map		*map;
	t_piece		*piece;

	piece = NULL;
	map = NULL;
	line = NULL;
	if (!map)
		init_all(&map, line, &piece);
	while (get_next_line(0, &line) > 0 && map && piece)
	{
		if (line[0] == 'P' && line[1] == 'l')
		{
			free(line);
			maj_tab(&line, map);
		}
		if (line[0] == 'P' && line[1] == 'i')
		{
			free(line);
			main_think(piece, map, line);
		}
	}
	free(line);
	cleaning(&piece, &map);
	return (0);
}
