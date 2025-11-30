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
// t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
// {
// 	t_matrix	vm;
// 	t_tuple		forward;
// 	t_tuple		left;
// 	t_tuple		true_up;
// 	t_matrix	trans;
// 	t_matrix	ori;
//
// 	forward = tuple_normalize(tuple_sub(to, from));
// 	left = tuple_cross(forward, tuple_normalize(up));
// 	true_up = tuple_cross(left, forward);
// 	ori.size = 4;
// 	ori.value[0][0] = left.x;
// 	ori.value[0][1] = left.y;
// 	ori.value[0][2] = left.z;
// 	ori.value[0][3] = 0;
// 	ori.value[1][0] = true_up.x;
// 	ori.value[1][1] = true_up.y;
// 	ori.value[1][2] = true_up.z;
// 	ori.value[1][3] = 0;
// 	ori.value[2][0] = -forward.x;
// 	ori.value[2][1] = -forward.y;
// 	ori.value[2][2] = -forward.z;
// 	ori.value[2][3] = 0;
// 	ori.value[3][0] = 0;
// 	ori.value[3][1] = 0;
// 	ori.value[3][2] = 0;
// 	ori.value[3][3] = 1;
// 	trans = matrix_translation(-from.x, -from.y, -from.z);
// 	vm = matrix_matrix_mult(ori, trans);
// 	return (vm);
// }

t_matrix	ori_matrix(t_tuple left, t_tuple forward, t_tuple true_up)
{
	t_matrix	ori;

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
	return (ori);
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
	ori = ori_matrix(left, forward, true_up);
	trans = matrix_translation(-from.x, -from.y, -from.z);
	vm = matrix_matrix_mult(ori, trans);
	return (vm);
}
