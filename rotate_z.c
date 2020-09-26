/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:46:37 by calpha            #+#    #+#             */
/*   Updated: 2020/09/26 22:46:52 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Rotate coordinate by z axis
*/

void	rotate_z(float *x, float *y, float rotate_z)
{
	float previous_x;
	float previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(rotate_z) - previous_y * sin(rotate_z);
	*y = previous_x * sin(rotate_z) + previous_y * cos(rotate_z);
}
