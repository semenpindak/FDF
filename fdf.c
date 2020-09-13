/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:06:43 by calpha            #+#    #+#             */
/*   Updated: 2020/09/12 00:28:51 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main (int ac, char *av[])
{
	t_data *map;

	map = NULL;
	if (ac == 2)
	map = (t_data *)malloc(sizeof(t_data));
	create_map(map, av);
	printf("%d\n", map->width);
	printf("%d\n", map->height);
	// printf("%zu\n", ft_strlen("aaaaaaaaaa"));
	// printf("%f\n", sin(45));
	// printf("%f\n", ceil(4.00000000678));
	free(map);
	return (0);
}
