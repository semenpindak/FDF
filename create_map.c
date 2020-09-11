/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:45:49 by calpha            #+#    #+#             */
/*   Updated: 2020/09/11 20:25:35 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	create_matrix(t_data *map, char *av[])
{
	int fd;
	char *line;
	int i;
	int j;

	fd = 3;
	i = 0;
	j = 0;
	open(av[1], O_RDONLY);
	map->matrix = (int **)malloc(map->height * sizeof(t_data *));
	while (get_next_line(fd, &line) > 0)
	{
		map->matrix[i] = (int *)line;
		i++;
		free(line);
	}
}

static void	count_hight(t_data *map, char *av[])
{
	int fd;
	char *line;
	int i;

	line = NULL;
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

static void	count_width(t_data *map, char *av[])
{
	int fd;
	char *line;
	char **rcp;
	int i;

	line = NULL;
	rcp = NULL;
	i = 0;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	rcp = ft_strsplit(line, ' ');
	free(line);
	while (rcp[i] != NULL)
		i++;
	map->width = i;
	free(rcp);
	close(fd);
}

void		create_map(t_data *map, char *av[])
{
	count_width(map, av);
	count_hight(map, av);
	create_matrix(map, av);

}
