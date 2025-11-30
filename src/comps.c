/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:14:28 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/30 22:16:21 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	local_normal_at(t_object *obj, t_tuple local_point)
{
	float	dist;

	if (obj->type == ELID_SP)
		return (tuple_sub(local_point, tuple_point(0, 0, 0)));
	if (obj->type == ELID_PL)
		return (tuple_vector(0, 1, 0));
	if (obj->type == ELID_CY)
	{
		dist = powf(local_point.x, 2) + powf(local_point.z, 2);
		if (dist < 1 && local_point.y >= 1 - EPS)
			return (tuple_vector(0, 1, 0));
		else if (dist < 1 && local_point.y <= -1 + EPS)
			return (tuple_vector(0, -1, 0));
		else
			return (tuple_vector(local_point.x, 0, local_point.z));
	}
	else
		return (tuple_vector(0, 0, 0));
}

t_tuple	normal_at(t_object *obj, t_tuple point)
{
	t_matrix	inverse;
	t_tuple		local_point;
	t_tuple		local_normal;
	t_tuple		world_normal;

	inverse = obj->inverse;
	local_point = matrix_tuple_mult(inverse, point);
	local_normal = local_normal_at(obj, local_point);
	world_normal = matrix_tuple_mult(matrix_transpose(inverse),
			local_normal);
	world_normal.w = 0;
	return (tuple_normalize(world_normal));
}

t_comps	prep_comps(t_intersects *intersection, t_ray *ray)
{
	t_comps	comps;

	comps.t = intersection->i;
	comps.obj = intersection->obj;
	comps.point = position(*ray, comps.t);
	comps.eyev = tuple_negate(ray->d);
	comps.normv = normal_at(comps.obj, comps.point);
	comps.is_inside = 0;
	if (tuple_dot(comps.normv, comps.eyev) < 0)
	{
		comps.is_inside = 1;
		comps.normv = tuple_negate(comps.normv);
	}
	return (comps);
}
