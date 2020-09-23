/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:43:29 by calpha            #+#    #+#             */
/*   Updated: 2020/09/23 22:44:28 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int	count_int(char *line)
{
	char	**ar;
	int		i;

	i = 0;
	if (!(ar = ft_strsplit(line, ' ')))
		return (0);
	while (ar[i] != NULL)
		i++;
	clear_array(i, ar);
	return (i);
}

int			validation_file(char *av[])
{
	int		fd;
	char	*line;
	int		check_one;
	int		check;
	int		r;

	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (get_next_line(fd, &line) == -1)
		return (0);
	check_one = count_int(line);
	free(line);
	while ((r = get_next_line(fd, &line)) > 0)
	{
		check = count_int(line);
		if (check != check_one)
			return (0);
		free(line);
	}
	if (r == -1)
		return (0);
	close(fd);
	return (1);
}
