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

void			display_free(void)
{
	ft_putstr("\nYou can roam freely here and explore all you want.\n\n");
	ft_putstr("[Arrow Key] - Move around in the maze\n");
	ft_putstr("[Keyboard R] - Reset back to start\n");
	ft_putstr("[Keyboard I] - Main menu\n");
	ft_putstr("[Keyboard N] - Change map\n");
}

void			display_menu(void)
{
	ft_putstr("\nOh no, during your trip to the castle in the sky\n");
	ft_putstr("you ended up getting stuck in a trap!\n\n");
	ft_putstr("You need to navigate your way out while attempting\n");
	ft_putstr("to avoid tilting the platform you're trapped on.\n\n");
	ft_putstr("Good luck!\n");
	ft_putstr("[Spacebar] - Interact with doors\n");
	ft_putstr("[Enter] - To move onto next level\n");
	ft_putstr("[Escape] - Exit because you are bad\n");
	ft_putstr("[Arrow Key] - Move around in the maze\n");
	ft_putstr("[Keyboard R] - Reset current level\n");
	ft_putstr("[Keyboard I] - Main menu\n");
}

static int		expose_event(t_map *map)
{
	if (map->intro == 0)
		return (0);
	else
		draw_reload(map);
	return (0);
}

static int		close_window(t_map *map)
{
	system("killall afplay");
	if (map)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
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
	system("afplay ./xpm/aimee.mp3 &");
	initialize_draw(map);
	start_draw(map);
	mlx_expose_hook(map->win, expose_event, map);
	mlx_hook(map->win, 2, (1L << 0), hook_event, map);
	mlx_hook(map->win, 3, (1L << 0), release_event, map);
	mlx_hook(map->win, 17, (1L << 0), close_window, map);
	mlx_loop_hook(map->mlx, loop_event, map);
	mlx_loop(map->mlx);
	return (0);
}
