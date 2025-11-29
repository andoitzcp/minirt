/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 material.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/10/25 11:38:48 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/10/25 20:14:18 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

t_material	def_material(void)
{
	t_material	mat;
	t_color		col;

	col = color_set(1, 1, 1);
	mat = new_material(&col, 0.1);
	return (mat);
}

t_material	new_material_from_raw_data(t_color *col, t_amblight *ambl)
{
	t_material	mat;

	mat.color = color_scale_up(color_blend(*col, ambl->col), ambl->ratio);
	mat.ambient = ambl->ratio;
	mat.diffuse = DEF_DIFFUSE;
	mat.specular = DEF_SPECULAR;
	mat.shininess = DEF_SHININESS;
	return (mat);
}

t_material	new_material(t_color *col, float ratio)
{
	t_material	mat;

	mat.color = *col;
	mat.ambient = ratio;
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 200;
	return (mat);
}

void	set_material(t_object *object, t_material material)
{
	object->mat = material;
	return ;
}
