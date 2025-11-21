/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 plane.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/21 21:55:30 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/21 21:55:30 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

// TODO Implement funtion to take raw data plane and convert it into matrix
// and material and set plane data
// t_object *new_plane_from_raw_data(t_raw_plane *rpl, t_amblight *ambl)
// {
//	   t_matrix trans;
//	   t_material mat;
//
//	   trans = matrix_translation(rpl->p.x, rpl->p.y, rpl->p.z);
//	   // put here rotations
//	   //trans = matrix_matrix_mult(trans, )
//	   mat = new_material_from_raw_data(&rpl->col, ambl);
//	   return (new_object(ELID_PL, &trans, &mat));
// }

t_object	*new_plane_from_raw_data(t_raw_plane *rpl, t_amblight *ambl)
{
	t_matrix	t;
	t_matrix	r;
	t_matrix	trans;
	t_material	mat;

	t = matrix_translation(rpl->p.x, rpl->p.y, rpl->p.z);
	r = matrix_rotation(rpl->v);
	trans = matrix_matrix_mult(t, r);
	mat = new_material_from_raw_data(&rpl->col, ambl);
	return (new_object(ELID_PL, &trans, &mat));
}
