/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:24:57 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/07 11:31:28 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

float	tuple_magnitude(t_tuple v)
{
	float	mag;

	if (tuple_is_point(v))
		return (0);
	if (!tuple_is_vector(v))
		return (NAN);
	mag = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return (mag);
}

t_tuple	tuple_normalize(t_tuple v)
{
	t_tuple	t;
	float	mag;

	mag = tuple_magnitude(v);
	if (mag == 0 || isnan(mag))
		t = tuple_set(NAN, NAN, NAN, NAN);
	else
	{
		t.x = v.x / mag;
		t.y = v.y / mag;
		t.z = v.z / mag;
	}
	return (t);
}

float	tuple_dot(t_tuple a, t_tuple b)
{
	float	dp;

	if (!tuple_is_vector(a) || !tuple_is_vector(b))
		dp = NAN;
	else
		dp = a.x * b.x + a.y * b.y + a.z * b.z;
	return (dp);
}

t_tuple	tuple_cross(t_tuple a, t_tuple b)
{
	t_tuple	t;

	if (!tuple_is_vector(a) || !tuple_is_vector(b))
		t = tuple_set(NAN, NAN, NAN, NAN);
	else
	{
		t.x = a.y * b.z - a.z * b.y;
		t.y = a.z * b.x - a.x * b.z;
		t.z = a.x * b.y - a.y * b.x;
		t.w = 0;
	}
	return (t);
}
