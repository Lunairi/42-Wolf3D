/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_left(t_map *map)
{
	if (map->left)
	{
		map->xpm_move += 20;
		if (map->xpm_move == 3600)
			map->xpm_move = 0;
		map->old_dirx = map->dir_x;
		map->dir_x = map->dir_x * cos(0.044)
			- map->dir_y * sin(0.044);
		map->dir_y = map->old_dirx * sin(0.044)
			+ map->dir_y * cos(0.044);
		map->old_planex = map->plane_x;
		map->plane_x = map->plane_x * cos(0.044)
			- map->plane_y * sin(0.044);
		map->plane_y = map->old_planex * sin(0.044)
			+ map->plane_y * cos(0.044);
	}
}

void	move_right(t_map *map)
{
	if (map->right)
	{
		map->xpm_move -= 20;
		if (map->xpm_move == -1800)
			map->xpm_move = 1800;
		map->old_dirx = map->dir_x;
		map->dir_x = map->dir_x * cos(-0.044)
			- map->dir_y * sin(-0.044);
		map->dir_y = map->old_dirx * sin(-0.044)
			+ map->dir_y * cos(-0.044);
		map->old_planex = map->plane_x;
		map->plane_x = map->plane_x * cos(-0.044)
			- map->plane_y * sin(-0.044);
		map->plane_y = map->old_planex * sin(-0.044)
			+ map->plane_y * cos(-0.044);
	}
}

void	move_down(t_map *map)
{
	if (map->down)
	{
		if (map->ray_dirx > 0)
		{
			if (map->xpm_scale > -300)
				map->xpm_scale -= 0.5;
		}
		else
		{
			if (map->xpm_scale < 0)
				map->xpm_scale += 0.5;
		}
		if (map->xpm_scale == 0 || map->xpm_scale == -300)
			map->game = 1;
		if ((map->med[(int)(map->pos_x - map->dir_x
				* 0.075)][(int)(map->pos_y)]) == '0')
			map->pos_x -= map->dir_x * 0.075;
		if ((map->med[(int)(map->pos_x)][(int)(map->pos_y
				- map->dir_y * 0.075)]) == '0')
			map->pos_y -= map->dir_y * 0.075;
	}
}

void	move_up(t_map *map)
{
	if (map->up)
	{
		if (map->ray_dirx > 0)
		{
			if (map->xpm_scale < 0)
				map->xpm_scale += 0.5;
		}
		else
		{
			if (map->xpm_scale > -300)
				map->xpm_scale -= 0.5;
		}
		if (map->xpm_scale == 0 || map->xpm_scale == -300)
			map->game = 1;
		if ((map->med[(int)(map->pos_x + map->dir_x
				* 0.075)][(int)(map->pos_y)]) == '0')
			map->pos_x += map->dir_x * 0.075;
		if ((map->med[(int)(map->pos_x)][(int)(map->pos_y
				+ map->dir_y * 0.075)]) == '0')
			map->pos_y += map->dir_y * 0.075;
	}
}

int		loop_event(t_map *map)
{
	move_left(map);
	move_right(map);
	move_up(map);
	move_down(map);
	draw_reload(map);
	return (0);
}
