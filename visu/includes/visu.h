#ifndef VISU_H
# define VISU_H

# include <mlx.h>
# include <math.h>

# define WIN_X 600
# define WIN_Y 600
# define EXIT 53

typedef struct	s_env
{
	void		*mlx_p;
	void		*win;
	void		*img_p;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			tab_w;
	int			tab_h;
	double		ratio_x;
	double		ratio_y;
	int			**tab;
}				t_env;

int				key_fun(int k, t_env *e);
void			put_pixel(t_env *env, int x, int y,
					unsigned int color);
void			draw_grid(t_env *env);

#endif
