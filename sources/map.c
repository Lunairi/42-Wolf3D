/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	erase_map(t_map *map)
{
	int i;

	i = 0;
	while (i < 24)
		ft_bzero(map->med[i++], 25);
}

void	initialize_easy(t_map *map)
{
	erase_map(map);
	ft_strcpy(map->med[0], "888888888888888888888888");
	ft_strcpy(map->med[1], "800000000000000000880008");
	ft_strcpy(map->med[2], "800080008888000000880008");
	ft_strcpy(map->med[3], "800080000088000888880008");
	ft_strcpy(map->med[4], "800080000088000088000008");
	ft_strcpy(map->med[5], "800080008888000000000008");
	ft_strcpy(map->med[6], "800080000088000000000008");
	ft_strcpy(map->med[7], "800080008888000008000008");
	ft_strcpy(map->med[8], "800080000000000008888008");
	ft_strcpy(map->med[9], "800000000000000008888008");
	ft_strcpy(map->med[10], "800000008888880008000008");
	ft_strcpy(map->med[11], "888800008888880008000008");
	ft_strcpy(map->med[12], "800000000000080008888888");
	ft_strcpy(map->med[13], "800000000000080000000008");
	ft_strcpy(map->med[14], "888888888000080000000008");
	ft_strcpy(map->med[15], "800008888800080000000008");
	ft_strcpy(map->med[16], "800008900800080000000008");
	ft_strcpy(map->med[17], "800008800800080000080008");
	ft_strcpy(map->med[18], "800008000000080000080008");
	ft_strcpy(map->med[19], "800008888888880000080008");
	ft_strcpy(map->med[20], "800000000000000000080008");
	ft_strcpy(map->med[21], "800000000000000000080008");
	ft_strcpy(map->med[22], "800000000000000000080008");
	ft_strcpy(map->med[23], "888888888888888888888888");
}

void	initialize_med(t_map *map)
{
	erase_map(map);
	ft_strcpy(map->med[0], "888888888884464464644464");
	ft_strcpy(map->med[1], "800000000084000000000004");
	ft_strcpy(map->med[2], "803300000084000000000006");
	ft_strcpy(map->med[3], "808000000000000000000006");
	ft_strcpy(map->med[4], "803008000084000000000004");
	ft_strcpy(map->med[5], "800008000004000006660646");
	ft_strcpy(map->med[6], "888008898884444446000006");
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

void	initialize_hard(t_map *map)
{
	erase_map(map);
	ft_strcpy(map->med[0], "888888888888888888888888");
	ft_strcpy(map->med[1], "800800008000880000000008");
	ft_strcpy(map->med[2], "800000008000088008008008");
	ft_strcpy(map->med[3], "800888888000008008008009");
	ft_strcpy(map->med[4], "800800000800000008888888");
	ft_strcpy(map->med[5], "800880000800000000000008");
	ft_strcpy(map->med[6], "800880000888888000000008");
	ft_strcpy(map->med[7], "800880000000000000080008");
	ft_strcpy(map->med[8], "800000000000000000080008");
	ft_strcpy(map->med[9], "888888888800008888888888");
	ft_strcpy(map->med[10], "800800800800008008008008");
	ft_strcpy(map->med[11], "800000000800000000000008");
	ft_strcpy(map->med[12], "800000000080000888880008");
	ft_strcpy(map->med[13], "800000000080000000800008");
	ft_strcpy(map->med[14], "800080000080000088800008");
	ft_strcpy(map->med[15], "800080008888800000800888");
	ft_strcpy(map->med[16], "800080000080000000800888");
	ft_strcpy(map->med[17], "800080000080008888800008");
	ft_strcpy(map->med[18], "800000000000000000000008");
	ft_strcpy(map->med[19], "888000888888000000000008");
	ft_strcpy(map->med[20], "800000000088000888888008");
	ft_strcpy(map->med[21], "800000000080000008000008");
	ft_strcpy(map->med[22], "800000000080000008000008");
	ft_strcpy(map->med[23], "888888888888888888888888");
}

void	initialize_maze(t_map *map)
{
	if (map->level == 1)
		initialize_easy(map);
	else if (map->level == 2)
		initialize_med(map);
	else if (map->level == 3)
		initialize_hard(map);
}
