/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:06:43 by calpha            #+#    #+#             */
/*   Updated: 2020/09/22 18:37:57 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** key == 53 ESC
** key == 123 left, key == 124 right, key == 125 up, key == 126 down
** key == 69 zoom+, key == 78 zoom-
*/

static int	deal_key(int key, t_data *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit (0);
	}
	if (key == 123)
		map->move_x -= 30;
	if (key == 124)
		map->move_x += 30;
	if (key == 125)
		map->move_y += 30;
	if (key == 126)
		map->move_y -= 30;
	if (key == 69)
		map->zoom += 2;
	if (key == 78)
		map->zoom -= 2;
	if (key == 0)
		rotate_left(map);
	if (key == 2)
		rotate_right(map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw_map(map);
	return (0);
}

static void	initialization(t_data *map)
{
	map->x1 = 0;
	map->y1 = 0;
	map->x2 = 0;
	map->y2 = 0;
	map->z1 = 0;
	map->z2 = 0;
	map->length = 0;
	map->width = 0;
	map->top = NULL;
	map->zoom = 20;
	map->move_x = 0;
	map->move_y = 0;
	map->color = 0;
	map->mlx_ptr = 0;
	map->win_ptr = NULL;
}

int			main(int ac, char *av[])
{
	t_data *map;

	if (ac == 2)
	{
		if (validation_file(av) == 0)
		{
			ft_putstr_fd("Error file\n", 2);
			return (0);
		}
		if (!(map = (t_data *)malloc(sizeof(t_data))))
			return (0);
		initialization(map);
		read_file(map, av);
	}
	else
	{
		ft_putstr_fd("Usage: ./fdf [file name]\n", 2);
		return (0);
	}
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, av[1]);
	draw_map(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);

	// int x;
	// int y;

	// y = 0;
	// while (y < map->width)
	// {
	// 	x = 0;
	// 	while (x < map->length)
	// 	{
	// 		printf("%3d", map->top[y][x]);
	// 		x++;
	// 	}
	// 	y++;
	// 	printf("\n");
	// }

	// clear_array(map);
	free(map);
	return (0);
}
