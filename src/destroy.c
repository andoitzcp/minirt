/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:15:06 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/23 13:06:38 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_canvas(t_canvas *can)
{
	free(can->image);
	can->image = NULL;
	free(can->pixel_block);
	can->pixel_block = NULL;
	free(can);
	can = NULL;
}

void	destroy_objs(t_object *objs)
{
	t_object	*cur;
	t_object	*next;
	
	cur = objs;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	objs = NULL;
}

void	destroy_intersects(t_intersects *i)
{
	t_intersects	*cur;
	t_intersects	*next;

	cur = i;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	i = NULL;
}

void destroy_regex(t_data *data)
{
	t_re	***re_array;

	re_array = data->raw.re_el_types;
	re_destroy(re_array[ELID_A]);
	re_destroy(re_array[ELID_C]);
	re_destroy(re_array[ELID_L]);
	re_destroy(re_array[ELID_SP]);
	re_destroy(re_array[ELID_PL]);
	re_destroy(re_array[ELID_CY]);
	re_destroy(re_array[ELID_BLANK_LINE]);
	re_destroy(data->raw.re_float);
	re_destroy(data->raw.re_int);
	data->raw.re_el_types[ELID_A] = NULL;
	data->raw.re_el_types[ELID_C] = NULL;
	data->raw.re_el_types[ELID_L] = NULL;
	data->raw.re_el_types[ELID_SP] = NULL;
	data->raw.re_el_types[ELID_PL] = NULL;
	data->raw.re_el_types[ELID_CY] = NULL;
	data->raw.re_el_types[ELID_BLANK_LINE] = NULL;
	data->raw.re_float = NULL;
	data->raw.re_int = NULL;
	return ;
}

static void free_3parray(char ***array)
{
	size_t i;
	size_t j;

	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != NULL)
			free(array[i][j++]);
		i++;
	}
	return ;
}

void destroy_rawlines(t_line *rls)
{
	t_line *node;
	t_line *p;

	node = rls;
	while (node != NULL)
	{
		p = node;
		node = node->next;
		free_3parray(p->content);
		free(p);
	}

	return ;
}
