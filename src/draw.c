/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:59:20 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/20 20:26:25 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_point(t_gui *gui, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < gui->width && y >= 0 && y < gui->height)
	{
		i = (x * gui->img.bpp / 8) + (y * gui->img.line_len);
		gui->img.addr[i] = color & 0xFF;
		gui->img.addr[++i] = (color >> 8) & 0xFF;
		gui->img.addr[++i] = (color >> 16) & 0xFF;
	}
}

void	draw_canvas(t_gui *gui, t_canvas canv)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < canv.height)
	{
		x = 0;
		while (x < canv.width)
		{
			color = color_to_int(color_clamp(canv.image[y][x]));
			draw_point(gui, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(gui->mlx, gui->window, gui->img.ptr, 0, 0);
}
