/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:35:23 by calpha            #+#    #+#             */
/*   Updated: 2020/09/22 16:02:33 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_x(int x, int y, t_data *map)
{
	map->x1 = x;
	map->y1 = y;
	map->x2 = x + 1;
	map->y2 = y;
	map->z1 = map->top[y][x];
	map->z2 = map->top[(y)][(x + 1)];
	line(map);
}

void	fill_y(int x, int y, t_data *map)
{
	map->x1 = x;
	map->y1 = y;
	map->x2 = x;
	map->y2 = y + 1;
	map->z1 = map->top[y][x];
	map->z2 = map->top[(y + 1)][x];
	line(map);
}

void	draw_map(t_data *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->width)
	{
		x = 0;
		while (x < map->length)
		{
			if (x < map->length - 1)
				fill_x(x, y, map);
			if (y < map->width - 1)
				fill_y(x, y, map);
			x++;
		}
		y++;
	}
}
