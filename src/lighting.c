/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:14:11 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/25 18:51:51 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ambient_lighting(t_material m, t_light l)
{
	t_color	ambient;

	ambient = color_blend(m.color, l.col);
	ambient = color_scale_up(ambient, m.ambient);
	return	(ambient);
}

t_color	diffuse_lighting(t_material m, t_light l, float ln_dot)
{
	t_color	diffuse;

	diffuse = color_blend(m.color, l.col);
	diffuse = color_scale_up(diffuse, m.diffuse);
	diffuse = color_scale_up(diffuse, ln_dot);
	return (diffuse);
}

t_color	specular_lighting(t_material m, t_light l, float re_dot)
{
	t_color	specular;
	float	factor;

	factor = powf(re_dot, m.shininess);
	specular = color_scale_up(l.col, m.specular);
	specular = color_scale_up(specular, factor);
	return (specular);
}

t_color	lighting(t_material m, t_tuple p, t_light l, t_tuple ev, t_tuple nv)
{
	t_color	color;
	t_tuple	lightv;
	t_tuple reflex;
	float	dot;
	
	color = ambient_lighting(m, l);
	lightv = tuple_sub(l.p, p);
	lightv = tuple_normalize(lightv);
	dot = tuple_dot(lightv, nv);
	if (dot < 0)
		return (color);
	color = color_add(color, diffuse_lighting(m, l, dot));
	reflex = reflect(tuple_negate(lightv), nv);
	dot = tuple_dot(reflex, ev);
	if (dot <= 0)
		return	(color);
	color = color_add(color, specular_lighting(m, l, dot));
	return (color);
}
