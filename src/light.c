/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:28:44 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/25 20:12:13 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light convert_light_from_raw(t_raw_light raw_light)
{
    t_light light;

    light.p = raw_light.p;
    light.abr = raw_light.abr;
    light.col.r = raw_light.col.r / 255;
    light.col.g = raw_light.col.g / 255;
    light.col.b = raw_light.col.b / 255;
    return (light);
}

// TODO elegir entre light, new_light, default_light
t_light	light(t_tuple p, t_color c)
{
	t_light light;

	light.p = p;
	light.col = c;
	light.abr = 1;
	return (light);
}

// TODO elegir entre light, new_light, default_light
t_light new_light(t_tuple point, t_color color, float ratio)
{
    t_light light;

    light.p = point;
    light.col = color;
    light.abr = ratio;
    return (light);
}

// TODO elegir entre light, new_light, default_light
t_light default_light(void)
{
    t_light light;

    light.p = tuple_point(-10, -10, -10);
    light.abr = 1;
    light.col = color_set(1, 1, 1);
    return (light);
}
