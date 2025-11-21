/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 transform.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/10/25 11:58:49 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/10/25 20:15:54 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

// TODO revisar juntos
t_ray	transform(t_ray r, t_matrix m)
{
	t_ray	rret;

	rret.o = matrix_tuple_mult(m, r.o);
	rret.d = matrix_tuple_mult(m, r.d);
	return (rret);
}

void	set_transform(t_object *object, t_matrix m)
{
	object->trans = m;
	return ;
}

/**
 * Moves the camera to a certain point (from) pointing to a point to() and
 * specifying the up vector (0, 1, 0) or (0, -1, 0) for the inverse camera
 */
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix	vm;
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	trans;
	t_matrix	ori;

	forward = tuple_normalize(tuple_sub(to, from));
	left = tuple_cross(forward, tuple_normalize(up));
	true_up = tuple_cross(left, forward);
	ori.size = 4;
	ori.value[0][0] = left.x;
	ori.value[0][1] = left.y;
	ori.value[0][2] = left.z;
	ori.value[0][3] = 0;
	ori.value[1][0] = true_up.x;
	ori.value[1][1] = true_up.y;
	ori.value[1][2] = true_up.z;
	ori.value[1][3] = 0;
	ori.value[2][0] = -forward.x;
	ori.value[2][1] = -forward.y;
	ori.value[2][2] = -forward.z;
	ori.value[2][3] = 0;
	ori.value[3][0] = 0;
	ori.value[3][1] = 0;
	ori.value[3][2] = 0;
	ori.value[3][3] = 1;
	trans = matrix_translation(-from.x, -from.y, -from.z);
	vm = matrix_matrix_mult(ori, trans);
	return (vm);
}

/**
 * Like view_transform but with normal vector.
 * Moves the camera to a certain point (from) with a direction (forward -
 * normalized alredy) and specifying the up vector (0, 1, 0) or (0, -1, 0) for
 * the inverse camera
 */
t_matrix	view_transform2(t_tuple from, t_tuple forward, t_tuple up)
{
	t_matrix	vm;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	trans;
	t_matrix	ori;

	forward = tuple_normalize(forward);
	left = tuple_cross(forward, tuple_normalize(up));
	true_up = tuple_cross(left, forward);
	ori.size = 4;
	ori.value[0][0] = left.x;
	ori.value[0][1] = left.y;
	ori.value[0][2] = left.z;
	ori.value[0][3] = 0;
	ori.value[1][0] = true_up.x;
	ori.value[1][1] = true_up.y;
	ori.value[1][2] = true_up.z;
	ori.value[1][3] = 0;
	ori.value[2][0] = -forward.x;
	ori.value[2][1] = -forward.y;
	ori.value[2][2] = -forward.z;
	ori.value[2][3] = 0;
	ori.value[3][0] = 0;
	ori.value[3][1] = 0;
	ori.value[3][2] = 0;
	ori.value[3][3] = 1;
	trans = matrix_translation(-from.x, -from.y, -from.z);
	vm = matrix_matrix_mult(ori, trans);
	return (vm);
}

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
