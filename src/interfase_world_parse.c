/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 interfase_world_parse.c							:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/21 20:39:30 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/21 20:39:30 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

t_world	sig_mundus_creatus_est(t_raw_data *rd)
{
	t_world			w;
	t_camera		c;
	t_amblight		ambl;
	t_light			l;
	t_resolution	res;

	c = get_camera_from_raw_data(rd);
	ambl = get_amblight_from_raw_data(rd);
	l = get_light_from_raw_data(rd);
	res.x_sz = DEF_RESOLUTION_X;
	res.y_sz = DEF_RESOLUTION_Y;
	w = new_world(&res, &ambl, &l, &c);
	return (w);
}
