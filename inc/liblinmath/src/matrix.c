/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:39:26 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/21 19:57:53 by iubieta-         ###   ########.fr       */
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

