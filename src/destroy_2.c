/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:16:52 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/30 22:19:45 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_3parray(char ***array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		ft_free2parray(array[i++]);
	free(array);
	array = NULL;
	return ;
}

void	destroy_elements(t_raw_data *rd)
{
	size_t		i;
	t_elements	**array;

	array = rd->els;
	i = 0;
	while (i < rd->nels)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
	return ;
}
