/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:39:26 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/22 19:51:57 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

t_matrix	matrix_zero(void)
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
			m.value[i][j++] = 0;
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

t_matrix matrix_inverse(t_matrix m)
{
	t_matrix	inverse;
	float		det;
	float		c;
	int			i;
	int			j;
	
	det = matrix_determinant(m);
	if (det == 0)
	{
		inverse = matrix_zero();
		inverse.size = 0;
		return (inverse);
	}
	i = 0;
	j = 0;
	inverse.size = m.size;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			c = matrix_cofactor(m, j, i);
			inverse.value[i][j] = c / det;
			j++;
		}
		i++;
	}
	return (inverse);
}
