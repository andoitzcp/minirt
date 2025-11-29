/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_data_common.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/20 20:28:25 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/20 20:28:25 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

uint8_t	get_amblight_data(t_data *data, t_raw_amblight *node, char ***line)
{
	if (match(data->raw.re_float, line[1][0]) == 0)
		return (0);
	node->ratio = ft_atof(line[1][0]);
	if (get_color_data(data, &(node->col), line[2]) == 0)
		return (0);
	if (check_color_bounds(&(node->col)) == 0)
		return (0);
	return (1);
}

uint8_t	get_camera_data(t_data *data, t_raw_camera *node, char ***line)
{
	if (get_point_data(data, &(node->p), line[1]) == 0)
		return (0);
	if (get_vector_data(data, &(node->v), line[2]) == 0)
		return (0);
	if (match(data->raw.re_int, line[3][0]) == 0)
		return (0);
	node->fov = ft_atoi(line[3][0]);
	if (node->fov > 180)
		return (0);
	return (1);
}

uint8_t	get_light_data(t_data *data, t_raw_light *node, char ***line)
{
	if (get_point_data(data, &(node->p), line[1]) == 0)
		return (0);
	if (match(data->raw.re_float, line[2][0]) == 0)
		return (0);
	node->abr = ft_atof(line[2][0]) / 10;
	if (node->abr < 0 || node->abr > 1)
		return (0);
	if (get_color_data(data, &(node->col), line[3]) == 0)
		return (0);
	if (check_color_bounds(&(node->col)) == 0)
		return (0);
	return (1);
}
