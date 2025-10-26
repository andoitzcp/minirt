/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:18:36 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/25 20:09:06 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO Implement funtion to take raw data plane and convert it into matrix
// and material and set plane data
void set_sphere_from_raw_data(t_sphere *sp, t_raw_sphere *rsp)
{
    (void)sp;
    (void)rsp;
    return ;
}

// TODO si eliminar p y dia ??
t_sphere new_sphere(void)
{
    t_sphere sp;

    sp.p = tuple_point(0, 0, 0);
    sp.mat = def_material();
    sp.trans = matrix_identity(4);
    return (sp);
}

t_sphere	*set_sphere_transform(t_sphere *s, t_matrix trans)
{
	t_matrix	m;

	m = matrix_matrix_mult(trans, s->trans);
	s->p = tuple_point(m.value[0][3], m.value[1][3], m.value[2][3]);
	s->trans = m;
	return (s);
}

t_matrix	get_sphere_transform(t_sphere s)
{
	t_matrix	transform;
	
	transform.value[0][3] = s.p.x;
	transform.value[1][3] = s.p.y;
	transform.value[2][3] = s.p.z;
	return (transform);
}

t_tuple	sphere_normal_at(t_sphere sphere, t_tuple point)
{
	t_tuple		obj_point;
	t_tuple 	obj_normal;
	t_tuple 	normal;
	t_matrix	aux_matrix;

	obj_point = transform_back(sphere.trans, point);
	obj_normal = tuple_sub(obj_point, tuple_point(0,0,0));
	aux_matrix = matrix_inverse(sphere.trans);
	aux_matrix = matrix_transpose(aux_matrix);
	normal = matrix_tuple_mult(aux_matrix, obj_normal);
	normal.w = 0;
	normal = tuple_normalize(normal);
	return (normal);
}

