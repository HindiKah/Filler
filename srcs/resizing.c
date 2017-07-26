#include "../includes/filler.h"

static void		first_y(t_piece *piece)
{
	int x;
	int y;

	y = 0;
	piece->ratio_y = -1;
	while (y < piece->h)
	{
		x = 0;
		while (x < piece->w)
		{
			if (piece->form[y][x])
			{
				piece->ratio_y = y;
				return;
			}
			x++;
		}
		y++;
	}
}

static void		first_x(t_piece *piece)
{
	int x;
	int y;

	x = 0;
	piece->ratio_x = -1;
	while (x < piece->w)
	{
		y = 0;
		while (y < piece->h)
		{
			if (piece->form[y][x])
			{
				piece->ratio_x = x;
				return;
			}
			y++;
		}
		x++;
	}
}
void			init_piece_zero(t_piece *piece)
{
	int x;
	int y;

	x = 0;
	while (x < 100)
	{
		y = 0;
		while (y < 100)
		{
			piece->form[x][y] = 0;
			piece->resized[x][y] = 0;
			y++;
		}
		x++;
	}
}

int				**mem_intint(int y, int x)
{
	int l;

	l = 0;
	if (x <= 0 || y <= 0)
		return (NULL);
	int **to_alloc;
	to_alloc = (int**)malloc(sizeof(int*) * y);
	if (!to_alloc)
		return (NULL);
	while (l <= y)
	{
		to_alloc[l] = (int*)malloc(sizeof(int) * x);
		if (!to_alloc[l])
			return (NULL);
		l++;
	}
	return (to_alloc);
}

void		resize_piece(t_piece *piece)
{
	int x;
	int y;
	int **tmp;

	first_y(piece);
	first_x(piece);
	y = 0;
	while (y + piece->ratio_y < piece->h)
	{
		x = 0;
		while (x + piece->ratio_x < piece->w)
		{
			piece->resized[y][x] = piece->form[y + piece->ratio_y][x + piece->
				ratio_x];
			x++;
		}
		y++;
	}
	tmp = piece->form;
	piece->form = piece->resized;
	piece->resized = tmp;
	last_x(piece);
	last_y(piece);
	piece->h = piece->ratio_ye + 1;
	piece->w = piece->ratio_xe + 1;
}
