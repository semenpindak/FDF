/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:43:29 by calpha            #+#    #+#             */
/*   Updated: 2020/09/25 19:23:33 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_int(char *line)
{
	char	**ar;
	int		i;

	i = 0;
	if (!(ar = ft_strsplit(line, ' ')))
		return (0);
	while (ar[i] != NULL)
		i++;
	free_array(i, (void **)ar);
	return (i);
}

int			check_proportion(char *av[])
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

static int	strnull(char *line, const char *needle)
{
	int i;

	i = 0;
	while (line[i] != '\0')
		i++;
	i--;
	if (line[i] == needle[0] || line[i] == needle[0])
	{
		i++;
		if (line[i] == needle[1])
			return (0);
	}
	return (1);
}

static int	check_arg_number(char *av[])
{
	int		fd;
	char	*line;
	int		i;

	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if ((line[i] < '-' || line[i] > '-')
			&& (line[i] < '0' || line[i] > '9')
			&& (line[i] < ' ' || line[i] > ' '))
				return (0);
			if (ft_strstr(line, "- ") != NULL || strnull(line, "-\0") == 0)
				return (0);
			i++;
		}
		free(line);
	}
	close(fd);
	return (1);
}

int			validation_file(char *av[])
{
	if (check_proportion(av) == 0)
		return (0);
	if (check_arg_number(av) == 0)
		return (0);
	if (check_min_max_number(av) == 0)
		return (0);
	return (1);
}
