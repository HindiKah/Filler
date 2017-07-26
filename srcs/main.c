/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:37:26 by ybenoit           #+#    #+#             */
/*   Updated: 2017/07/25 17:23:51 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		print(int y, int x)
{
	ft_putstr(ft_itoa(y));
	ft_putstr_fd(ft_itoa(y), 2);
	ft_putchar(' ');
	ft_putchar_fd(' ', 2);
	ft_putstr(ft_itoa(x));
	ft_putstr_fd(ft_itoa(x), 2);
	ft_putchar_fd('\n', 2);
	ft_putchar('\n');
}

void			print_tab(int **tab)
{
	int y = 0;

	while (y < 50)
	{
		int x = 0;
		while (x < 50)
		{
			dprintf(2, "%d ", tab[y][x]);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

static void		init_all(t_map **map, char *line, t_piece **piece)
{
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

int				main(void)
{
	char		*line;
	t_map		*map;
	t_piece		*piece;

	piece = NULL;
	map = NULL;
	line = NULL;
	init_all(&map, line, &piece);
	while (get_next_line(0, &line) > 0 && !map->error)
	{
		if (line[0] == 'P' && line[1] == 'l')
			map = maj_tab(&line, map);
		if (line[0] == 'P' && line[1] == 'i')
		{
			piece = init_piece(&line, piece);
			piece->p = map->p;
			resize_piece(piece);
			check_touch(map);
			map = nearest_to(map, piece, give_position(map));
			print(map->zone->y - piece->ratio_y, map->zone->x - 
				piece->ratio_x);
		}
	}
	free(piece);
	free(map);
	return (0);
}
