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

static int		expose_event(t_map *map)
{
	draw_reload(map);
	return (0);
}

int				main(void)
{
	t_map		*map;

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
