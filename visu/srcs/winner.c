/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:00:27 by ybenoit           #+#    #+#             */
/*   Updated: 2017/08/02 15:04:05 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"
#include "../../includes/filler.h"

void		winner(char *line, t_env *env)
{
	int one;
	int two;

	get_next_line(0, &line);
	one = ft_atoi(line + 11);
	get_next_line(0, &line);
	two = ft_atoi(line + 11);
	dprintf(2, "coucou\n");
	if (one > two)
		mlx_string_put(env->mlx_p, env->win, 250, 605,
				0x00FF00, "Player 1 won");
	else
		mlx_string_put(env->mlx_p, env->win, 250, 250,
				0x00FF00, "Player 2 won");
	mlx_put_image_to_window(env->mlx_p, env->win, env->img_p, 0, 0);
	mlx_do_sync(env->mlx_p);
}
