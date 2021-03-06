/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_free(int x, t_map *map)
{
	t_vars v;

	v.i = -1;
	v.y = (map->draw_start - 1);
	if (v.y < 0)
		v.y = 0;
	v.j = (map->draw_end);
	if (v.j > 600)
		v.j = 599;
	while (++v.i < v.y)
		map->pix[x + (v.i * map->s_line / 4)] = 0xAAAAAA;
	while (++v.y < v.j)
	{
		if (map->side == 1 && map->ray_diry < 0)
			map->pix[x + (v.y * map->s_line / 4)] = 0x222222;
		else if (map->side == 1)
			map->pix[x + (v.y * map->s_line / 4)] = 0x444444;
		else if (map->ray_dirx < 0)
			map->pix[x + (v.y * map->s_line / 4)] = 0x666666;
		else
			map->pix[x + (v.y * map->s_line / 4)] = 0x888888;
	}
	while (++v.j < 599)
		map->pix[x + (v.j * map->s_line / 4)] = 0xEEEEEE;
}

void		draw_bar(int x, t_map *map)
{
	t_vars v;

	v.i = -1;
	v.y = (map->draw_start - 1);
	if (v.y < 0)
		v.y = 0;
	v.j = (map->draw_end);
	if (v.j > 600)
		v.j = 599;
	while (++v.i < v.y)
		map->pix[x + (v.i * map->s_line / 4)] = 0xC00000A0;
	while (++v.y < v.j)
		map->pix[x + (v.y * map->s_line / 4)] = map->xpm_addr[x
		+ (v.y * map->xpm_s / 4)];
	while (++v.j < 599)
		map->pix[x + (v.j * map->s_line / 4)] = 0xC00000A0;
}

void		intro_image(t_map *map)
{
	map->go = mlx_xpm_file_to_image(map->mlx, "./xpm/intro.xpm",
		&(map->go_x), &(map->go_y));
	mlx_put_image_to_window(map->mlx, map->win, map->go, 0, 0);
}

void		draw_reload(t_map *map)
{
	map->img = mlx_new_image(map->mlx, 800, 600);
	map->pix = (int*)mlx_get_data_addr(map->img, &(map->bits),
		&(map->s_line), &(map->endian));
	map->end = 0;
	map->wall_x = 0;
	start_draw(map);
	if (map->game == 0 && map->intro == 1)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->flr,
			map->xpm_move, map->xpm_scale);
		if (map->xpm_move > 0)
			mlx_put_image_to_window(map->mlx, map->win, map->flr,
				(map->xpm_move - 3600), map->xpm_scale);
		mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
		if (map->game == 0 && map->free != 1)
			coord(map);
	}
	else if (map->intro == 0)
		intro_image(map);
	else
		game_over(map);
	mlx_destroy_image(map->mlx, map->img);
}
