/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:06:43 by calpha            #+#    #+#             */
/*   Updated: 2020/09/15 20:00:19 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int deal_key(int key, t_data *map)
// {
// 	if (key == 53)
// 		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
// 	return (0);
// }

static void	clear_array(t_data *map)
{
	int i;

	i = 0;
	while (i < map->width)
	{
		free(map->top[i]);
		i++;
	}
	free(map->top[i]);
}

// void	terminate(char *s)
// {
// 	if (errno == 0)
// 		ft_putendl_fd(s, 2);
// 	else
// 		perror(s);
// 	exit(1);
// }

int main (int ac, char *av[])
{
	t_data *map;

	map = NULL;
	// printf("%s %d", av[1], ac);
	if (ac == 2)
	{
		map = (t_data *)malloc(sizeof(t_data));
		read_file(map, av);
	}
	// map->zoom = 20;
	// map->mlx_ptr = mlx_init();
	// map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, av[1]);
	// draw_map(map);
	// mlx_key_hook(map->win_ptr, deal_key, map);
	// mlx_loop(map->mlx_ptr);

	clear_array(map);
	free(map);
	return (0);
}
