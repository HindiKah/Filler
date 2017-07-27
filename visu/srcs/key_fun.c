#include "../includes/visu.h"
#include "../../includes/filler.h"

int			key_fun(int k, t_env *e)
{
	if (k == EXIT)
	{
		mlx_destroy_window(e->mlx_p, e->win);
		exit(0);
	}
	return (0);
}
