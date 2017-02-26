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


#endif
