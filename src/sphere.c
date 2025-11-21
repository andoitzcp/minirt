/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 sphere.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/10/25 12:18:36 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/10/25 20:09:06 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

// TODO Implement funtion to take raw data plane and convert it into matrix
// and material and set plane data
t_object	*new_sphere_from_raw_data(t_raw_sphere *rsp, t_amblight *ambl)
{
	t_matrix	trans;
	t_material	mat;

	trans = matrix_translation(rsp->p.x, rsp->p.y, rsp->p.z);
	trans = matrix_matrix_mult(trans,
			matrix_scalation(rsp->dia, rsp->dia, rsp->dia));
	mat = new_material_from_raw_data(&rsp->col, ambl);
	return (new_object(ELID_SP, &trans, &mat));
}
