/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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