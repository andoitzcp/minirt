/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:49 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/25 12:35:57 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple transform_back(t_matrix transform, t_tuple point)
{
	t_matrix	inverse;
	t_tuple		obj_point;

	inverse = matrix_inverse(transform);
	obj_point = matrix_tuple_mult(inverse, point);
	return (obj_point);
}
