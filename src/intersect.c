/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 intersect.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/10/26 20:20:42 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/21 20:41:24 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

t_intersects	*new_intersect(t_object *obj, float i)
{
	t_intersects	*node;

	node = malloc(sizeof(t_intersects));
	if (node == NULL)
		return (NULL);
	node->obj = obj;
	node->i = i;
	node->next = NULL;
	return (node);
}

void	insert_ray_intersect(t_intersects **head, t_intersects *node)
{
	t_intersects	*current;
	t_intersects	*prev;

	current = *head;
	if (current == NULL)
	{
		*head = node;
		return ;
	}
	if (node->i < current->i)
	{
		node->next = current;
		*head = node;
		return ;
	}
	while (current != NULL)
	{
		if (current->i > node->i)
			break ;
		prev = current;
		current = current->next;
	}
	if (current != NULL)
		node->next = current;
	prev->next = node;
	return ;
}

void	get_ray_el_intersects(t_ray *ray, t_object *obj)
{
	int				i;
	float			array[3];
	t_intersects	*node;
	t_ray			local_ray;

	local_ray = transform(*ray, obj->inverse);
	if (obj->type == ELID_SP)
		calc_ray_sp_intersects(array, &local_ray);
	if (obj->type == ELID_PL)
		calc_ray_pl_intersects(array, &local_ray);
	if (obj->type == ELID_CY)
		calc_ray_cy_intersects(array, &local_ray);
	i = 0;
	while (i++ < (int)array[0])
	{
		node = new_intersect(obj, array[i]);
		insert_ray_intersect(&(ray->i), node);
	}
	return ;
}

float	hit(t_intersects **head)
{
	t_intersects	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->i > 0)
			break ;
		current = current->next;
	}
	if (current != NULL)
		return (current->i);
	return (-1);
}
