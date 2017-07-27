#include "../../includes/filler.h"
#include "../includes/visu.h"

static int		give_color(int player)
{
	if (player == 1)
		return (0xFF0000);
	else
		return (0x0000FF);
}

static void		draw_fullsquare(t_env *env, int x, int y, int p)
{
	int i;
	int j;

	i = 0;
	while (i < env->ratio_x)
	{
		j = 0;
		while (j < env->ratio_y)
		{
			put_pixel(env, i + x, j + y, give_color(p));
			j++;
		}
		i++;
	}
}

static void		draw_emptysquare(t_env *env, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < env->ratio_y)
	{
		put_pixel(env, i + x, j + y, 0);
		j++;
	}
	while (i < env->ratio_x)
	{
		put_pixel(env, i + x, j + y, 0);
		i++;
	}
	while (j >= 0)
	{
		put_pixel(env, i + x, j + y, 0);
		j--;
	}
	while (i >= 0)
	{
		put_pixel(env, i + x, j + y, 0);
		i--;
	}
}

void			put_pixel(t_env *env, int x, int y, unsigned int c)
{
	int i;

	i = (x * 4) + (y * env->size_l);
	if (i < 1440000)
	{
	env->data[i] = c;
	env->data[++i] = c >> 8;
	env->data[++i] = c >> 16;
	}
}

void		draw_grid(t_env *env)
{
	int i;
	int j;

	j = 0;
	while (j < env->tab_h)
	{
		i = 0;
		while (i < env->tab_w)
		{
			if (env->tab[j][i] == 1)
			{
				draw_fullsquare(env, i * env->ratio_x,
						j * env->ratio_y, 1);
			}
			else if (env->tab[j][i] == -1)
			{
				draw_fullsquare(env, i * env->ratio_x,
						j * env->ratio_y, -1);
			}
			draw_emptysquare(env, i * env->ratio_x,
					j * env->ratio_y);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(env->mlx_p, env->win, env->img_p, 0, 0);
}
