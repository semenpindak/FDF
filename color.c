/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:39:54 by calpha            #+#    #+#             */
/*   Updated: 2020/09/22 13:41:37 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color_minus(float z)
{
	int color;

	if (z >= -20)
		color = 0x008eff;
	if (z >= -18 && z < -20)
		color = 0x0290f4;
	if (z >= -16 && z < -18)
		color = 0x0492e8;
	if (z >= -14 && z < -16)
		color = 0x0693e0;
	if (z >= -12 && z < -14)
		color = 0x0c98c6;
	if (z >= -10 && z < -12)
		color = 0x119cac;
	if (z >= -8 && z < -10)
		color = 0x16a096;
	if (z >= -6 && z < -8)
		color = 0x1ca57c;
	if (z >= -4 && z < -6)
		color = 0x21aa62;
	if (z >= -2 && z < -4)
		color = 0x27b044;
	if (z >= 0 && z < -2)
		color = 0x2db625;
	return (color);
}

int			color_plus(float z)
{
	int color;

	color = color_minus(z);
	if (z >= 0 && z < 2)
		color = 0x33ad23;
	if (z >= 2 && z < 4)
		color = 0x3ba021;
	if (z >= 4 && z < 6)
		color = 0x4d831b;
	if (z >= 6 && z < 8)
		color = 0x537a19;
	if (z >= 8 && z < 10)
		color = 0x597117;
	if (z >= 10 && z < 12)
		color = 0x606615;
	if (z >= 12 && z < 14)
		color = 0x6e5010;
	if (z >= 14 && z < 16)
		color = 0x81330a;
	if (z >= 16 && z < 18)
		color = 0x941604;
	if (z >= 18)
		color = 0x941604;
	return (color);
}

int			color(t_data *map)
{
	return ((map->z1 > map->z2) ? color_plus(map->z1) : color_plus(map->z2));
}
