/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 21:50:27 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/30 21:56:32 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO move to liblinmath
t_matrix	matrix_from_tuples(t_tuple x, t_tuple y, t_tuple z)
{
	t_matrix	m;

	m = matrix_zero();
	m.value[0][0] = x.x;
	m.value[1][0] = x.y;
	m.value[2][0] = x.z;
	m.value[0][1] = y.x;
	m.value[1][1] = y.y;
	m.value[2][1] = y.z;
	m.value[0][2] = z.x;
	m.value[1][2] = z.y;
	m.value[2][2] = z.z;
	m.value[3][3] = 1;
	return (m);
}

// TODO get matrix rotation from a source and destiny vector
// TODO move to liblinmath
t_matrix	matrix_rotation(t_tuple dest)
{
	t_matrix	r;
	t_tuple		tmp;
	t_tuple		xp;
	t_tuple		yp;
	t_tuple		zp;

	dest = tuple_normalize(dest);
	yp = dest;
	if (fabs(dest.y) < 0.9)
		tmp = tuple_vector(0, 1, 0);
	else
		tmp = tuple_vector(1, 0, 0);
	xp = tuple_cross(tmp, yp);
	xp = tuple_normalize(xp);
	zp = tuple_cross(yp, xp);
	zp = tuple_normalize(zp);
	r = matrix_from_tuples(xp, yp, zp);
	return (r);
}
