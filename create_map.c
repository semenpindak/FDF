/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:45:49 by calpha            #+#    #+#             */
/*   Updated: 2020/09/12 00:28:00 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_array(t_data *map, int i, char **rcp)
{
	int j;

	j = 0;
	while (j < map->width)
	{
		map->matrix[i][j] = ft_atoi(rcp[j]);
		j++;
	}
}

static void	create_matrix(t_data *map, char *av[])
{
	int		fd;
	char	*line;
	char	**rcp;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	map->matrix = (int **)malloc(map->height * sizeof(int *));
	while (get_next_line(fd, &line) > 0)
	{
		rcp = ft_strsplit(line, ' ');
		map->matrix[i] = (int *)malloc(map->width * sizeof(int));
		fill_array(map, i, rcp);
		i++;
		free(line);
	}
	close(fd);
}

static void	count_hight(t_data *map, char *av[])
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
	map->height = i;
	close(fd);
}

static void	clear_array(int ac, char **ar)
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

static void	count_width(t_data *map, char *av[])
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
	map->width = i;
	clear_array(i, rcp);
	close(fd);
}

void		create_map(t_data *map, char *av[])
{
	int i;
	int j;

	count_width(map, av);
	count_hight(map, av);
	create_matrix(map, av);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%3d", map->matrix[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
