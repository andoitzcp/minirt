/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:49 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/25 20:15:54 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO revisar juntos
t_ray transform(t_ray r, t_matrix m)
{
    t_ray rret;

    rret.o = matrix_tuple_mult(m, r.o);
    rret.d = matrix_tuple_mult(m, r.d);
    return (rret);
}

// TODO eliminar old??
void set_transform_old(t_elements *el, t_matrix m)
{
    if (el->type == ELID_SP)
        el->elda.sp.t = m;
    else if (el->type == ELID_PL)
        el->elda.pl.t = m;
    else if (el->type == ELID_CY)
        el->elda.cy.t = m;
    return ;
}

void set_transform(t_object *object, t_matrix m)
{
    if (object->type == ELID_SP)
        object->data.sp.t = m;
    else if (object->type == ELID_PL)
        object->data.pl.t = m;
    else if (object->type == ELID_CY)
        object->data.cy.t = m;
    return ;
}

t_tuple transform_back(t_matrix transform, t_tuple point)
{
	t_matrix	inverse;
	t_tuple		obj_point;

	inverse = matrix_inverse(transform);
	obj_point = matrix_tuple_mult(inverse, point);
	return (obj_point);
}
