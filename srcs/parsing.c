#include "../includes/filler.h"

int			**init_intab(int x, int y, int **tab, char **line);
t_coord		*init_home(int y, int x);
t_map		*check_home(t_map *map);

t_map		*init_playernmap(char **line, t_map *map)
{
	map = (t_map*)malloc(sizeof(t_map));
	get_next_line(0, line);
	while (!ft_strstr(*line, "ybenoit"))
	{
		get_next_line(0, line);
		sleep(1);
	}
	if (ft_strstr(*line, "p1"))
	{
		map->p = 1;
		map->player = 'o';
	}
	else
	{
		map->p = -1;
		map->player = 'x';
	}
	while (!ft_strstr(*line, "Plateau"))
		get_next_line(0, line);
	map = init_touch(map);
	map->h = ft_atoi(*line + 7);
	map->w = ft_atoi(*line + ft_num_count(map->h) + 8);
	map->tab = init_intab(map->w, map->h, map->tab, line);
	map->zone = (t_coord*)malloc(sizeof(t_coord));
	map->zone->x = -1;
	return (map);
}

int			**init_intab(int x, int y, int **tab, char **line)
{
	int		w;
	int		h;

	h = 0;
	get_next_line(0, line);
	tab = (int**)malloc(sizeof(int*) * (y));
	while (h < y)
	{
		w = 0;
		get_next_line(0, line);
		tab[h] = (int*)malloc(sizeof(int) * x);
		while (w < x)
		{
			if (line[0][w + 4] == 'o' || line[0][w + 4] == 'O')
				tab[h][w] = 1;
			else if (line[0][w + 4] == 'x' ||
					line[0][w + 4]  == 'X')
				tab[h][w] = -1;
			else
				tab[h][w] = 0;
			w++;
		}
		h++;
	}
	return (tab);
}

t_piece			*init_piece(char **line, t_piece *piece)
{
	int		x;
	int		y;

	y = 0;
	if (piece)
		free(piece);
	piece = (t_piece*)malloc(sizeof(t_piece));
	piece->value = 0;
	while (!ft_strstr(*line, "Pi"))
		get_next_line(0, line);
	piece->h = ft_atoi(*line + 6);
	piece->w = ft_atoi(*line + 6 + ft_num_count(piece->h));
	piece->form = (int**)malloc(sizeof(int*) * piece->h);
	while (y < piece->h)
	{
		x = 0;
		get_next_line(0, line);
		piece->form[y] = (int*)malloc(sizeof(int) * piece->w);
		while (x < piece->w)
		{
			piece->form[y][x] = (line[0][x] == '*') ? 1 : 0;
			piece->value += piece->form[y][x];
			x++;
		}
		y++;
	}
	return (piece);
}

t_map			*maj_tab(char **line, t_map *map)
{
	if (map->tab)
		free(map->tab);
	map->tab = init_intab(map->w, map->h, map->tab, line);
	return (map);
}

