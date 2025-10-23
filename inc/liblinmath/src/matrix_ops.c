/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:41:00 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/22 20:08:04 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

float	matrix_row_col_mult(int row, int col, t_matrix a, t_matrix b)
{
	float	ret;
	int		i;

	if (row >= a.size || col >= b.size)
		return (NAN);
	ret = 0;
	i = 0;
	while (i < a.size)
	{
		ret += a.value[row][i] * b.value[i][col];
		i++;
	}
	return (ret);
}

t_matrix	matrix_matrix_mult(t_matrix a, t_matrix b)
{
	t_matrix	c;
	int			i;
	int			j;

	c = matrix_zero();
	c.size = b.size;
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < b.size)
		{
			c.value[i][j] = matrix_row_col_mult(i, j, a, b);
			j++;
		}
		i++;
	}
	return c;
}

t_tuple	matrix_tuple_mult(t_matrix m, t_tuple t)
{
	t_tuple	ret;

	ret.x = m.value[0][0] * t.x + m.value[0][1] * t.y +
		m.value[0][2] * t.z + m.value[0][3] * t.w;
	ret.y = m.value[1][0] * t.x + m.value[1][1] * t.y +
		m.value[1][2] * t.z + m.value[1][3] * t.w;
	ret.z = m.value[2][0] * t.x + m.value[2][1] * t.y +
		m.value[2][2] * t.z + m.value[2][3] * t.w;
	ret.w = m.value[3][0] * t.x + m.value[3][1] * t.y +
		m.value[3][2] * t.z + m.value[3][3] * t.w;
	return (ret);
}

t_matrix matrix_transpose(t_matrix m)
{
	t_matrix	new;
	int			i;
	int			j;

	new.size = m.size;
	i = 0;
	while (i < m.size)
	{
		j = 0;
		while(j < m.size)
		{
			new.value[i][j] = m.value[j][i];
			j++;
		}
		i++;
	}
	return new;
}

float	matrix_determinant(t_matrix m)
{
	float	det;
	int		j;

	if (m.size == 2)
	{
		det = m.value[0][0] * m.value[1][1] - m.value[0][1] * m.value[1][0];
		return (det);
	}
	det = 0;
	j = 0;
	while (j < m.size)
	{
		det = det + m.value[0][j] * matrix_cofactor(m, 0, j);
		j++;
	}
	return det;
}
