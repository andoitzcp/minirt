/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sp_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 21:59:30 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/30 22:10:59 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	swap(float *a, float *b)
{
	float	c;

	c = *a;
	*a = *b;
	*b = c;
	return ;
}

void	bzero_array(float *array, size_t sz)
{
	size_t	i;

	i = 0;
	while (i < sz)
		array[i++] = 0;
	return ;
}

void	add_intersect(float *array, float t)
{
	if (array[0] > 1)
		return ;
	array[0] += 1;
	array[(int)array[0]] = t;
	return ;
}

float	check_cap(t_ray *ray, float t)
{
	float	x;
	float	z;

	x = ray->o.x + t * ray->d.x;
	z = ray->o.z + t * ray->d.z;
	return ((powf(x, 2) + powf(z, 2) <= 1));
}

void	check_cap_2(t_ray *ray, float *t, float *array)
{
	t[0] = (-1 - ray->o.y) / ray->d.y;
	t[1] = (+1 - ray->o.y) / ray->d.y;
	if (check_cap(ray, t[0]))
		add_intersect(array, t[0]);
	if (check_cap(ray, t[1]))
		add_intersect(array, t[1]);
}
