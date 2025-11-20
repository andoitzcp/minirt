/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:02:46 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/20 20:04:23 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_amblight	new_amblight(t_color color, float ratio)
{
	t_amblight	amblight;

	amblight.col = color;
	amblight.ratio = ratio;
	return (amblight);
}

t_amblight	def_amblight(void)
{
	t_amblight	amblight;

	amblight.ratio = 1;
	amblight.col = color_set(1, 1, 1);
	return (amblight);
}

/**
 * Converts parsed ambient light parameters into usable ambient light
 * parameters. This is later used in the definition of the default material.
 */
t_amblight	get_amblight_from_raw_data(t_raw_data *rd)
{
	t_amblight	al;

	al.col = color_scale_down(rd->ali.col, 255);
	al.ratio = rd->ali.ratio;
	return (al);
}
