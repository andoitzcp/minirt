/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                       :+:    :+: :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:44:25 by acampo-p          #+#    #+#             */
/*   Updated: 2025/10/04 04:24:20 by andoitzcp   ########  ###                */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float helper(char *s)
{
	size_t len;
	float f;

	len = ft_strlen(s);
	f = 0;
	while (len > 0)
	{
		f += (float)(s[len - 1] - '0');
		f /= 10;
		len--;
	}
	return (f);


}

float ft_atof(const char *nptr)
{
	char *aux;
	char **s;
	float ret;

	aux = (char *)nptr;
	if (*nptr == '.')
		aux = ft_strjoin("0", nptr);
	s = ft_split(aux, '.');
	ret = (float)ft_atoi(s[0]);
	if (*nptr == '-')
		ret -= helper(s[1]);
	else
		ret += helper(s[1]);
	ft_free2parray(s);
	if (*nptr == '.')
		free(aux);
	return (ret);
}
