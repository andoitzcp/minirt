/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:05:06 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/07 16:04:04 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_add(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r + b.r;
	c.g = a.g + b.g;
	c.b = a.b + b.b;
	return (c);
}

t_color	color_sub(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r - b.r;
	c.g = a.g - b.g;
	c.b = a.b - b.b;
	return (c);
}

t_color	color_scale_up(t_color a, float n)
{
	t_color	c;

	c.r = a.r * n;
	c.g = a.g * n;
	c.b = a.b * n;
	return (c);
}

t_color	color_scale_down(t_color a, float n)
{
	t_color	c;

	if (n == 0)
		c = color_set(NAN, NAN, NAN);
	else
	{
		c.r = a.r / n;
		c.g = a.g / n;
		c.b = a.b / n;
	}
	return (c);
}

t_color	color_blend(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r * b.r;
	c.g = a.g * b.g;
	c.b = a.b * b.b;
	return (c);
}
