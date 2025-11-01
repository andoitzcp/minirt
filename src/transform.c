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
        el->elda.sp.trans = m;
    else if (el->type == ELID_PL)
        el->elda.pl.t = m;
    else if (el->type == ELID_CY)
        el->elda.cy.t = m;
    return ;
}

void set_transform(t_object *object, t_matrix m)
{
    if (object->type == ELID_SP)
        object->data.sp.trans = m;
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

t_matrix view_transform(t_tuple from, t_tuple to, t_tuple up)
{
    t_matrix vm;
    t_tuple forward;
    t_tuple left;
    t_tuple true_up;
    t_matrix trans;
    t_matrix ori;

    forward = tuple_normalize(tuple_sub(to, from));
    left = tuple_cross(forward, tuple_normalize(up));
    true_up = tuple_cross(left, forward);
    ori.size = 4;
    ori.value[0][0] = left.x;
    ori.value[0][1] = left.y;
    ori.value[0][2] = left.z;
    ori.value[0][3] = 0;
    ori.value[1][0] = true_up.x;
    ori.value[1][1] = true_up.y;
    ori.value[1][2] = true_up.z;
    ori.value[1][3] = 0;
    ori.value[2][0] = -forward.x;
    ori.value[2][1] = -forward.y;
    ori.value[2][2] = -forward.z;
    ori.value[2][3] = 0;
    ori.value[3][0] = 0;
    ori.value[3][1] = 0;
    ori.value[3][2] = 0;
    ori.value[3][3] = 1;
    trans = matrix_translation(-from.x, -from.y, -from.z);
    vm = matrix_matrix_mult(ori, trans);
    return (vm);
}
