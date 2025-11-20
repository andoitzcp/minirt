/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 camera.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/20 20:04:45 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/20 20:04:45 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Creates a new camera struct
 */
t_camera	new_camera(int hsize, int vsize, float fov)
{
	t_camera	camera;

	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.fov = fov;
	camera.trans = matrix_identity(4);
	camera_comps(&camera);
	return (camera);
}

/**
 * Auxiliary function used for tests
 */
t_camera	def_camera(void)
{
	t_camera	cam;

	cam = new_camera(DEF_RESOLUTION_X, DEF_RESOLUTION_Y, M_PI);
	return (cam);
}

/**
 * Computes key values to renderization of the image.
 */
void	camera_comps(t_camera *camera)
{
	float	half_view;
	float	aspect;

	half_view = tan((float)camera->fov / 2);
	aspect = (float)camera->hsize / camera->vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pix_sz = (camera->half_width * 2) / camera->hsize;
}

/**
 * Converts parsed camera parameters into usable camera variables
 */
t_camera	get_camera_from_raw_data(t_raw_data *rd)
{
	t_camera	c;
	int			res[2];
	float		fov;

	res[0] = rd->res.x_sz;
	res[1] = rd->res.y_sz;
	fov = degrees_to_radians(rd->c.fov);
	c = new_camera(res[0], res[1], fov);
	c.trans = view_transform2(rd->c.p, rd->c.v, tuple_vector(0, 1, 0));
	return (c);
}
