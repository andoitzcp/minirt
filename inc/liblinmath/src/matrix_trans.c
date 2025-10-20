/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:14:20 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/21 19:54:35 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

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

t_matrix	matrix_shearing(float props[6])
{
	t_matrix	m;

	m = matrix_identity(4);
	m.value[0][1] = props[0];
	m.value[0][2] = props[1];
	m.value[1][0] = props[2];
	m.value[1][2] = props[3];
	m.value[2][0] = props[4];
	m.value[2][1] = props[5];
	return (m);
}
