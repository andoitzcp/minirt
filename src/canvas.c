/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:13:45 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/15 23:28:39 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	*canvas_init(int width, int height)
{
	t_canvas	*can;

	if (width < 1 || height < 1)
		return (NULL);
	can = (t_canvas *)malloc(sizeof(t_canvas *));
	if (!can)
		return (NULL);
	can->width = width;
	can->height = height;
	can->pixel_block = (t_color *)malloc(sizeof(t_color) * width * height + 1);
	if (!can->pixel_block)
		return (NULL);
	can->image = (t_color **)malloc(sizeof(t_color*) * height);
	if (!can->image)
		return (NULL);
	canvas_set_color(can, color_set(0, 0, 0));
	return (can);
}

void	canvas_set_color(t_canvas *can, t_color c)
{
	int			i;
	int			j;
	
	i = 0;
	while (i < can->height)
	{
		can->image[i] = &can->pixel_block[i * can->width];
		j = 0;
		while (j < can->width)
			can->image[i][j++] = c;
		i++;
	}
}

int	canvas_set_pixel(t_canvas *can, int x, int y, t_color c)
{
	if (x >= can->width || y >= can->height)
		return (1);
	can->image[y][x] = c;
	return (0);
}

t_color	canvas_get_pixel(t_canvas can, int x, int y)
{
	if (x >= can.width || y >= can.height)
		return (color_set(NAN, NAN, NAN));
	return (can.image[y][x]);
}


