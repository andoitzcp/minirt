/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 21:41:28 by iubieta-          #+#    #+#             */
/*   Updated: 2025/11/30 21:45:04 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
