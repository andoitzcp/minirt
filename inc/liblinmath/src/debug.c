/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:40:25 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/25 19:43:38 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"

void	matrix_print(t_matrix m)
{
	int i;
	int j;

	i = 0;
	while(i < m.size)
	{
		j = 0;
		while(j < m.size)
		{
			printf("%f ", m.value[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	tuple_print(t_tuple t)
{
	printf("x: %f, y: %f, z: %f, w: %f\n", t.x,t.y,t.z,t.w);
}
