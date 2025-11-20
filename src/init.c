/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 init.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/20 20:35:07 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/20 20:35:07 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

static void	init_re_element_types(t_data *data)
{
	size_t	i;
	t_re	***re_array;

	re_array = data->raw.re_el_types;
	data->emf = data->emf | EMF_REET;
	re_array[ELID_A] = re_new(RE_EL_A);
	re_array[ELID_C] = re_new(RE_EL_C);
	re_array[ELID_L] = re_new(RE_EL_L);
	re_array[ELID_SP] = re_new(RE_EL_SP);
	re_array[ELID_PL] = re_new(RE_EL_PL);
	re_array[ELID_CY] = re_new(RE_EL_CY);
	re_array[ELID_BLANK_LINE] = re_new(RE_EL_BLANK);
	re_array[RE_TYPE_QTY] = NULL;
	i = 0;
	while (i < RE_TYPE_QTY)
	{
		if (re_array[i++] == NULL)
			ft_exit(data, ERRORS008);
	}
}

void	init(t_data *data)
{
	init_re_element_types(data);
	data->raw.lines = NULL;
	data->raw.re_float = re_new(RE_FLOAT);
	data->raw.re_int = re_new(RE_INT);
}
