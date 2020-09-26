/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:45:49 by calpha            #+#    #+#             */
/*   Updated: 2020/09/25 19:05:18 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_coordinates_i(t_data *map, int i, char **rcp)
{
	int j;

	j = 0;
	while (j < map->length)
	{
		map->top[i][j] = ft_atoi(rcp[j]);
		j++;
	}
}

static void	create_coordinates(t_data *map, char *av[])
{
	int		fd;
	char	*line;
	char	**rcp;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	map->top = (int **)malloc(map->width * sizeof(int *));
	while (get_next_line(fd, &line) > 0)
	{
		rcp = ft_strsplit(line, ' ');
		map->top[i] = (int *)malloc(map->length * sizeof(int));
		fill_coordinates_i(map, i, rcp);
		free_array(map->length, (void **)rcp);
		free(line);
		i++;
	}
	close(fd);
}

static void	count_width(t_data *map, char *av[])
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	map->width = i;
	close(fd);
}

static void	count_length(t_data *map, char *av[])
{
	int		fd;
	char	*line;
	char	**rcp;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	rcp = ft_strsplit(line, ' ');
	free(line);
	while (rcp[i] != NULL)
		i++;
	map->length = i;
	free_array(i, (void **)rcp);
	close(fd);
}

void		read_file(t_data *map, char *av[])
{
	count_length(map, av);
	count_width(map, av);
	create_coordinates(map, av);
}
