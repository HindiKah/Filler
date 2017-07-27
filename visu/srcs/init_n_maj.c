#include "../../includes/filler.h"

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

int				**init_intab(int x, int y, int **tab, char **line)
{
	int		w;
	int		h;

	h = 0;
	get_next_line(0, line);
	while (h < y)
	{
		w = 0;
		get_next_line(0, line);
		while (w < x)
		{
			if (line[0][w + 4] == 'o' || line[0][w + 4] == 'O')
				tab[h][w] = 1;
			else if (line[0][w + 4] == 'x' || line[0][w + 4] == 'X')
				tab[h][w] = -1;
			else
				tab[h][w] = 0;
			w++;
		}
		h++;
	}
	return (tab);
}
