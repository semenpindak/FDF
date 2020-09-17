/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:05:38 by calpha            #+#    #+#             */
/*   Updated: 2020/09/17 20:52:04 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isomitric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	line(int x0, int y0, int x1, int y1, t_data *map)
{
	int deltax;
	int deltay;
	int error;
	int deltaerr;
	int diry;
	int z0;
	int z1;

	z0 = map->top[y0][x0];
	z1 = map->top[y1][x1];

	// printf("z0 = %d, z1 = %d\n", z0, z1);
	isomitric(&x0, &y0, z0);
	isomitric(&x1, &y1, z1);


	// x0 *= 20;
	// x1 *= 20;
	// y0 *= 20;
	// y1 *= 20;


	deltax = x1 - x0;
	deltay = y1 - y0;
	error = 0;
	deltaerr = (MIN(deltax, deltay) + 1) / (MAX(deltax, deltay) + 1);
	// printf("deltax = %f, deltay = %f\n", deltax, deltay);
	// printf("deltaerr = %f\n", deltaerr);
	diry = MIN(deltax, deltay);
	diry = (diry > 0) ? 1 : -1;


	printf("x0 = %d, y0 = %d, z0 = %d\n", x0, y0, z0);
	printf("x1 = %d, y1 = %d, z1 = %d\n", x1, y1, z1);
	while ((x0 < x1) || y0 < y1)
	{
		// printf("x0 = %1.f, y0 = %1.f,\n", x0, y0);
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x0, y0, 0x00FFFFFF);
		error = error + deltaerr;
		if (deltay < deltax)
		{
			if (error >= 1)
			{
				y0 = y0 + diry;
				error = error - 1.0;
			}
			x0++;
		}
		else
		{
			if (error >= 1)
			{
				x0 = x0 + diry;
				error = error - 1.0;
			}
			y0++;
		}
		// printf("error = %.1f, diry = %d,\n", error, diry);
	}
}
