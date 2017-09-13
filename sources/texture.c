/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	texturize(t_map *map, int x, int y)
{
	if (map->side == 1 && map->ray_diry < 0)
		map->pix[x + (y * map->s_line / 4)] =
			darken((map->flr_addr[(x + (map->xpm_move)) + (y
				* map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
	else if (map->side == 1)
		map->pix[x + (y * map->s_line / 4)] =
			darken((map->flr_addr[(x + 1800 + (map->xpm_move)) + (y
				* map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
	else if (map->ray_dirx < 0)
		map->pix[x + (y * map->s_line / 4)] =
			darken((map->flr_addr[(x + 2700 + (map->xpm_move)) + (y
				* map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
	else
		map->pix[x + (y * map->s_line / 4)] =
			darken((map->flr_addr[(x + 900 + (map->xpm_move)) + (y
				* map->flr_s / 4)]), (double)(map->draw_end - map->draw_start));
}

void	draw_line(int x, t_map *map)
{
	t_vars	v;
	int		p;
	int		t;

	v.i = -1;
	v.y = (map->draw_start - 1);
	p = (0 - map->draw_start);
	if (v.y < 0)
		v.y = 0;
	v.j = (map->draw_end);
	if (v.j > 600)
		v.j = 599;
	v.d = (map->draw_end - map->draw_start) / 2;
	t = map->draw_end - map->draw_start;
	while (++v.i < v.y)
		map->pix[x + (v.i * map->s_line / 4)] = 0xC00000A0;
	while (++v.y < v.j)
		texturize(map, x, v.y);
	while (++v.j < 599)
		map->pix[x + (v.j * map->s_line / 4)] = 0xC00000A0;
}
