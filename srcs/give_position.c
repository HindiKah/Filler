#include "../includes/filler.h"

t_coord			where_to_go(t_map *map);
t_coord			give_start_position(t_map *map);

t_coord			give_position(t_map *map)
{
	t_coord		ret;

	if (map->up_down == -1 && (check_horiz_end(0, map)) != 0 && !map->touchy1)
	{
		ret.x = map->w / 2;
		ret.y = 0;
		return (ret);
	}
	else if (map->up_down == 1 && (check_horiz_end(0, map)) != 0 && !map->touchy2)
	{
		ret.x = map->w / 2;
		ret.y = map->h - 1;
		return (ret);
	}
	if (!map->touchx1 && !map->touchx2 &&
			!map->touchy1 && !map->touchy2)
		return (give_start_position(map));
	else
		return (where_to_go(map));
}

t_coord			give_start_position(t_map *map)
{
	t_coord		ret;

	if (map->up_down && (ret.x = check_horiz_start(map->h - 1, map) != 0))
	{
		ret.y = map->h - 1;
		if (ret.x < 0)
			ret.x = map->w /2;
	}
	else if (map->up_down == -1 && (ret.x = check_horiz_end(0, map)) != 0)
	{
		ret.y = 0;
		if (ret.x < 0)
			ret.x = map->w / 2;
	}
	else
		return (where_to_go(map));
	return (ret);
}

t_coord			where_to_go(t_map *map)
{
	t_coord		ret;

	if (map->up_down && map->touchy2)
	{
		if (!map->touchy1)
		{
			ret.x = check_horiz_start(0, map);
			ret.x += ret.x <= 0 ? map->w * 3 / 4 : 0;
			ret.y = 0;
		}
		else if (!map->touchx2)
		{
			ret.y = check_vert_start(map->w - 1, map);
			ret.y += ret.y <= 0 ? map->h / 4 : 0;
			ret.x = map->w - 1;
		}
	}
	else if (map->up_down == -1 && map->touchy1)
	{
		if (!map->touchy2)
		{
			ret.x = check_horiz_start(0 , map);
			ret.x += ret.x <= 0 ? map->w / 4 : 0;
			ret.y = map->h - 1;
		}
		else if (!map->touchx1)
		{
			ret.y = check_vert_start(0, map);
			ret.y += ret.y <= 0 ? map->h * 3 / 4 : 0;
			ret.x = 0;
		}
		return (ret);
	}
	else
	{
		ret.x = map->w / 2;
		ret.y = map->h / 2;
	}
	return (ret);
}
