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
	printf("flag1000: nels = %d\n", rd->nels);
	while (i < rd->nels)
	{
		printf("flag1001: nels = %d\n", rd->nels);
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
		printf("flag1002: %p\n", o);
		object_append(&w->objs, o);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_canvas	*canvas;
	t_gui		gui;

	data.raw.res.x_sz = 900;
	data.raw.res.y_sz = 500;
	if (argc != 2)
		exit(1);
	if (is_valid_input_file(argv[1]) == 0)
		exit(1);
	init(&data);
	parse(&data, argv[1]);
	data.world = sig_mundus_creatus_est(&data.raw);
	if (populate_world(&data.world, &data.raw) != 0)
		ft_exit(&data, "TMP");
	// canvas_init(data.world.c.hsize, data.world.c.hsize); //TODO eliminar??
	canvas = render(data.world.c, data.world);
	canvas_to_ppm(*canvas, "first_render.ppm");
	gui_init(&gui, *canvas);
	draw_canvas(&gui, *canvas);
	destroy_canvas(canvas);
	gui_loop(&gui);
}

/* int main(int argc, char **argv) */
/* { */
/*	   (void)argc; */
/*	   (void)argv; */
/*	   //t_data data; */
/*	   t_world world; */
/*	   t_camera camera; */
/*	   t_object *floor; */
/*	   //t_object *left_wall; */
/*	   //t_object *right_wall; */
/*	   t_object *middle; */
/*	   t_object *right; */
/*	   t_object *left; */
/*	   t_object *cyl; */
/*	   t_matrix transform; */
/*	   t_material material; */
/*	   t_canvas *canvas; */

/*	   //data.emf = 0; */
/*	   //init(&data); */
/*	   //parse(&data, argv[1]); */

/*	   transform = matrix_translation(0, 1, 0); */
/*	   material = def_material(); */
/*	   material.color = color_set(1, 0.9, 0.9); */
/*	   material.specular = 2; */
/*	   floor = new_object(ELID_PL, NULL, &material); */

/*	   /\* transform = matrix_translation(0, 0, 5); *\/ */
/*	   /\* transform = matrix_matrix_mult(transform, matrix_rot_y(-45)); *\/ */
/*	   /\* transform = matrix_matrix_mult(transform, matrix_rot_x(90)); *\/ */
/*	   /\* transform = matrix_matrix_mult(transform, matrix_scalation(10, 0.01, 10)); *\/ */
/*	   /\* left_wall = new_object(ELID_SP, &transform, &material); *\/ */

/*	   /\* transform = matrix_translation(0, 0, 5); *\/ */
/*	   /\* transform = matrix_matrix_mult(transform, matrix_rot_y(45)); *\/ */
/*	   /\* transform = matrix_matrix_mult(transform, matrix_rot_x(90)); *\/ */
/*	   /\* transform = matrix_matrix_mult(transform, matrix_scalation(10, 0.01, 10)); *\/ */
/*	   /\* right_wall = new_object(ELID_SP, &transform, &material); *\/ */

/*	   transform = matrix_translation(-0.5, 1, 0.5); */
/*	   material = def_material(); */
/*	   material.color = color_set(0.1, 1.0, 0.5); */
/*	   material.diffuse = 0.7; */
/*	   material.specular = 0.3; */
/*	   middle = new_object(ELID_SP, &transform, &material); */

/*	   transform = matrix_translation(1.5, 0.5, -0.5); */
/*	   transform = matrix_matrix_mult(transform, matrix_scalation(0.5, 0.5, 0.5)); */
/*	   material = def_material(); */
/*	   material.color = color_set(0.5, 1.0, 0.5); */
/*	   material.diffuse = 0.7; */
/*	   material.specular = 0.3; */
/*	   right = new_object(ELID_SP, &transform, &material); */

/*	   transform = matrix_translation(-1.5, 0.33, -0.75); */
/*	   transform = matrix_matrix_mult(transform, matrix_scalation(0.33, 0.33, 0.33)); */
/*	   material = def_material(); */
/*	   material.color = color_set(1.0, 0.8, 0.1); */
/*	   material.diffuse = 0.7; */
/*	   material.specular = 0.3; */
/*	   left = new_object(ELID_SP, &transform, &material); */

/*	   transform = matrix_translation(-0.5, 1, 0.5); */
/*	   transform = matrix_matrix_mult(transform, matrix_rot_z(-90)); */
/*	   transform = matrix_matrix_mult(transform, matrix_rot_x(-90)); */
/*	   //transform = matrix_matrix_mult(transform, matrix_rot_y(-90)); */
/*	   transform = matrix_matrix_mult(transform, matrix_scalation(0.33, 2.33, 0.33)); */
/*	   cyl = new_object(ELID_CY, &transform, &material); */

/*	   world = new_world(); */
/*	   world.l = new_light(tuple_point(-10, 10, -10), color_set(1, 1, 1), 1); */
/*	   object_append(&world.objs, floor); */
/*	   //object_append(&world.objs, left_wall); */
/*	   //object_append(&world.objs, right_wall); */
/*	   (void)middle; */
/*	   //object_append(&world.objs, middle); */
/*	   object_append(&world.objs, right); */
/*	   object_append(&world.objs, left); */
/*	   object_append(&world.objs, cyl); */
/*	   camera = new_camera(500, 500, M_PI / 3); */
/*	   //camera = new_camera(1920, 1080, M_PI / 3); */
/*	   camera.trans = view_transform(tuple_point(0, 1.5, -5), */
/*									 tuple_point(0, 1, 0), */
/*									 tuple_vector(0, 1, 0)); */
/*	   canvas = render(camera, world); */
/*	   canvas_to_ppm(*canvas, "first_render.ppm"); */
/* } */
