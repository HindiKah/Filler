/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_resize_nf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 20:49:32 by ybenoit           #+#    #+#             */
/*   Updated: 2017/06/15 20:49:37 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_resize_nf(char *str, int start, int end)
{
	char	*ret;
	int		i;

	if (end > (int)ft_strlen(str))
		return (str);
	i = 0;
	ret = (char*)malloc(sizeof(char) * (end - start + 1));
	while (start < end)
		ret[i++] = str[start++];
	ret[i] = '\0';
	return (ret);
}
