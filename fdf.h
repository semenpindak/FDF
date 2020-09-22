/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:05:55 by calpha            #+#    #+#             */
/*   Updated: 2020/09/22 18:37:21 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "Libft/includes/libft.h"

typedef struct	s_data
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	int			z1;
	int			z2;
	int			length;
	int			width;
	int			**top;
	int			zoom;
	int			move_x;
	int			move_y;
	int			color;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

typedef struct	s_bresenham
{
	float		deltax;
	float		deltay;
	float		signx;
	float		signy;
	float		error;
	float		error2;
}				t_bresenham;

int				validation_file(char *av[]);
void			read_file(t_data *map, char *av[]);
void			line(t_data *map);
void			draw_map(t_data *map);
void			zoom(t_data *map);
void			move(t_data *map);
int				color(t_data *map);
void			rotate_left(t_data *map);
void			rotate_right(t_data *map);
#endif
