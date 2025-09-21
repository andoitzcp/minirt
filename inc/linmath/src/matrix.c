/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:39:26 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/17 23:33:22 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"
#include <math.h>

t_matrix	matrix_zero()
{
	t_matrix	m;
	int			i;
	int			j;

	m.size = 4;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m.value[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

t_matrix	matrix_from_array(int size, float array[16])
{
	t_matrix	m;
	int			n;
	int			i;
	int			j;

	m = matrix_zero();
	m.size = size;
	n = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			m.value[i][j++] = array[n++];
		i++;
	}
	return (m);
}

t_matrix	matrix_identity(int size)
{
	t_matrix	m;
	int			i;

	m = matrix_zero();
	m.size = size;
	i = 0;
	while (i < size)
	{
		m.value[i][i] = 1;
		i++;
	}
	return (m);
}

t_matrix	matrix_translation(float x, float y, float z)
{
	t_matrix	m;

	m = matrix_identity(4);
	m.value[0][3] = x;
	m.value[1][3] = y;
	m.value[2][3] = z;
	return (m);
}

t_matrix	matrix_scalation(float x, float y, float z)
{
	t_matrix	m;

	m = matrix_zero();
	m.value[0][0] = x;
	m.value[1][1] = y;
	m.value[2][2] = z;
	m.value[3][3] = 1;
	return (m);
}

// t_matrix	matrix_rotation(float angle)
// {
// 	t_matrix	m;
//
// 	angle = radians_to_degrees(angle);
// 	m = matrix_zero();
// 	m.value[0][0] = 1;
// 	m.value[1][1] = cos(angle);
// 	m.value[1][2] = -sin(angle);
// 	m.value[2][1] = sin(angle);
// 	m.value[2][2] = cos(angle);
// 	m.value[3][3] = 1;
// 	return (m);
// }
