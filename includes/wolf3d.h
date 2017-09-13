/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"


# define M1 "888888888884464464644464"
# define M2 "800000000084000000000004"
# define M3 "803300000884000000000006"
# define M4 "800300000000000000000006"
# define M5 "803300000884000000000004"
# define M6 "800000000084000006660646"
# define M7 "888000898884444446000006"
# define M8 "777000777080000084040606"
# define M9 "770000007808000000000006"
# define M10 "700000000000000000000004"
# define M11 "700000000000000006060606"
# define M12 "770000007808080806460666"
# define M13 "777000777884068403330333"
# define M14 "222000222464006063000003"
# define M15 "220000022400000043000003"
# define M16 "200000002400000043000003"
# define M17 "100000001444446063300033"
# define M18 "200000002221222660050505"
# define M19 "220000022200022050500055"
# define M20 "200000000000002505050505"
# define M21 "100000000000000000000005"
# define M22 "200000000000002505050505"
# define M23 "220000022200022050500055"
# define M24 "222212222221222555555555"


typedef struct s_vars
{
	int			x;
	int			y;
	int			d;
	int			i;
	int			j;
	int			k;
	int m;
}				t_vars;

typedef struct s_map
{
	void 		*xpm;
	char		med[24][25];
	void	*go;
	int 	go_x;
	int 	go_y;
	void		*flr;
	int 		flr_move;
	int 		*flr_addr;
	int 	game;
	int flr_s;
	int flr_e;
	int flr_b;
	int flr_x;
	int flr_y;
	double 		xpm_scale;
	int 		xpm_move;
	int 		*xpm_addr;
	int 		xpm_s;
	int 		xpm_e;
	int 		xpm_b;
	int 		xpm_x;
	int 		xpm_y;
	char		*map;
	void		*mlx;
	void		*win;
	void		*img;
	int			*pix;
	int			bits;
	int			s_line;
	int			endian;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	int			hit;
	int			side;
	int			end;
	int			map_x;
	int			map_y;
	double		side_distx;
	double		side_disty;
	double		delta_distx;
	double		delta_disty;
	double		wall_dist;
	int			step_x;
	int			step_y;
	double		camera_x;
	double		ray_posx;
	double		ray_posy;
	double		ray_dirx;
	double		ray_diry;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		old_dirx;
	double		old_planex;
	int			up;
	int			down;
	int			left;
	int			right;
	int			wall_x;
	int			wall_y;
	double		floor_xwall;
	double		floor_ywall;
	double		floor_dist;
	double		dist_player;
	double		current_dist;
	double		weight;
	double		floor_x;
	double		floor_y;
	double		current_floorx;
	double		current_floory;
	int			eggplant;
}				t_map;

void	draw_reload(t_map *map);
void	start_draw(t_map *map);
void	init_map(t_map *map);
void	initialize_med(t_map *map);
#endif
