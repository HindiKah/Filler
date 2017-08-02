/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resizing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:44:16 by ybenoit           #+#    #+#             */
/*   Updated: 2017/08/02 16:34:03 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	last_y(t_piece *piece)
{
	int x;
	int y;

	y = 49;
	piece->ratio_ye = -1;
	while (y >= 0)
	{
		x = 0;
		while (x < piece->w)
		{
			if (piece->form[y][x] && piece->ratio_ye == -1)
			{
				piece->ratio_ye = y;
				return ;
			}
			x++;
		}
		y--;
	}
}

void	last_x(t_piece *piece)
{
	int x;
	int y;

	x = 49;
	piece->ratio_xe = -1;
	while (x >= 0)
	{
		y = 0;
		while (y < piece->h)
		{
			if (piece->form[y][x] && piece->ratio_xe == -1)
			{
				piece->ratio_xe = x;
				return ;
			}
			y++;
		}
		x--;
	}
}
