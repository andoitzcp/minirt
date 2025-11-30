/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 world.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/21 22:03:40 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/21 22:03:40 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

t_world	def_world(void)
{
	t_world		world;
	t_matrix	t;
	t_material	mat;
	t_object	*obj;

	world.res.x_sz = DEF_RESOLUTION_X;
	world.res.y_sz = DEF_RESOLUTION_Y;
	world.ali = def_amblight();
	world.l = def_light();
	world.c = def_camera();
	t = matrix_scalation(0.5, 0.5, 0.5);
	mat = def_material();
	mat.color = color_set(0.8, 1.0, 0.6);
	mat.diffuse = 0.7;
	mat.specular = 0.2;
	world.objs = NULL;
	obj = new_object(ELID_SP, NULL, &mat);
	object_append(&world.objs, obj);
	obj = new_object(ELID_SP, &t, NULL);
	object_append(&world.objs, obj);
	return (world);
}

t_world	new_world(t_resolution *res, t_amblight *ambl, t_light *l,
		t_camera *cam)
{
	t_world	world;

	world.res = *res;
	world.ali = *ambl;
	world.l = *l;
	world.c = *cam;
	world.objs = NULL;
	return (world);
}

void	intersect_world(t_world *world, t_ray *ray)
{
	t_object	*obj;

	obj = world->objs;
	while (obj != NULL)
	{
		get_ray_el_intersects(ray, obj);
		obj = obj->next;
	}
}
