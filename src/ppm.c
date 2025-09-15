/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:17:27 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/15 23:31:26 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

void	ppm_write_header(t_canvas can, int fd)
{
	dprintf(fd, "P3\n");
	dprintf(fd, "%i %i\n", can.width, can.height);
	dprintf(fd, "255\n");
}

int	ppm_write_value(int value, int linelen, int fd)
{
	char	*s;
	int		len;
	
	s = ft_itoa(value);
	len = ft_strlen(s);
	if (linelen + 1 + len > 70)
		ft_putchar_fd('\n', fd);
	else if (linelen > 0)
	{
		ft_putchar_fd(' ', fd);
		len = linelen + 1 + len;
	}
	ft_putstr_fd(s, fd);
	free(s);
	return (len);
}

int ppm_write_pixel(t_color c, int linelen, int fd)
{
	int	len;

	len = linelen;
	c = color_clamp(c);
	len = ppm_write_value(c.r, len, fd);
	len = ppm_write_value(c.g, len, fd);
	len = ppm_write_value(c.b, len, fd);
	return (len);
}

int	canvas_to_ppm(t_canvas can, char *path)
{
	int	fd;
	int i;
	int j;
	int len;

	if (!path || !path[0])
		return (1);
	path = ft_strjoin(path, ".ppm");
	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	free(path);
	if (fd == -1)
		return (errno);
	ppm_write_header(can, fd);
	i = 0;
	while (i < can.height)
	{
		j = 0;
		len = 0;
		while (j < can.width)
			len = ppm_write_pixel(can.image[i][j++], len, fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
	close(fd);
	return (0);
}
