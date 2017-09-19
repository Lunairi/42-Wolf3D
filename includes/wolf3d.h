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

typedef struct	s_vars
{
	int			x;
	int			y;
	int			d;
	int			i;
	int			j;
	int			k;
	int			m;
}				t_vars;

typedef struct	s_map
{
	int			free;
	int			intro;
	int			map_type;
	int			level;
	void		*xpm;
	char		med[24][25];
	void		*go;
	int			go_x;
	int			go_y;
	void		*flr;
	int			flr_move;
	int			*flr_addr;
	int			game;
	int			flr_s;
	int			flr_e;
	int			flr_b;
	int			flr_x;
	int			flr_y;
	double		xpm_scale;
	int			xpm_move;
	int			*xpm_addr;
	int			xpm_s;
	int			xpm_e;
	int			xpm_b;
	int			xpm_x;
	int			xpm_y;
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

/*
** main.c
*/
void			display_free(void);
void			display_menu(void);

/*
** raycast.c
*/
void			start_draw(t_map *map);

/*
** texture.c
*/
void			draw_line(int x, t_map *map);

/*
** init.c
*/
void			initialize_draw(t_map *map);
void			init_map(t_map *map);
void			init_level(t_map *map);

/*
** hook.c
*/
int				release_event(int key, t_map *map);
int				hook_event(int key, t_map *map);

/*
** draw.c
*/
void			draw_reload(t_map *map);
void			draw_bar(int x, t_map *map);
void			draw_free(int x, t_map *map);

/*
** map.c
*/
void			initialize_maze(t_map *map);

/*
** utility.c
*/
int				darken(int img, double distance);
void			check_pos(t_map *map);
void			game_over(t_map *map);
void			next_level(t_map *map);
void			coord(t_map *map);

/*
** event.c
*/
int				loop_event(t_map *map);

#endif
