/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:05:55 by calpha            #+#    #+#             */
/*   Updated: 2020/09/15 16:25:31 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
// # include "mlx.h"
# include "libft/libft.h"

#define ABS(a) ((a < 0) ? -a : a)
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a > b) ? b : a

typedef struct	s_data
{
	int			length;
	int			width;
	int			**top;
	int			zoom;
	int			color;


	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

void			read_file(t_data *map, char *av[]);
// void			line(float x0, float y0, float x1, float y1, t_data *map);
// void			draw_map(t_data *map);

#endif
