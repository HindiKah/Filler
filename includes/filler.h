#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_direction
{
	int			x;
	int			y;
}				t_direction;

	typedef struct	s_map
{
	char		player;
	int			p;
	int			w;
	int			h;
	int			up_down;
	int			right_left;
	int			touchx1;
	int			touchx2;
	int			touchy1;
	int			touchy2;
	t_coord		*zone;
	int			dif;
	int			**tab;
}				t_map;


typedef struct	s_piece
{
	int			h;
	int			w;
	int			p;
	int			**form;
	int			value;
}				t_piece;

t_map			*init_playernmap(char **line, t_map *map);
t_piece			*init_piece(char **line, t_piece *piece);
int				is_not_out(t_map *map, t_piece *piece, t_coord coord);
int				add_tab_value(t_map *map,t_piece *piece, t_coord coord);
int				p_can_enter(t_map *map, t_piece *piece, t_coord coord);
int				can_iplace(t_map *map, t_piece *piece, t_coord coord);
int				val_abs(int x);
int				calc_prox(t_coord c1, t_coord c2);
t_map			*nearest_to(t_map *map, t_piece *piece, t_coord dest);
t_map			*go_to_vs(t_map *map, t_piece *piece,  t_coord coord);
t_direction		neighbour(t_coord coord, t_map *map);
t_map			*check_zone(t_map *map, t_piece *piece, t_coord coord);
t_map			*maj_tab(char **line, t_map *map);
t_map			*init_upndown(t_map *map);
t_map			*init_rightnleft(t_map *map);
t_map			*init_touch(t_map *map);
t_coord			give_position(t_map *map);
int				check_horiz_start(int c, t_map *map);
int				check_vert_start(int c, t_map *map);
int				check_horiz_end(int c, t_map *map);
int				check_vert_end(int c, t_map *map);
t_map			*check_touch(t_map *map);
int				touch_horiz(int c, t_map *map);
int				touch_vert(int c, t_map *map);





void			debug(char *str);
#endif
