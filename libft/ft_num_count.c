/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:35:32 by ybenoit           #+#    #+#             */
/*   Updated: 2017/01/10 07:31:06 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_count(unsigned long int n)
{
	unsigned long int	i;
	int				pw;

	pw = 1;
	i = n;
	while (i >= 10)
	{
		i /= 10;
		pw++;
	}
	return (pw);
}