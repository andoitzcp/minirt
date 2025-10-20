/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:16:57 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/07 11:27:09 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

float	*tuple_to_array(t_tuple t, float ar[4])
{
	ar[0] = t.x;
	ar[1] = t.y;
	ar[2] = t.z;
	ar[3] = t.w;
	return (ar);
}

t_tuple	tuple_set(float x, float y, float z, float w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

int	tuple_eq(t_tuple a, t_tuple b)
{
	if (!float_eq(a.x, b.x))
		return (0);
	if (!float_eq(a.y, b.y))
		return (0);
	if (!float_eq(a.z, b.z))
		return (0);
	if (!float_eq(a.w, b.w))
		return (0);
	return (1);
}
