/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:37:26 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/19 17:13:20 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		print(int y, int x)
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

int			main(void)
{
	char		*line;
	t_map		*map;
	t_piece		*piece;

	map = NULL;
	map = init_playernmap(&line, map);
	map = init_upndown(map);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == 'P' && line[1] == 'l')
			map = maj_tab(&line, map);
		if (line[0] == 'P' && line[1] == 'i')
		{
			piece = init_piece(&line, piece);
			piece->p = map->p;
			check_touch(map);
			map = nearest_to(map, piece, give_position(map));
			print(map->zone->y, map->zone->x);
		}
	}
	if (piece)
		free(piece);
	if (map)
		free(map);
	return (0);
}
