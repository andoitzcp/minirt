/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:23:54 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/07 11:30:23 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

t_tuple	tuple_add(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t.x = a.x + b.x;
	t.y = a.y + b.y;
	t.z = a.z + b.z;
	t.w = a.w + b.w;
	return (t);
}

t_tuple	tuple_sub(t_tuple a, t_tuple b)
{
	t_tuple	t;

	t.x = a.x - b.x;
	t.y = a.y - b.y;
	t.z = a.z - b.z;
	t.w = a.w - b.w;
	return (t);
}

t_tuple	tuple_scale_up(t_tuple v, float n)
{
	t_tuple	t;

	t.x = v.x * n;
	t.y = v.y * n;
	t.z = v.z * n;
	t.w = v.w * n;
	return (t);
}

t_tuple	tuple_scale_down(t_tuple v, float n)
{
	t_tuple	t;

	if (n == 0)
		t = tuple_set(NAN, NAN, NAN, NAN);
	else
	{
		t.x = v.x / n;
		t.y = v.y / n;
		t.z = v.z / n;
		t.w = v.w / n;
	}
	return (t);
}

t_tuple	tuple_negate(t_tuple v)
{
	t_tuple	t;

	t.x = -v.x;
	t.y = -v.y;
	t.z = -v.z;
	t.w = -v.w;
	return (t);
}
