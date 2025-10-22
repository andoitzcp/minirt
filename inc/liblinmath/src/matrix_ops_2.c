/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:37:16 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/22 20:27:29 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

t_matrix	matrix_submatrix(t_matrix m, int row, int col)
{
	t_matrix	subm;
	int			i;
	int			j;
	int			offset_i;
	int			offset_j;

	subm.size = m.size - 1;
	i = 0;
	offset_i = 0;
	while (i < subm.size)
	{
		if (i == row)
			offset_i++;
		j = 0;
		offset_j = 0;
		while (j < subm.size)
		{
			if (j == col)
				offset_j++;
			subm.value[i][j] = m.value[i + offset_i][j + offset_j];
			j++;
		}
		i++;
	}
	return (subm);
}

float	matrix_minor(t_matrix m, int row, int col)
{
	float		minor;
	t_matrix	subm;
	
	subm = matrix_submatrix(m, row, col);
	minor = matrix_determinant(subm);
}

float	matrix_cofactor(t_matrix m, int row, int col)
{
	float	cofactor;

	cofactor = matrix_minor(m, row, col);
	if ((row + col) % 2 != 0)
		cofactor = cofactor * (-1);
}
