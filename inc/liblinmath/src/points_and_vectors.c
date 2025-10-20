/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_and_vectors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:23:01 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/07 11:27:39 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

t_tuple	tuple_point(float x, float y, float z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 1;
	return (t);
}

t_tuple	tuple_vector(float x, float y, float z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 0;
	return (t);
}

int	tuple_is_point(t_tuple t)
{
	return (t.w == 1);
}

int	tuple_is_vector(t_tuple t)
{
	return (t.w == 0);
}
