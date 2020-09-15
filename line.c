// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   line.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/09/13 17:05:38 by calpha            #+#    #+#             */
// /*   Updated: 2020/09/15 16:22:05 by calpha           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fdf.h"

// void	isometric(float *x, float *y, int z)
// {
// 	*x = (*x - *y) * cos(0.8);
// 	*y = (*x + *y) * sin(0.8) - z;
// }

// void	line(float x0, float y0, float x1, float y1, t_data *map)
// {
// 	float x_step;
// 	float y_step;
// 	int max;
// 	int z0;
// 	int z1;

// 	z0 = map->top[(int)y0][(int)x0];
// 	z1 = map->top[(int)y1][(int)x1];

// 	x0 *= map->zoom;
// 	x1 *= map->zoom;
// 	y0 *= map->zoom;
// 	y1 *= map->zoom;

// 	map->color = (z0 || z1) ? 0xe80c0c : 0xffffff;

// 	isometric(&x0, &y0, z0);
// 	isometric(&x1, &y1, z1);

// 	x0 += 300;
// 	x1 += 300;
// 	y0 += 300;
// 	y1 += 300;

// 	// printf("line\n");
// 	x_step = x1 - x0;
// 	y_step = y1 - y0;

// 	max = MAX(ABS(x_step), ABS(y_step));
// 	// printf("max = %d", max);
// 	x_step /= max;
// 	y_step /= max;
// 	// printf("line2\n");
// 	while ((int)(x0 - x1) || (int)(y0 - y1))
// 	{
// 		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x0, y0, map->color);
// 		x0 += x_step;
// 		y0 += y_step;
// 	}
// }
