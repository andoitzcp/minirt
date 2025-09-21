/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:30:50 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/07 15:44:16 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linmath.h"
#include <math.h>

int	float_eq(float a, float b)
{
	if (isinf(a) && isinf(b))
		return (a == b);
	if (isnan(a) || isnan(b))
		return (0);
	return (fabsf(a - b) < EPS);
}

float	float_limit(float n, float min, float max)
{
	if (isnan(n))
		return (NAN);
	if (n < min)
		return (min);
	if (n > max)
		return (max);
	return (n);
}
