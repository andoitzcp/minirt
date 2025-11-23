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
