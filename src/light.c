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

/*
 * Create new light struct from parameters
 */
t_light new_light(t_tuple point, t_color color, float ratio)
{
    t_light light;

    light.p = point;
    light.col = color;
    light.abr = ratio;
    return (light);
}

/*
 * Auxiliary function used in tests
 */
t_light def_light(void)
{
    t_light light;

    light.p = tuple_point(-10, -10, -10);
    light.abr = 1;
    light.col = color_set(1, 1, 1);
    return (light);
}

/**
 * Converts parsed light parameters into usable light variables
 */
t_light get_light_from_raw_data(t_raw_data *rd)
{
    t_light light;

    light.p = rd->l.p;
    light.abr = rd->l.abr;
    light.col = color_scale_down(rd->l.col, 255);
    return (light);
}
