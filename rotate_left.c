/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:13:11 by calpha            #+#    #+#             */
/*   Updated: 2020/09/22 18:38:20 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void overwriting_array(int **rotate, t_data *map)
{
	int i;

	i = 0;
	map->top = (int **)malloc(map->length * sizeof(int *));
	while (i < map->length)
	{
		map->top[i] = (int *)malloc(map->width * sizeof(int));
		ft_memcpy(map->top[i], rotate[i], (4 * map->width));
		i++;
	}
}

static void	clear_array(int ac, int **ar)
{
	int i;

	i = 0;
	while (i < ac)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

static void	fill_coordinates_i(int **rotate, int i, t_data *map)
{
	int j;
	int k;

	j = 0;
	k = map->width - 1;
	while (j < map->width)
	{
		rotate[i][j] = map->top[k][i];
		j++;
		k--;
	}
}

void	rotate_left(t_data *map)
{
	int **rotate;
	int i;
	int tmp;

	i = 0;
	rotate = (int **)malloc(map->length * sizeof(int *));
	while (i < map->length)
	{
		rotate[i] = (int *)malloc(map->width * sizeof(int));
		fill_coordinates_i(rotate, i, map);
		i++;
	}
	clear_array(map->width, map->top);
	overwriting_array(rotate, map);
	clear_array(map->length, rotate);
	tmp = map->length;
	map->length = map->width;
	map->width = tmp;
}
