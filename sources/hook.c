/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	free_next(t_map *map)
{
	map->level += 1;
	if (map->level > 3)
		map->level = 1;
	init_level(map);
	initialize_maze(map);
	draw_reload(map);
}

int		release_event(int key, t_map *map)
{
	if (key == 123)
		map->left = 0;
	else if (key == 124)
		map->right = 0;
	else if (key == 125)
		map->down = 0;
	else if (key == 126)
		map->up = 0;
	return (0);
}

void	reset_level(int key, t_map *map)
{
	if (key == 15 && map->intro == 1)
	{
		init_level(map);
		draw_reload(map);
	}
	else if (key == 0 && map->intro != 1)
	{
		map->intro = 1;
		display_menu();
		draw_reload(map);
	}
	else if (key == 11 && map->intro != 1)
	{
		map->intro = 1;
		map->free = 1;
		display_free();
		draw_reload(map);
	}
	else if (key == 34)
	{
		init_map(map);
		draw_reload(map);
	}
	else if (key == 45 && map->free == 1)
		free_next(map);
}

int		hook_event(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		system("killall afplay");
		exit(EXIT_SUCCESS);
	}
	else if (key == 123 && map->intro == 1)
		map->left = 1;
	else if (key == 124 && map->intro == 1)
		map->right = 1;
	else if (key == 125 && map->intro == 1)
		map->down = 1;
	else if (key == 126 && map->intro == 1)
		map->up = 1;
	else if (key == 36 && map->game == 2 && map->free == 0)
		next_level(map);
	else if (key == 49 && map->intro == 1 && map->free == 0)
		check_pos(map);
	reset_level(key, map);
	return (0);
}
