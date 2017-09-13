/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define mapWidth 24
#define mapHeight 24

void	coord(t_map *map)
{
	char *str;
	double i;

	i = (double)map->xpm_scale;
	i = fabs(((i + 150) / 150) * 100);
	str = ft_itoa(i);

	mlx_string_put(map->mlx, map->win, 5, 0, 0x123456, "Platform Tilt");
	mlx_string_put(map->mlx, map->win, 5, 20, 0x123456, str);
}

void	game_over(t_map *map)
{
	map->go = mlx_xpm_file_to_image(map->mlx, "./xpm/skycast.xpm", &(map->go_x), &(map->go_y));
	mlx_put_image_to_window(map->mlx, map->win, map->go, 0, 0);
}

int 	loop_event(t_map *map)
{
	if (map->left)
	{
		map->xpm_move += 20;
		if(map->xpm_move == 3600)
			map->xpm_move = 0;
		map->old_dirx = map->dir_x;
		map->dir_x = map->dir_x * cos(0.044) - map->dir_y * sin(0.044);
		map->dir_y = map->old_dirx * sin(0.044) + map->dir_y * cos(0.044);
		map->old_planex = map->plane_x;
		map->plane_x = map->plane_x * cos(0.044) - map->plane_y * sin(0.044);
		map->plane_y = map->old_planex * sin(0.044) + map->plane_y * cos(0.044);
	}
	else if (map->right)
	{
		map->xpm_move -= 20;
		if(map->xpm_move == -1800)
			map->xpm_move = 1800;
		map->old_dirx = map->dir_x;
		map->dir_x = map->dir_x * cos(-0.044) - map->dir_y * sin(-0.044);
		map->dir_y = map->old_dirx * sin(-0.044) + map->dir_y * cos(-0.044);
		map->old_planex = map->plane_x;
		map->plane_x = map->plane_x * cos(-0.044) - map->plane_y * sin(-0.044);
		map->plane_y = map->old_planex * sin(-0.044) + map->plane_y * cos(-0.044);
	}
	else if (map->down)
	{
		if(map->ray_dirx > 0)
		{
			if(map->xpm_scale > -300)
				map->xpm_scale -= 0.5;
		}
		else
		{
			if(map->xpm_scale < 0)
				map->xpm_scale += 0.5;
		}
		if(map->xpm_scale == 0 || map->xpm_scale == -300)
		{
			map->game = 0;
		}
		if ((map->med[(int)(map->pos_x - map->dir_x * 0.075)][(int)(map->pos_y)]) == 0)
			map->pos_x -= map->dir_x * 0.075;
		if ((map->med[(int)(map->pos_x)][(int)(map->pos_y - map->dir_y * 0.075)]) == 0)
			map->pos_y -= map->dir_y * 0.075;
	}
	else if (map->up)
	{
		if(map->ray_dirx > 0)
		{
			if(map->xpm_scale < 0)
				map->xpm_scale += 0.5;
		}
		else
		{
			if(map->xpm_scale > -300)
				map->xpm_scale -= 0.5;
		}
		if(map->xpm_scale == 0 || map->xpm_scale == -300)
		{
			map->game = 0;
		}
		if ((map->med[(int)(map->pos_x + map->dir_x * 0.075)][(int)(map->pos_y)]) == 0)
			map->pos_x += map->dir_x * 0.075;
		if ((map->med[(int)(map->pos_x)][(int)(map->pos_y + map->dir_y * 0.075)]) == 0)
			map->pos_y += map->dir_y * 0.075;
	}
	draw_reload(map);
	return (0);	
}

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
	return (0);
}

static int		expose_event(t_map *map)
{
	draw_reload(map);
	return (0);
}

void	initialize_med(t_map *map)
{
	ft_strcpy(map->med[0], "888888888884464464644464");
	ft_strcpy(map->med[1], "800000000084000000000004");
	ft_strcpy(map->med[2], "803300000884000000000006");
	ft_strcpy(map->med[3], "800300000000000000000006");
	ft_strcpy(map->med[4], "803300000884000000000004");
	ft_strcpy(map->med[5], "800000000084000006660646");
	ft_strcpy(map->med[6], "888000898884444446000006");
	ft_strcpy(map->med[7], "777000777080000084040606");
	ft_strcpy(map->med[8], "770000007808000000000006");
	ft_strcpy(map->med[9], "700000000000000000000004");
	ft_strcpy(map->med[10], "700000000000000006060606");
	ft_strcpy(map->med[11], "770000007808080806460666");
	ft_strcpy(map->med[12], "777000777884068403330333");
	ft_strcpy(map->med[13], "222000222464006063000003");
	ft_strcpy(map->med[14], "220000022400000043000003");
	ft_strcpy(map->med[15], "200000002400000043000003");
	ft_strcpy(map->med[16], "100000001444446063300033");
	ft_strcpy(map->med[17], "200000002221222660050505");
	ft_strcpy(map->med[18], "220000022200022050500055");
	ft_strcpy(map->med[19], "200000000000002505050505");
	ft_strcpy(map->med[20], "100000000000000000000005");
	ft_strcpy(map->med[21], "200000000000002505050505");
	ft_strcpy(map->med[22], "220000022200022050500055");
	ft_strcpy(map->med[23], "222212222221222555555555");
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
	map->xpm = mlx_xpm_file_to_image(map->mlx, "./xpm/star.xpm", &(map->xpm_x), &(map->xpm_y));
	map->xpm_addr = (int*)mlx_get_data_addr(map->xpm, &(map->xpm_b), &(map->xpm_s), &(map->xpm_e));

	map->flr = mlx_xpm_file_to_image(map->mlx, "./xpm/penis.xpm", &(map->flr_x), &(map->flr_y));
	map->flr_addr = (int*)mlx_get_data_addr(map->flr, &(map->flr_b), &(map->flr_s), &(map->flr_e));
	initialize_med(map);
	map->pix = (int*)mlx_get_data_addr(map->img,
		&(map->bits), &(map->s_line), &(map->endian));
}

void	draw_reload(t_map *map)
{
	map->img = mlx_new_image(map->mlx, 800, 600);
//	map->pic = mlx_xpm_file_to_image(map->mlx, "./sources/test.xpm", &(map->pic_x), &(map->pic_y));
	map->pix = (int*)mlx_get_data_addr(map->img, &(map->bits),
		&(map->s_line), &(map->endian));
	map->end = 0;
	map->wall_x = 0;
	start_draw(map);
	// map->xpm = mlx_xpm_file_to_image(map->mlx, "./xpm/panana.xpm", &(map->xpm_x), &(map->xpm_y));
	// mlx_put_image_to_window(map->mlx, map->win, map->xpm, map->xpm_move, 0);
	// if(map->xpm_move > 0)
	// 	mlx_put_image_to_window(map->mlx, map->win, map->flr, (map->xpm_move - 1920), 0);
	//ft_putstr("X: "); ft_putnbr(map->map_x); ft_putstr(" Y: "); ft_putnbr(map->map_y); ft_putstr("\n");
	if(map->map_x == 6 && map->map_y == 6)
	{
		map->game = 1;
		game_over(map);
	}
	if(map->game == 0)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->flr, map->xpm_move, map->xpm_scale); 
		if(map->xpm_move > 0) 
		 mlx_put_image_to_window(map->mlx, map->win, map->flr, (map->xpm_move - 3600), map->xpm_scale);
		mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
		if(map->game == 0)
		coord(map);
	}
	else
		game_over(map);
	// mlx_put_image_to_window(map->mlx, map->win, map->xpm, 0, 0);
	mlx_destroy_image(map->mlx, map->img);
}

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
}

void	draw_bar(int x, t_map *map)
{
	t_vars v;

	v.i = -1;
	v.y = (map->draw_start - 1);
	if (v.y < 0)
		v.y = 0;
	v.j = (map->draw_end);
	if (v.j > 600)
		v.j = 600;
	 while (++v.i < v.y)
	 		map->pix[x + (v.i * map->s_line / 4)] = 0xC00000A0;
	while (++v.y < (map->draw_end))
			map->pix[x + (v.y * map->s_line / 4)] = 0x123456;
	while (++v.j < 599)
			map->pix[x + (v.j * map->s_line / 4)] = 0xC00000A0;
}

int 	south(int height, int type, int p)
{
	static int i;
	static double x;

	if (p)
	{
		i += p;
		return (0);
	}
	if (type == 1)
	{
		x = (double)height / 1.5;
		return (1);
	}
	if (type == 2)
	{
		i = 0;
		return (0);
	}
	++i;
	if (fmod((double)i, x) < x / 2)
		return (0x2F4F4F);
	else
		return (0x708090);
}


int 	north(int height, int type, int p)
{
	static int i;
	static double x;

	if (p)
	{
		i += p;
		return (0);
	}
	if (type == 1)
	{
		x = (double)height / 1.5;
		return (1);
	}
	if (type == 2)
	{
		i = 0;
		return (0);
	}
	++i;
	if (fmod((double)i, x) < x / 2)
		return (0x191970);
	else
		return (0x4169E1);
}


int 	east(int height, int type, int p)
{
	static int i;
	static double x;

	if (p)
	{
		i += p;
		return (0);
	}
	if (type == 1)
	{
		x = (double)height / 1.5;
		return (1);
	}
	if (type == 2)
	{
		i = 0;
		return (0);
	}
	++i;
	if (fmod((double)i, x) < x / 2)
		return (0x4B0082);
	else
		return (0x8A2BE2);
}


int 	west(int height, int type, int p)
{
	static int i;
	static double x;

	if (p)
	{
		i += p;
		return (0);
	}
	if (type == 1)
	{
		x = (double)height / 1.5;
		return (1);
	}
	if (type == 2)
	{
		i = 0;
		return (0);
	}
	++i;
	if (fmod((double)i, x) < x / 2)
		return (0x8B0000);
	else
		return (0xB22222);
}

int 	darken(int img, double distance)
{
	double percent;
	int red;
	int blue;
	int green;

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

void	draw_line(int x, t_map *map)
{
	t_vars v;
	int p;
	v.i = -1;
	v.y = (map->draw_start - 1);
	p = (0 - map->draw_start);
	if (v.y < 0)
		v.y = 0;
	v.j = (map->draw_end);
	if (v.j > 600)
		v.j = 599;
	v.d = (map->draw_end - map->draw_start) / 2;

	int t;
	t = map->draw_end - map->draw_start;
	// south(t, 1, 0); north(t, 1, 0); east(t, 1, 0); west(t, 1, 0);
	// if (p > 0)
	// 		{
	// 			south(0,0, p); north(0,0, p); east(0,0, p); west(0,0, p); 
	// 			p = 0;
	// 		}
	 while (++v.i < v.y)
	 	map->pix[x + (v.i * map->s_line / 4)] = 0xC00000A0;
	 		//map->pix[x + (v.i * map->s_line / 4)] = map->xpm_addr[((x + map->xpm_move) % 1600) + (v.i * map->s_line / 4)];	
	while (++v.y < v.j)
	{

		if (map->side == 1 && map->ray_diry < 0)
			map->pix[x + (v.y * map->s_line / 4)] = darken((map->flr_addr[(x + (map->xpm_move)) + (v.y * map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
			// map->pix[x + (v.y * map->s_line / 4)] = west(0, 0, 0);
		else if (map->side == 1)
			map->pix[x + (v.y * map->s_line / 4)] = darken((map->flr_addr[(x + 1800 + (map->xpm_move)) + (v.y * map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
			// map->pix[x + (v.y * map->s_line / 4)] = east(0, 0, 0);
		else if (map->ray_dirx < 0)
		{
			map->pix[x + (v.y * map->s_line / 4)] = darken((map->flr_addr[(x + 2700 + (map->xpm_move)) + (v.y * map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
			// map->pix[x + (v.y * map->s_line / 4)] = south(0, 0, 0);
		}
		else
			map->pix[x + (v.y * map->s_line / 4)] = darken((map->flr_addr[(x + 900 + (map->xpm_move)) + (v.y * map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
			// map->pix[x + (v.y * map->s_line / 4)] = north(0, 0, 0);
	}
	// south(0, 2, 0); north(0, 2, 0); east(0, 2, 0); west(0, 2, 0);
	while (++v.j < 599)
	{
		if ((map->eggplant % 2) == 0)
		{
			if (map->side == 1 && map->ray_diry < 0)
				map->pix[x + (v.j * map->s_line / 4)] = darken((map->flr_addr[(x + (map->xpm_move)) + ((v.j + 150)  * map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
			else if (map->side == 1)
				map->pix[x + (v.j * map->s_line / 4)] = darken((map->flr_addr[(x + 1800 + (map->xpm_move)) + ((v.j + 150)  * map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
			else if (map->ray_dirx < 0)
			{
				map->pix[x + (v.j * map->s_line / 4)] = darken((map->flr_addr[(x + 2700 + (map->xpm_move)) + ((v.j + 150)  * map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
			}
			else
				map->pix[x + (v.j * map->s_line / 4)] = darken((map->flr_addr[(x + 900 + (map->xpm_move)) + ((v.j + 150) * map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
		}
		else
			map->pix[x + (v.j * map->s_line / 4)] = 0xC00000A0;	
	}
}

void	start_draw(t_map *map)
{
	t_vars v;

//	while (map->end != 1)
	//{
		v.x = -1;
		while (++v.x < 800)
		{
			map->camera_x = 2 * v.x / (double)(800) - 1;
			map->ray_posx = map->pos_x;
			map->ray_posy = map->pos_y;
			map->ray_dirx = map->dir_x + map->plane_x * map->camera_x;
			map->ray_diry = map->dir_y + map->plane_y * map->camera_x;
			map->map_x = (int)(map->ray_posx);
			map->map_y = (int)(map->ray_posy);
			map->delta_distx = sqrt(1 + (map->ray_diry * map->ray_diry) / (map->ray_dirx * map->ray_dirx));
			map->delta_disty = sqrt(1 + (map->ray_dirx * map->ray_dirx) / (map->ray_diry * map->ray_diry));
			map->hit = 0; 
			if (map->ray_dirx < 0.0)
			{
				map->step_x = -1;
				map->side_distx = (map->ray_posx - map->map_x) * map->delta_distx;
			}
			else
			{
				map->step_x = 1;
				map->side_distx = (map->map_x + 1.0 - map->ray_posx) * map->delta_distx;
			}
			if (map->ray_diry < 0.0)
			{
				map->step_y = -1;
				map->side_disty = (map->ray_posy - map->map_y) * map->delta_disty;
			}
			else
			{
				map->step_y = 1;
				map->side_disty = (map->map_y + 1.0 - map->ray_posy) * map->delta_disty;
			}
			while (map->hit == 0)
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
				if (map->med[map->map_x][map->map_y] > 0) 
					map->hit = 1;
				if (map->med[map->map_x][map->map_y] == 9) 
					map->hit = 2;
			} 
			if (map->side == 0)
				map->wall_dist = (map->map_x - map->ray_posx + (1 - map->step_x) / 2) / map->ray_dirx;
			else
				map->wall_dist = (map->map_y - map->ray_posy + (1 - map->step_y) / 2) / map->ray_diry;
			map->line_height = (int)(600 / map->wall_dist);
			map->draw_start = -(map->line_height) / 1.5 + 600 / 2;
			//if (map->draw_start < 0)
				//map->draw_start = 0;
				map->draw_end = map->line_height / 1.5 + 600 / 2;
			//if (map->draw_end >= 600)
				//map->draw_end = 600 - 1;
			if(map->hit == 2)
				draw_bar(v.x, map);
			else
				draw_line(v.x, map);
	//	map->end = 1;
	}
}


int			main()
{
	t_map *map;

	if ((map = ft_memalloc(sizeof(t_map))) == NULL)
	{
		ft_putstr("Instruction unclear, eggplant stuck in blender.");
		return (0);
	}
	init_map(map);
	initialize_draw(map);
	start_draw(map);
	mlx_expose_hook(map->win, expose_event, map);
	mlx_hook(map->win, 2, (1L << 0), hook_event, map);
	mlx_hook(map->win, 3, (1L << 0), release_event, map);
	mlx_loop_hook(map->mlx, loop_event, map);
	mlx_loop(map->mlx);
	return (0);
}
