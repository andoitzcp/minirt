/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_data_geo_els.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/20 20:28:53 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/20 20:28:53 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

uint8_t	get_sphere_data(t_data *data, t_raw_sphere *node, char ***line)
{
	if (get_point_data(data, &(node->p), line[1]) == 0)
		return (0);
	if (match(data->raw.re_float, line[2][0]) == 0)
		return (0);
	node->dia = ft_atof(line[2][0]);
	if (get_color_data(data, &(node->col), line[3]) == 0)
		return (0);
	if (check_color_bounds(&(node->col)) == 0)
		return (0);
	tuple_print(node->p);
	return (1);
}

uint8_t	get_plane_data(t_data *data, t_raw_plane *node, char ***line)
{
	if (get_point_data(data, &(node->p), line[1]) == 0)
		return (0);
	if (get_vector_data(data, &(node->v), line[2]) == 0)
		return (0);
	if (get_color_data(data, &(node->col), line[3]) == 0)
		return (0);
	if (check_nvector_bounds(&(node->v)) == 0)
		return (0);
	if (check_color_bounds(&(node->col)) == 0)
		return (0);
	return (1);
}

uint8_t	get_cylinder_data(t_data *data, t_raw_cylinder *node, char ***line)
{
	if (get_point_data(data, &(node->p), line[1]) == 0)
		return (0);
	if (get_vector_data(data, &(node->v), line[2]) == 0)
		return (0);
	if (match(data->raw.re_float, line[3][0]) == 0)
		return (0);
	node->dia = ft_atof(line[3][0]);
	if (match(data->raw.re_float, line[4][0]) == 0)
		return (0);
	node->hei = ft_atof(line[4][0]);
	if (get_color_data(data, &(node->col), line[5]) == 0)
		return (0);
	if (check_nvector_bounds(&(node->v)) == 0)
		return (0);
	if (check_color_bounds(&(node->col)) == 0)
		return (0);
	return (1);
}
