/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_pos(t_map *map, int x)
{
	map->camera_x = 2 * x / (double)(800) - 1;
	map->ray_posx = map->pos_x;
	map->ray_posy = map->pos_y;
	map->ray_dirx = map->dir_x + map->plane_x * map->camera_x;
	map->ray_diry = map->dir_y + map->plane_y * map->camera_x;
	map->map_x = (int)(map->ray_posx);
	map->map_y = (int)(map->ray_posy);
	map->delta_distx = sqrt(1 + (map->ray_diry * map->ray_diry)
		/ (map->ray_dirx * map->ray_dirx));
	map->delta_disty = sqrt(1 + (map->ray_dirx * map->ray_dirx)
		/ (map->ray_diry * map->ray_diry));
	map->hit = 0;
}

void	init_ray(t_map *map)
{
	if (map->ray_dirx < 0.0)
	{
		map->step_x = -1;
		map->side_distx = (map->ray_posx - map->map_x) * map->delta_distx;
	}
	else
	{
		map->step_x = 1;
		map->side_distx = (map->map_x + 1.0 - map->ray_posx)
			* map->delta_distx;
	}
	if (map->ray_diry < 0.0)
	{
		map->step_y = -1;
		map->side_disty = (map->ray_posy - map->map_y) * map->delta_disty;
	}
	else
	{
		map->step_y = 1;
		map->side_disty = (map->map_y + 1.0 - map->ray_posy)
			* map->delta_disty;
	}
}

void	calc_dist(t_map *map)
{
	if (map->side_distx < map->side_disty)
	{
		map->side_distx += map->delta_distx;
		map->map_x += map->step_x;
		map->side = 0;
	}
	else
	{
		map->side_disty += map->delta_disty;
		map->map_y += map->step_y;
		map->side = 1;
	}
	if (map->med[map->map_x][map->map_y] > '0')
		map->hit = 1;
	if (map->med[map->map_x][map->map_y] == '9')
		map->hit = 2;
}

void	start_draw(t_map *map)
{
	t_vars v;

	v.x = -1;
	while (++v.x < 800)
	{
		init_pos(map, v.x);
		init_ray(map);
		while (map->hit == 0)
			calc_dist(map);
		if (map->side == 0)
			map->wall_dist = (map->map_x - map->ray_posx
				+ (1 - map->step_x) / 2) / map->ray_dirx;
		else
			map->wall_dist = (map->map_y - map->ray_posy
				+ (1 - map->step_y) / 2) / map->ray_diry;
		map->line_height = (int)(600 / map->wall_dist);
		map->draw_start = -(map->line_height) / 1.5 + 600 / 2;
		map->draw_end = map->line_height / 1.5 + 600 / 2;
		if (map->free == 1)
			draw_free(v.x, map);
		else if (map->hit == 2)
			draw_bar(v.x, map);
		else
			draw_line(v.x, map);
	}
}
