#include "../includes/filler.h"

void		display_map(t_map *map)
{
	int y = 0;
	int x = 0;

		ft_putchar_fd('\n', 2);
		ft_putchar_fd(map->tab[0][0], 2);
		ft_putchar_fd('\n', 2);
		ft_putchar_fd('\n', 2);
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			ft_putnbr_fd(map->tab[y][x], 2);
			x++;
		}
		ft_putchar_fd('\n', 2);
		y++;
	}
}
