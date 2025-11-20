/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_data_basic.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/20 20:27:35 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/20 20:27:35 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

uint8_t	get_point_data(t_data *data, t_tuple *tuple, char **s)
{
	uint8_t	i;

	i = 0;
	while (s[i] != NULL)
	{
		if (match(data->raw.re_float, s[i]) != 1)
			return (0);
		i++;
	}
	tuple->x = ft_atof(s[0]);
	tuple->y = ft_atof(s[1]);
	tuple->z = ft_atof(s[2]);
	tuple->w = 1;
	return (1);
}

uint8_t	get_vector_data(t_data *data, t_tuple *tuple, char **s)
{
	uint8_t	i;

	i = 0;
	while (s[i] != NULL)
	{
		if (match(data->raw.re_float, s[i]) != 1)
			return (0);
		i++;
	}
	tuple->x = ft_atof(s[0]);
	tuple->y = ft_atof(s[1]);
	tuple->z = ft_atof(s[2]);
	tuple->w = 0;
	return (1);
}

uint8_t	get_color_data(t_data *data, t_color *color, char **s)
{
	uint8_t	i;

	i = 0;
	while (s[i] != NULL)
	{
		if (match(data->raw.re_int, s[i]) != 1)
			return (0);
		i++;
	}
	color->r = ft_atoi(s[0]);
	color->g = ft_atoi(s[1]);
	color->b = ft_atoi(s[2]);
	return (1);
}
