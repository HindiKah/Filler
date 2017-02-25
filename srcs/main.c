#include "../includes/filler.h"

void		print(int x, int y)
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
	int			i = 0;

while (get_next_line(0, &line) > 0)
	{
		if (i == 0)
		{
			ft_putstr_fd("back in main", 2);
			print(2, 8);
			i++;
		}
	}
	return 0;
}
