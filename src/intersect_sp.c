/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 intersect_sp.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/21 20:43:37 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/21 20:43:37 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

void	calc_ray_sp_intersects(float *array, t_ray *ray)
{
	t_tuple	sp_to_ray;
	float	dotp[3];
	float	dis;

	sp_to_ray = tuple_sub(ray->o, tuple_point(0, 0, 0));
	dotp[0] = tuple_dot(ray->d, ray->d);
	dotp[1] = 2 * tuple_dot(ray->d, sp_to_ray);
	dotp[2] = tuple_dot(sp_to_ray, sp_to_ray) - 1;
	dis = powf(dotp[1], 2) - 4 * dotp[0] * dotp[2];
	bzero_array(array, 3);
	if (dis < 0)
		return ;
	array[0] = 2;
	array[1] = (-dotp[1] - sqrtf(dis)) / (2 * dotp[0]);
	array[2] = (-dotp[1] + sqrtf(dis)) / (2 * dotp[0]);
	if (array[1] > array[2])
		swap(&(array[1]), &(array[2]));
	return ;
}

// TODO implement plane intersects
void	calc_ray_pl_intersects(float *array, t_ray *ray)
{
	bzero_array(array, 3);
	if (fabs(ray->d.y) < EPS)
		return ;
	array[0] = 1;
	array[1] = -ray->o.y / ray->d.y;
	return ;
}

// TODO implement plane intersects
void	calc_ray_cy_intersects(float *array, t_ray *ray)
{
	float	abc[3];
	float	disc;
	float	t[2];
	float	y[2];

	bzero_array(array, 3);
	abc[0] = powf(ray->d.x, 2) + powf(ray->d.z, 2);
	if (float_eq(abc[0], 0))
		return ;
	abc[1] = 2 * ray->o.x * ray->d.x + 2 * ray->o.z * ray->d.z;
	abc[2] = powf(ray->o.x, 2) + powf(ray->o.z, 2) - 1;
	disc = powf(abc[1], 2) - 4 * abc[0] * abc[2];
	if (disc < 0)
		return ;
	t[0] = (-abc[1] - sqrtf(disc)) / (2 * abc[0]);
	t[1] = (-abc[1] + sqrtf(disc)) / (2 * abc[0]);
	y[0] = ray->o.y + t[0] * ray->d.y;
	y[1] = ray->o.y + t[1] * ray->d.y;
	if (-1 < y[0] && y[0] < 1)
		add_intersect(array, t[0]);
	if (-1 < y[1] && y[1] < 1)
		add_intersect(array, t[1]);
	check_cap_2(ray, t, array);
}

void	calc_ray_caps_intersects(float *array, t_ray *ray)
{
	(void)array;
	(void)ray;
	(void)check_cap(ray, 0);
}
