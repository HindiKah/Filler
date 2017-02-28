#include "../includes/filler.h"

void		print(int x, int y)
{
	ft_putstr_fd(ft_itoa(y), 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd(ft_itoa(x), 2);
	ft_putchar_fd('\n', 2);
}
int			main(int argc, const char *argv[])
{
	char				*line;
	static t_map		*map;

		map = init_playernmap(line, map);
		sleep(1);
		display_map(map);
		//if (line[0] = 'P' && line[1] == 'i')
		//	init_piece(map);
		//print_coord(map);
	return 0;
}
