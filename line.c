/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:05:38 by calpha            #+#    #+#             */
/*   Updated: 2020/09/22 13:44:36 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric(t_data *map)
{
	map->x1 = (map->x1 - map->y1) * cos(0.9);
	map->y1 = (map->x1 + map->y1) * sin(0.9) - map->z1;
	map->x2 = (map->x2 - map->y2) * cos(0.9);
	map->y2 = (map->x2 + map->y2) * sin(0.9) - map->z2;
}

float ft_fabs(float a)
{
	return (a < 0 ? (-a) : a);
}

static void initialization(t_bresenham *alg, t_data *map)
{
	alg->deltax = ft_fabs(map->x2 - map->x1);
	alg->deltay = ft_fabs(map->y2 - map->y1);
	alg->signx = map->x1 < map->x2 ? 1 : -1;
	alg->signy = map->y1 < map->y2 ? 1 : -1;
	alg->error = alg->deltax - alg->deltay;
}

void	line(t_data *map)
{
	t_bresenham *alg;

	alg = (t_bresenham *)malloc(sizeof(t_bresenham));
	zoom(map);
	isometric(map);
	map->color = color(map);
	move(map);
	initialization(alg, map);
	mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x2, map->y2, map->color);
	while ((int)(map->x1 - map->x2) || (int)(map->y1 - map->y2))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, map->color);
		alg->error2 = alg->error * 2;
		if (alg->error2 > -(alg->deltay))
		{
			alg->error -= alg->deltay;
			map->x1 += alg->signx;
		}
		if (alg->error2 < alg->deltax)
		{
			alg->error += alg->deltax;
			map->y1 += alg->signy;
		}
	}
	free(alg);
}
