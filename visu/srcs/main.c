#include "../../includes/filler.h"

static t_env	*init_env(t_env *env)
{
	env = (t_env*)malloc(sizeof(t_env));
	env->tab = mem_intint(110, 110);
	env->mlx_p = mlx_init();
	env->img_p = mlx_new_image(env->mlx_p, WIN_X, WIN_Y);
	env->data = (char*)mlx_get_data_addr(env->img_p,
			&env->bpp, &env->size_l,  &env->endian);
	return (env);
}

static t_env	*init_param(char **line, t_env *map)
{
	get_next_line(0, line);
	while (!ft_strstr(*line, "Plateau"))
	{
		if (line[0][0] < 30)
			exit(0);
		get_next_line(0, line);
	}
	map->tab_h = ft_atoi(*line + 7);
	map->tab_w = ft_atoi(*line + ft_num_count(map->tab_h)
			+ 8);
	map->ratio_x = WIN_X / map->tab_w;
	map->ratio_y = WIN_Y / map->tab_h;
	map->tab = init_intab(map->tab_w, map->tab_h, map->tab,
			line);
	return (map);
}

void		print_tab(t_env *env)
{
	int i;
	int j;

	j = 0;
	while (j < env->tab_h)
	{
		i = 0;
		while (i < env->tab_w)
		{
			dprintf(2, "%d ", env->tab[j][i]);
			i++;
		}
		j++;
		dprintf(2, "\n");
	}
}

int				main(void)
{
	char	*line;
	t_env	*env;

	line = NULL;
	env = NULL;
	env = init_env(env);
	init_param(&line, env);
	env->win = mlx_new_window(env->mlx_p, WIN_X, WIN_Y, "Filler");
	mlx_key_hook(env->win, key_fun, env);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == 'P' && line[1] == 'l')
			env->tab = init_intab(env->tab_w, env->tab_h,
					env->tab, &line);
		draw_grid(env);
	}
	mlx_loop(env->mlx_p);
	return (0);
}