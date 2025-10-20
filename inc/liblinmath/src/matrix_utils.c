/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:16:44 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/17 19:46:20 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

int	matrix_eq(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	if (a.size != b.size)
		return (0);
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			if (!float_eq(a.value[i][j], b.value[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	matrix_fill_limits(t_matrix *m, float value)
{
	int	i;
	int j;
	int size;

	size = m->size;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i >= size || j >= size)
				m->value[i][j] = value;
			j++;
		}
		i++;
	}
}
