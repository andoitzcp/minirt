/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:39:02 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/30 21:45:04 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img	gui_img_init(t_gui *gui, int width, int height)
{
	t_img	img;

	img.ptr = mlx_new_image(gui->mlx, width, height);
	if (!img.ptr)
		ft_exit(gui->data, "Failed to init image", 0);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_len,
			&img.endian);
	if (!img.addr)
		ft_exit(gui->data, "Failed to init img address", 0);
	return (img);
}

void	gui_init(t_gui *gui, t_canvas canv)
{
	gui->mlx = mlx_init();
	if (!gui->mlx)
		ft_exit(gui->data, "Failed to init mlx", 0);
	gui->width = canv.width;
	gui->height = canv.height;
	gui->window = mlx_new_window(gui->mlx, gui->width, gui->height, "MiniRT");
	if (!gui->window)
		ft_exit(gui->data, "Failed to init window", 0);
	gui->img = gui_img_init(gui, gui->width, gui->height);
}

void	free_gui(t_gui *gui)
{
	if (!gui)
		return ;
	if (gui->img.ptr)
	{
		mlx_destroy_image(gui->mlx, gui->img.ptr);
		gui->img.ptr = NULL;
	}
	if (gui->img.addr)
		gui->img.addr = NULL;
	if (gui->window)
	{
		mlx_destroy_window(gui->mlx, gui->window);
		gui->window = NULL;
	}
	if (gui->mlx)
	{
		mlx_destroy_display(gui->mlx);
		free(gui->mlx);
		gui->mlx = NULL;
	}
	ft_exit(gui->data, "EXITED SUCCESSFULLY\n", -1);
}
