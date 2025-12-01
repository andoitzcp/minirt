/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:13:22 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/30 22:21:33 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	shade_hit(t_world *world, t_comps *comps)
{
	t_tuple	over_point;

	over_point = tuple_add(comps->point,
			tuple_scale_up(comps->normv, 100 * EPS));
	comps->is_shadowed = is_shadowed(world, over_point);
	comps->light = world->l;
	comps->mat = comps->obj->mat;
	return (lighting(*comps));
}

t_intersects	*get_hit_intersect(t_ray *ray, float hit)
{
	t_intersects	*current;

	current = ray->i;
	while (current != NULL)
	{
		if (float_eq(current->i, hit))
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_color	color_at(t_world *world, t_ray *ray)
{
	float			h;
	t_intersects	*i;
	t_comps			c;

	intersect_world(world, ray);
	h = hit(&ray->i);
	if (h == -1)
		return (color_set(0, 0, 0));
	i = get_hit_intersect(ray, h);
	c = prep_comps(i, ray);
	c.amblight = world->ali;
	return (shade_hit(world, &c));
}

t_ray	ray_for_pixel(t_camera c, int px, int py)
{
	float	offset[2];
	float	world[2];
	t_tuple	pixel;
	t_tuple	rod[2];
	t_ray	ray;

	offset[0] = (px + 0.5) * c.pix_sz;
	offset[1] = (py + 0.5) * c.pix_sz;
	world[0] = c.half_width - offset[0];
	world[1] = c.half_height - offset[1];
	pixel = matrix_tuple_mult(matrix_inverse(c.trans),
			tuple_point(world[0], world[1], -1));
	rod[0] = matrix_tuple_mult(matrix_inverse(c.trans), tuple_point(0, 0, 0));
	rod[1] = tuple_normalize(tuple_sub(pixel, rod[0]));
	ray = new_ray(rod[0], rod[1]);
	return (ray);
}

t_canvas	*render(t_camera c, t_world w)
{
	int			i;
	int			j;
	t_canvas	*image;
	t_ray		r;
	t_color		col;

	image = canvas_init(c.hsize, c.vsize);
	i = 0;
	while (i < c.vsize)
	{
		j = 0;
		printf("\e[1;1H\e[2J");
		printf("Progress: %f\n", (float) 100 * i / c.vsize);
		while (j < c.hsize)
		{
			r = ray_for_pixel(c, j, i);
			col = color_at(&w, &r);
			destroy_intersects(r.i);
			canvas_set_pixel(image, j, i, col);
			j++;
		}
		i++;
	}
	return (image);
}
