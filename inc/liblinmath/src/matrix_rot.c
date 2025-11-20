/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:51:30 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/25 17:01:23 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

float	degrees_to_radians(float deg)
{
	float	rad;

	rad = deg * M_PI / 180;
	return (rad);
}

float	radians_to_degrees(float rad)
{
	float	deg;

	deg = rad * 180 / M_PI;
	return (deg);
}

t_matrix	matrix_rot_x(float angle)
{
	t_matrix	m;
	float		c;
	float		s;

	m = matrix_identity(4);
	angle = degrees_to_radians(angle);
	c = cos(angle);
	s = sin(angle);
	m.value[1][1] = c;
	m.value[1][2] = -s;
	m.value[2][1] = s;
	m.value[2][2] = c;
	return (m);
}

t_matrix	matrix_rot_y(float angle)
{
	t_matrix	m;
	float		c;
	float		s;

	m = matrix_identity(4);
	angle = degrees_to_radians(angle);
	c = cos(angle);
	s = sin(angle);
	m.value[0][0] = c;
	m.value[0][2] = s;
	m.value[2][0] = -s;
	m.value[2][2] = c;
	return (m);
}

t_matrix	matrix_rot_z(float angle)
{
	t_matrix	m;
	float		c;
	float		s;

	m = matrix_identity(4);
	angle = degrees_to_radians(angle);
	c = cos(angle);
	s = sin(angle);
	m.value[0][0] = c;
	m.value[0][1] = -s;
	m.value[1][0] = s;
	m.value[1][1] = c;
	return (m);
}
