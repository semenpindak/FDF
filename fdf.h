/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:05:55 by calpha            #+#    #+#             */
/*   Updated: 2020/09/11 23:34:14 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
// # include <mlx.h>
# include "libft/libft.h"

typedef struct	s_data
{
	int			width;
	int			height;
	int			**matrix;
}				t_data;

void			create_map(t_data *map, char *av[]);


#endif
