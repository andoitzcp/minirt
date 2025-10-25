/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:28:44 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/25 18:54:49 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	light(t_tuple p, t_color c)
{
	t_light light;

	light.p = p;
	light.col = c;
	light.abr = 1;
	return (light);
}
