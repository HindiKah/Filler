/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:13:30 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/28 11:13:53 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

typedef struct	s_map
{
	char		player;
	int			w;
	int			h;
	int			**tab;
}				t_map;

typedef struct	s_piece
{
	int			**p;
}				t_piece;

t_map			*init_playernmap(char *line, t_map *map);
void			init_intab(char *line, t_map *map);
int				*init_line(char *line, int *l, int w);

//TESTING FUNCTION
void	display_map(t_map *map);
#endif
