#include "../includes/filler.h"

int			can_i_go_up(t_coord start, int line, t_map *map, int p)
{
	int			x;
	int			dir;
	t_coord		tmp;
	t_direction	n;

	dir = (line - start.y > 0) ? -1 : 1;
	if (start.y == line)
		return (1);
	else if (!start.x || start.x == map->w - 1)
	{
		//debug("ENTER BITCH");
		return (0);
	}
	else
	{
		n = neighbour(start, map);
		/*debug("NEIGHBOUR=");
		debug(ft_itoa(n.xl));
		debug(ft_itoa(n.xr));
		debug(ft_itoa(n.yu));
		debug(ft_itoa(n.yd));
		debug("ZONE");
		debug(ft_itoa(start.x));
		debug(ft_itoa(start.y));*/
	 //sleep(1);
		if ((n.yu == 1 && dir == -1) || (n.yd == 1 && dir == 1))
		{
			tmp.x = start.x;
			tmp.y = start.y - dir;
			return (can_i_go_up(tmp, line, map, 0));
		}
		if (n.xr && p != 1)
		{
			tmp.x = start.x + 1;
			tmp.y = start.y;
			return (can_i_go_up(tmp, line, map, -1));
		}
		if (n.xl && p != -1)
		{
			tmp.x = start.x - 1;
			tmp.y = start.y;
			return (can_i_go_up(tmp, line, map, 1));
		}
	}
	return (0);
}

int			can_i_go_lr(t_coord start, int col, t_map *map, int p)
{
	int			y;
	int			dir;
	t_coord		tmp;
	t_direction	n;

	dir = (col - start.x > 0) ? -1 : 1;
	if (start.x == col)
		return (1);
	else
	{
		n = neighbour(tmp, map);
		if ((n.xl == 1 && dir == -1) || (n.xr == 1 && dir == 1))
		{
			tmp.x = start.x + dir;
			tmp.y = start.y;
			return (can_i_go_up(tmp, col, map, 0));
		}
		if (n.yd && p != 1)
		{
			tmp.x = start.x;
			tmp.y = start.y + 1;
			return (can_i_go_up(tmp, col, map, -1));
		}
		if (n.yu && p != -1)
		{
			tmp.x = start.x;
			tmp.y = start.y - 1;
			return (can_i_go_up(tmp, col, map, 1));
		}
	}
	return (0);
}
