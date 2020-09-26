/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 19:22:07 by calpha            #+#    #+#             */
/*   Updated: 2020/09/25 19:27:50 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_length_min_max(char **av, int n)
{
	int		i;
	int		j;
	char	*check_int;

	i = 0;
	j = 0;
	if (av[n][0] == '-')
	{
		i++;
		check_int = "2147483648";
	}
	else
		check_int = "2147483647";
	while (av[n][i] != '\0')
	{
		if (av[n][i] > check_int[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

static int	check_min_max(int n, char **rcp)
{
	if (((ft_strlen(rcp[n]) > 10) && rcp[n][0] != '-') ||
		((ft_strlen(rcp[n]) > 11) && rcp[n][0] == '-'))
		return (0);
	if (((ft_strlen(rcp[n]) == 10) && rcp[n][0] != '-') ||
		((ft_strlen(rcp[n]) == 11) && rcp[n][0] == '-'))
	{
		if (check_length_min_max(rcp, n) == 0)
			return (0);
	}
	return (1);
}

int			check_min_max_number(char *av[])
{
	int		fd;
	char	*line;
	int		n;
	char	**rcp;

	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(rcp = ft_strsplit(line, ' ')))
			return (0);
		n = 0;
		while (rcp[n] != NULL)
		{
			if (check_min_max(n, rcp) == 0)
				return (0);
			n++;
		}
		free_array(n, (void **)rcp);
		free(line);
	}
	close(fd);
	return (1);
}
