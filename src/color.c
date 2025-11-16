/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:40:16 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/07 19:21:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

t_color	color_set(float r, float g, float b)
{
	t_color	c;
	
	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color color_limit(t_color c)
{
	c.r = float_limit(c.r, 0, 255);
	c.g = float_limit(c.g, 0, 255);
	c.b = float_limit(c.b, 0, 255);
	return (c);
}

t_color	color_clamp(t_color c)
{
	c.r = c.r * 255;
	c.g = c.g * 255;
	c.b = c.b * 255;
	c = color_limit(c);
	c.r = roundf(c.r);
	c.g = roundf(c.g);
	c.b = roundf(c.b);
	return (c);
}

t_color color_convert_from_raw(t_color color)
{
	t_color c;

	c.r = color.r;
	c.g = color.g;
	c.b = color.b;
	return (c);
}

int	color_to_int(t_color rgb)
{
	int	color;
	int	r;
	int	g;
	int	b;
	
	r = (int)rgb.r;
	g = (int)rgb.g;
	b = (int)rgb.b;
	color = (r << 16) | (g << 8) | b;
	return (color);
}
