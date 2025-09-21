/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:41:00 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/17 23:19:00 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

float	matrix_row_col_mult(int row, int col, t_matrix a, t_matrix b)
{
	float	ret;
	int		i;
	int		j;

	if (row >= a.size || col >= b.size)
		return (NAN);
	ret = 0;
	i = 0;
	while (i < a.size)
	{
		ret += a.val[row][i] * b.val[i][col];
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
			c.val[i][j] = matrix_row_col_mult(i, j, a, b);
			j++;
		}
	}
	return c;
}

t_tuple	matrix_tuple_mult(t_matrix m, t_tuple t)
{
	t_tuple	ret;

	ret.x = m.val[0][0] * t.x + m.val[0][1] * t.y + m.val[0][2] * t.z + m.val[0][3] * t.w;
	ret.y = m.val[1][0] * t.x + m.val[1][1] * t.y +
		m.val[1][2] * t.z + m.val[1][3] * t.w;
	ret.z = m.val[2][0] * t.x + m.val[2][1] * t.y +
		m.val[2][2] * t.z + m.val[2][3] * t.w;
	ret.w = m.val[3][0] * t.x + m.val[3][1] * t.y +
		m.val[3][2] * t.z + m.val[3][3] * t.w;
	return (ret);
}
