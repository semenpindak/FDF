/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:35:23 by calpha            #+#    #+#             */
/*   Updated: 2020/09/26 22:46:49 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_x(int x, int y, t_data *map)
{
	float x1i;
	float y1i;
	float x2i;
	float y2i;

	x1i = x;
	y1i = y;
	x2i = x + 1;
	y2i = y;
	map->z1 = map->top[y][x];
	map->z2 = map->top[y][(x + 1)];
	rotate_x(&y1i, &map->z1, map->rotate_x);
	rotate_y(&x1i, &map->z1, map->rotate_y);
	rotate_z(&x1i, &y1i, map->rotate_z);
	map->x1 = x1i;
	map->y1 = y1i;
	rotate_x(&y2i, &map->z2, map->rotate_x);
	rotate_y(&x2i, &map->z2, map->rotate_y);
	rotate_z(&x2i, &y2i, map->rotate_z);
	map->x2 = x2i;
	map->y2 = y2i;
	line(map);
}

static void	fill_y(int x, int y, t_data *map)
{
	float x1i;
	float y1i;
	float x2i;
	float y2i;

	x1i = x;
	y1i = y;
	x2i = x;
	y2i = y + 1;
	map->z1 = map->top[y][x];
	map->z2 = map->top[(y + 1)][x];
	rotate_x(&y1i, &map->z1, map->rotate_x);
	rotate_y(&x1i, &map->z1, map->rotate_y);
	rotate_z(&x1i, &y1i, map->rotate_z);
	map->x1 = x1i;
	map->y1 = y1i;
	rotate_x(&y2i, &map->z2, map->rotate_x);
	rotate_y(&x2i, &map->z2, map->rotate_y);
	rotate_z(&x2i, &y2i, map->rotate_z);
	map->x2 = x2i;
	map->y2 = y2i;
	line(map);
}

static void	move_point(t_data *map)
{
	map->x1 += map->move_x;
	map->y1 += map->move_y;
}

static void	point(t_data *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	map->z1 = map->top[y][x];
	map->color = color_plus(map->z1);
	map->x1 = (map->x1 - map->y1) * cos(0.523599);
	map->y1 = (map->x1 + map->y1) * sin(0.523599);
	move_point(map);
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, map->color);
}

void		draw_map(t_data *map)
{
	int x;
	int y;

	if (map->width == 1 && map->length == 1)
		point(map);
	else
	{
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
}
