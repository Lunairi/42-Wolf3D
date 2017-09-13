/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_map(t_map *map)
{
	map->pos_x = 22.0;
	map->pos_y = 11.5;
	map->dir_x = -1;
	map->dir_y = 0;
	map->plane_x = 0;
	map->plane_y = 0.66;
	map->time = 0;
	map->old_time = 0;
	map->eggplant = 1;
	map->xpm_move = 0;
	map->xpm_scale = -150;
	map->end = 0;
	map->game = 0;
	map->level = 1;
}

void	initialize_draw(t_map *map)
{
	if (!(map->mlx = mlx_init()))
	{
		ft_putstr("Instructions unclear, eggplant generated instead of map.");
		return ;
	}
	map->win = mlx_new_window(map->mlx, 800, 600, "Kill me please");
	map->img = mlx_new_image(map->mlx, 800, 600);
	map->xpm = mlx_xpm_file_to_image(map->mlx, "./xpm/star.xpm",
		&(map->xpm_x), &(map->xpm_y));
	map->xpm_addr = (int*)mlx_get_data_addr(map->xpm,
		&(map->xpm_b), &(map->xpm_s), &(map->xpm_e));
	map->flr = mlx_xpm_file_to_image(map->mlx, "./xpm/bg.xpm",
		&(map->flr_x), &(map->flr_y));
	map->flr_addr = (int*)mlx_get_data_addr(map->flr,
		&(map->flr_b), &(map->flr_s), &(map->flr_e));
	initialize_maze(map);
	map->pix = (int*)mlx_get_data_addr(map->img,
		&(map->bits), &(map->s_line), &(map->endian));
}
