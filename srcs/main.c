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

	if (!map)
		map = init_playernmap(line, map);
	//display_map(map);
while ((get_next_line(0, &line)) > 0)
	{
			ft_putstr_fd("\t\t\t", 2);
			ft_putstr_fd(line, 2);
			ft_putstr_fd("\n", 2);
	}
	return 0;
}
