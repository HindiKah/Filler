/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:00:18 by ybenoit           #+#    #+#             */
/*   Updated: 2017/08/02 15:00:20 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
