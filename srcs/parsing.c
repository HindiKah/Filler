#include "../includes/filler.h"

t_map		*init_playernmap(char *line, t_map *map)
{
	map = (t_map*)malloc(sizeof(t_map));
	while (!ft_strstr(line, "ybenoit"))
		get_next_line(0, &line);
	if (line[10] == '1')
		map->player = 'o';
	else
		map->player = 'x';
	while (!ft_strstr(line, "Plateau"))
		get_next_line(0, &line);
	map->w = ft_atoi(line + 7);
	map->h = ft_atoi(line + ft_num_count(map->w));
	init_intab(map->w, map->h, map->tab);
	return (map);
}

void		init_intab(int x, int y, int **tab)
{
	int		w;
	int		h;

	h = 0;
	tab = (int**)malloc(sizeof(int*) * (y + 1));
	while (h++ <= y + 1)
	{
		w = 0;
		while (w++ < x)
			tab[h][w] = 0;
		tab[h][w] = -1;
	}
}
