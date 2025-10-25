/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:38:48 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/25 20:14:18 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO elegir entre material y default_material
t_material	material()
{
	t_material mat;

	mat.color = color_set(1, 1, 1);
	mat.ambient = 0.1;
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 200;

	return (mat);
}

// TODO elegir entre material y default_material
t_material default_material(void)
{
    t_material m;

    m.color = color_set(1, 1, 1);
    m.ambient = 1;
    m.diffuse = 1;
    m.shininess = 1;
    m.specular = 1;
    return (m);
}

void set_material(t_object *object, t_material material)
{
    if (object->type == ELID_SP)
        object->data.sp.mat = material;
    else if (object->type == ELID_PL)
        object->data.pl.mat = material;
    else if (object->type == ELID_CY)
        object->data.cy.mat = material;
    return ;
}
