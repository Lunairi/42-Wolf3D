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

int		release_event(int key, t_map *map)
{
	if (key == 123)
	{
		map->left = 0;
	}
	else if (key == 124)
	{
		map->right = 0;
	}
	else if (key == 125)
	{
		map->down = 0;
	}
	else if (key == 126)
	{
		map->up = 0;
	}
	return (0);
}

int		hook_event(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(EXIT_SUCCESS);
	}
	else if (key == 14)
	{
		map->eggplant += 1;
		draw_reload(map);
	}
	else if (key == 123)
		map->left = 1;
	else if (key == 124)
		map->right = 1;
	else if (key == 125)
		map->down = 1;
	else if (key == 126)
		map->up = 1;
	else if (key == 36 && map->game == 2)
		next_level(map);
	else if (key == 49)
		check_pos(map);
	return (0);
}
