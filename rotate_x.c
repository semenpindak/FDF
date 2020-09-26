/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:44:27 by calpha            #+#    #+#             */
/*   Updated: 2020/09/26 22:44:39 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Rotate coordinate by x axis
*/

void	rotate_x(float *y, float *z, float rotate_x)
{
	float previous_y;

	previous_y = *y;
	*y = previous_y * cos(rotate_x) + *z * sin(rotate_x);
	*z = -previous_y * sin(rotate_x) + *z * cos(rotate_x);
}
