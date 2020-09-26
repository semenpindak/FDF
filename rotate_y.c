/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:45:44 by calpha            #+#    #+#             */
/*   Updated: 2020/09/26 22:45:56 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Rotate coordinate by y axis
*/

void	rotate_y(float *x, float *z, float rotate_y)
{
	float previous_x;

	previous_x = *x;
	*x = previous_x * cos(rotate_y) + *z * sin(rotate_y);
	*z = -previous_x * sin(rotate_y) + *z * cos(rotate_y);
}
