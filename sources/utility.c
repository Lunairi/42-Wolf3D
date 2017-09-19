/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	coord(t_map *map)
{
	double	i;

	i = (double)map->xpm_scale;
	i = fabs(((i + 150) / 150) * 100);
	mlx_string_put(map->mlx, map->win, 5, 0, 0x123456, "Danger Tilt Level");
	mlx_string_put(map->mlx, map->win, 5, 20, 0x123456, "[");
	if (i >= 10)
		mlx_string_put(map->mlx, map->win, 12, 20, 0x104080, "=");
	if (i >= 20)
		mlx_string_put(map->mlx, map->win, 21, 20, 0x0099CC, "=");
	if (i >= 30)
		mlx_string_put(map->mlx, map->win, 30, 20, 0xBDF6E9, "=");
	if (i >= 40)
		mlx_string_put(map->mlx, map->win, 39, 20, 0x78C29E, "=");
	if (i >= 50)
		mlx_string_put(map->mlx, map->win, 48, 20, 0xB38909, "=");
	if (i >= 60)
		mlx_string_put(map->mlx, map->win, 57, 20, 0xDFCA4E, "=");
	if (i >= 70)
		mlx_string_put(map->mlx, map->win, 66, 20, 0xFF805C, "=");
	if (i >= 80)
		mlx_string_put(map->mlx, map->win, 75, 20, 0xFF3B3F, "=");
	if (i >= 90)
		mlx_string_put(map->mlx, map->win, 84, 20, 0xEA2C0B, "=");
	mlx_string_put(map->mlx, map->win, 94, 20, 0x123456, "]");
}

void	game_over(t_map *map)
{
	if (map->free == 1)
		return ;
	if (map->game == 1)
	{
		map->go = mlx_xpm_file_to_image(map->mlx, "./xpm/skycast.xpm",
			&(map->go_x), &(map->go_y));
		mlx_put_image_to_window(map->mlx, map->win, map->go, 0, 0);
	}
	else if (map->game == 2)
	{
		map->go = mlx_xpm_file_to_image(map->mlx, "./xpm/level.xpm",
			&(map->go_x), &(map->go_y));
		mlx_put_image_to_window(map->mlx, map->win, map->go, 0, 0);
	}
	else
	{
		map->go = mlx_xpm_file_to_image(map->mlx, "./xpm/castle.xpm",
			&(map->go_x), &(map->go_y));
		mlx_put_image_to_window(map->mlx, map->win, map->go, 0, 0);
	}
}

void	next_level(t_map *map)
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
	initialize_maze(map);
	draw_reload(map);
}

void	check_pos(t_map *map)
{
	if ((map->map_x == 15 && map->map_y == 7 && map->level == 1)
		|| (map->map_x == 15 && map->map_y == 8 && map->level == 1)
		|| (map->map_x == 15 && map->map_y == 6 && map->level == 1))
	{
		map->game = 2;
		map->level = 2;
		game_over(map);
	}
	if ((map->map_x == 6 && map->map_y == 7 && map->level == 2)
		|| (map->map_x == 6 && map->map_y == 6 && map->level == 2))
	{
		map->game = 2;
		map->level = 3;
		game_over(map);
	}
	if ((map->map_x == 4 && map->map_y == 22 && map->level == 3)
		|| (map->map_x == 4 && map->map_y == 21 && map->level == 3))
	{
		map->game = 3;
		map->level = 3;
		game_over(map);
	}
}

int		darken(int img, double distance)
{
	double	percent;
	int		red;
	int		blue;
	int		green;

	percent = 5000 / distance;
	if (percent > 100)
		percent = 100;
	percent = (100 - percent) / 100;
	blue = 255 - img % 256;
	img /= 256;
	green = 255 - img % 256;
	img /= 256;
	red = 255 - img % 256;
	red = (int)((double)red * percent);
	green = (int)((double)green * percent);
	blue = (int)((double)blue * percent);
	red = 255 - red;
	blue = 255 - blue;
	green = 255 - green;
	img = blue + green * 256 + red * 256 * 256;
	return (img);
}
