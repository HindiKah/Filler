/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 20:52:24 by ybenoit           #+#    #+#             */
/*   Updated: 2017/08/02 17:12:30 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../visu/includes/visu.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_direction
{
	int			xr;
	int			xl;
	int			yd;
	int			yu;
}				t_direction;

typedef struct	s_map
{
	int			error;
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
	int			**resized;
	int			value;
	int			ratio_x;
	int			ratio_y;
	int			ratio_xe;
	int			ratio_ye;
	int			error;
}				t_piece;

t_map			*init_playernmap(char **line, t_map *map);
t_piece			*init_piece(char **line, t_piece *piece);
int				is_not_out(t_map *map, t_piece *piece, t_coord coord);
int				add_tab_value(t_map *map, t_piece *piece, t_coord coord);
int				p_can_enter(t_map *map, t_piece *piece, t_coord coord);
int				can_iplace(t_map *map, t_piece *piece, t_coord coord);
int				val_abs(int x);
int				calc_prox(t_coord c1, t_coord c2);
t_map			*nearest_to(t_map *map, t_piece *piece, t_coord dest);
t_map			*go_to_vs(t_map *map, t_piece *piece, t_coord coord);
t_direction		neighbour(t_coord coord, t_map *map);
t_map			*check_zone(t_map *map, t_piece *piece, t_coord coord);
void			maj_tab(char **line, t_map *map);
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
int				can_i_go_up(t_coord start, int line, t_map *map, int p);
int				can_i_go_lr(t_coord start, int col, t_map *map, int p);
int				**init_intab(int x, int y, int **tab, char **line);
t_coord			*init_home(int y, int x);
t_map			*check_home(t_map *map);
t_map			*init_map_param(t_map *map, char **line);
t_coord			where_to_go(t_map *map);
t_coord			give_start_position(t_map *map);
t_coord			position_up(t_map *map);
t_coord			position_down(t_map *map);
void			init_check_coord(t_coord *begin, t_coord *end, t_piece *piece,
				t_coord coord);
int				else_up(t_coord start, int line, t_map *map, int p);
int				else_lr(t_coord start, int line, t_map *map, int p);
void			resize_piece(t_piece *piece);
int				**mem_intint(int y, int x);
void			init_piece_zero(t_piece *piece);
void			last_y(t_piece *piece);
void			last_x(t_piece *piece);
#endif
