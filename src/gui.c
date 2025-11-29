/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:39:02 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/29 19:41:58 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img	gui_img_init(t_gui *gui, int width, int height)
{
	t_img	img;

	img.ptr = mlx_new_image(gui->mlx, width, height);
	if (!img.ptr)
	{
		perror("Failed to init image");
		exit(EXIT_FAILURE);
	}
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_len,
			&img.endian);
	if (!img.addr)
	{
		perror("Failed to init img address");
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	gui_init(t_gui *gui, t_canvas canv)
{
	gui->mlx = mlx_init();
	if (!gui->mlx)
	{
		perror("Failed to init mlx");
		exit(EXIT_FAILURE);
	}
	gui->width = canv.width;
	gui->height = canv.height;
	gui->window = mlx_new_window(gui->mlx, gui->width, gui->height, "FdF");
	if (!gui->window)
	{
		perror("Failed to init window");
		exit(EXIT_FAILURE);
	}
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
	exit(0);
}

int	close_window(void *param)
{
	t_gui	*gui;

	gui = (t_gui *)param;
	free_gui(gui);
	return (0);
}

void	window_ctrl(int keycode, t_gui *gui)
{
	if (keycode == 65307)
	{
		free_gui(gui);
	}
}

int	handle_key(int keycode, void *param)
{
	t_gui	*gui;

	gui = (t_gui *)param;
	window_ctrl(keycode, gui);
	return (0);
}

void	gui_loop(t_gui *gui)
{
	mlx_hook(gui->window, 17, 0, close_window, gui);
	mlx_hook(gui->window, 2, 1L << 0, handle_key, gui);
	mlx_loop(gui->mlx);
}
