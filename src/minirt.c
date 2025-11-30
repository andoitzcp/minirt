/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 minirt.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: iubieta- <iubieta@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/15 14:08:03 by iubieta-		   #+#	  #+#			  */
/*	 Updated: 2025/11/15 14:09:10 by iubieta-		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "minirt.h"

int	populate_world(t_world *w, t_raw_data *rd)
{
	t_object	*o;
	uint		i;

	i = 0;
	while (i < rd->nels)
	{
		if (rd->els[i]->type == ELID_SP)
			o = new_sphere_from_raw_data(&rd->els[i]->relda.sp, &w->ali);
		else if (rd->els[i]->type == ELID_PL)
			o = new_plane_from_raw_data(&rd->els[i]->relda.pl, &w->ali);
		else if (rd->els[i]->type == ELID_CY)
			o = new_cylinder_from_raw_data(&rd->els[i]->relda.cy, &w->ali);
		else
			return (2);
		if (o == NULL)
			return (1);
		object_append(&w->objs, o);
		i++;
	}
	return (0);
}

//int main(void)
//{
//	t_data		data;
//	char *s= "cy  -12,0,0           1,0,0   1.0  6  255,140,0";
//	char ***line;
//	t_line *node;
//
//	line = split_line(s);
//	node = build_line_node(&data, line, 1);
//	destroy_rawlines(node);
//}

int	main(int argc, char **argv)
{
	t_data		data;
	t_canvas	*canvas;
	t_gui		gui;

	data.raw.res.x_sz = DEF_RESOLUTION_X;
	data.raw.res.y_sz = DEF_RESOLUTION_Y;
	if (argc != 2)
		exit(1);
	if (is_valid_input_file(argv[1]) == 0)
		exit(1);
	init(&data);
	parse(&data, argv[1]);
	destroy_regex(&data);
	destroy_rawlines(data.raw.lines);
	data.world = sig_mundus_creatus_est(&data.raw);
	if (populate_world(&data.world, &data.raw) != 0)
		ft_exit(&data, "TMP");
	destroy_elements(&data.raw);
	canvas = render(data.world.c, data.world);
	destroy_objs(data.world.objs);
	gui_init(&gui, *canvas);
	draw_canvas(&gui, *canvas);
	destroy_canvas(canvas);
	gui_loop(&gui);
}
