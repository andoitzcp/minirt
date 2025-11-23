/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 lighting.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/10/23 21:14:11 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/10/25 18:51:51 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

//TODO check amblighting ratio influence
t_color	ambient_lighting(t_material m, t_light l)
{
	t_color	ambient;

	ambient = color_blend(m.color, l.col);
	ambient = color_scale_up(ambient, 0.3);
	// ambient = color_scale_up(ambient, l.abr);
	ambient = color_scale_up(ambient, m.ambient);
	return (ambient);
}

t_color	diffuse_lighting(t_material m, t_light l, float ln_dot)
{
	t_color	diffuse;

	diffuse = color_blend(m.color, l.col);
	diffuse = color_scale_up(diffuse, 0.3);
	// diffuse = color_scale_up(diffuse, l.abr);
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

int	is_shadowed(t_world *w, t_tuple p)
{
	t_tuple	v;
	t_ray	r;
	float	distance;
	float	h;

	v = tuple_sub(w->l.p, p);
	distance = tuple_magnitude(v);
	r = new_ray(p, tuple_normalize(v));
	intersect_world(w, &r);
	h = hit(&r.i);
	destroy_intersects(r.i);
	if (h > 0 && h < distance)
		return (1);
	return (0);
}

/* t_color	lighting(t_comps comps) */
/* { */
/*	t_color effective_col; */
/*	t_tuple lightv; */
/*	t_color ambient; */

/*	effective_col = color_blend(comps.mat.color, comps.light.col); */
/*	lightv = tuple_normalize(tuple_sub(comps.light.p, comps.point)); */
/*	ambient = color_scale_up(effective_col, comps.mat.ambient); */

/* } */

// TODO añadir amblight en comps y utilizarla para el ambient lighting
t_color	lighting(t_comps comps)
{
	t_color	color;
	t_tuple	lightv;
	t_tuple	reflex;
	float	dot;

	color = ambient_lighting(comps.mat, comps.light);
	lightv = tuple_sub(comps.light.p, comps.point);
	lightv = tuple_normalize(lightv);
	dot = tuple_dot(lightv, comps.normv);
	if (dot < 0 || comps.is_shadowed)
		return (color);
	color = color_add(color, diffuse_lighting(comps.mat, comps.light, dot));
	reflex = reflect(tuple_negate(lightv), comps.normv);
	dot = tuple_dot(reflex, comps.eyev);
	if (dot <= 0)
		return (color);
	color = color_add(color, specular_lighting(comps.mat, comps.light, dot));
	return (color);
}
