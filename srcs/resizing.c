#include "../includes/filler.h"

static void		first_y(t_piece *piece)
{
	int x;
	int y;

	y = 0;
	while (y < piece->h)
	{
		x = 0;
		while (x < piece->w)
		{
			if (piece->form[y][x] && piece->ratio_y == -1)
				piece->ratio_y = y;
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
	while (x < piece->w)
	{
		y = 0;
		while (y < piece->h)
		{
			if (piece->form[y][x] && piece->ratio_x == -1)
				piece->ratio_x = x;;
			y++;
		}
		x++;
	}
}

static int	**mem_intint(int y, int x)
{
	int l;

	l = 0;
	int **to_alloc;
	to_alloc = (int**)malloc(sizeof(int*) * y);
	while (l <= y)
	{
		to_alloc[l] = (int*)malloc(sizeof(int) * x);
		l++;
	}
	return (to_alloc);
}

static void		clean_piece(t_piece *piece)
{
	int y;

	y = 0;
	while (y < piece->h)
	{
		if (piece->form[y])
			free(piece->form[y]);
		y++;
	}
	free(piece);
}

void		resize_piece(t_piece *piece)
{
	int x;
	int y;
	int **resized;

	first_y(piece);
	first_x(piece);
	resized = mem_intint(piece->h - piece->ratio_y + 1, 
			piece->w - piece->ratio_x + 1);
	y = 0;
	while (y + piece->ratio_y < piece->h)
	{
		x = 0;
		while (x + piece->ratio_x < piece->w)
		{
			resized[y][x] = piece->form[y + piece->ratio_y][x + piece->
				ratio_x];
			x++;
		}
		y++;
	}
	clean_piece(piece);
	piece->h = piece->h - piece->ratio_y;
	piece->w = piece->w - piece->ratio_x;
	piece->form = resized;
}
