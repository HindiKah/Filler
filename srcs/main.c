#include "../includes/filler.h"

void		print_tab(int h, int w, int **tab);
void		print_piece(t_piece *piece);

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
int			main(int argc, const char *argv[])
{
	char		*line;
	t_map		*map;
	t_piece		*piece;

	map = init_playernmap(&line, map);
	map = init_upndown(map);
			display_map(map);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == 'P' && line[1] == 'l')
		{
			map = maj_tab(&line, map);
			check_touch(map);
		}
		if (line[0] == 'P' && line[1] == 'i')
		{
			piece = init_piece(&line, piece);
			piece->p = map->p;
			map = nearest_to(map, piece, give_position(map));
			print(map->zone->y, map->zone->x);
			//sleep(1);
		}
	}

	return 0;
}

void		print_piece(t_piece *piece)
{
	sleep(1);
	ft_putstr_fd("piece {\n\n", 2);
	print_tab(piece->h, piece->w, piece->form);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("H = ", 2);
	ft_putstr_fd(ft_itoa(piece->h), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("W = ", 2);
	ft_putstr_fd(ft_itoa(piece->w), 2);
	ft_putstr_fd("\npiece->p = ", 2);
	ft_putstr_fd(ft_itoa(piece->p), 2);
	ft_putstr_fd("\nValue = ", 2);
	ft_putstr_fd(ft_itoa(piece->value), 2);
	ft_putstr_fd("\n}", 2);
	ft_putstr_fd("\n", 2);
}

void		display_map(t_map *map)
{
	print_tab(map->h, map->w, map->tab);
	debug("map->p = ");
	debug(ft_itoa(map->p));
	debug("map->up_down = ");
	debug(ft_itoa(map->up_down));
	debug("map h/w ");
	ft_putstr_fd(ft_itoa(map->h), 2);
	ft_putstr_fd("/", 2);
	ft_putstr_fd(ft_itoa(map->w), 2);
	debug("");
	if (map->zone)
	{
		ft_putstr_fd("zone x/y = ", 2);
		ft_putstr_fd(ft_itoa(map->zone->x), 2);
		ft_putstr_fd("/", 2);
		ft_putstr_fd(ft_itoa(map->zone->y), 2);
		ft_putstr_fd("\n", 2);
	}
	debug("touchx1 = ");
	debug(ft_itoa(map->touchx1));
	debug("touchx2 = ");
	debug(ft_itoa(map->touchx2));
	debug("touchy1 = ");
	debug(ft_itoa(map->touchy1));
	debug("touchy2 = ");
	debug(ft_itoa(map->touchy2));
	debug("up_down = ");
	debug(ft_itoa(map->up_down));
}

void		print_tab(int h, int w, int **tab)
{
	int x;
	int y;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (tab[y][x] >= 0)
				ft_putstr_fd(ft_itoa(tab[y][x]), 2);
			else
				ft_putstr_fd("2", 2);
			x++;
		}
		ft_putstr_fd("\n", 2);
		y++;
	}
}

void		debug(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}
