#include "minirt.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    //t_data data;
    t_world world;
    t_camera camera;
    t_object *floor;
    t_object *left_wall;
    t_object *right_wall;
    t_object *middle;
    t_object *right;
    t_object *left;
    t_matrix transform;
    t_material material;
    t_canvas *canvas;

    //data.emf = 0;
    //init(&data);
    //parse(&data, argv[1]);

    transform = matrix_scalation(10, 0.01, 10);
    material = def_material();
    material.color = color_set(1, 0.9, 0.9);
    material.specular = 0;
    floor = new_object(ELID_SP, &transform, &material);

    transform = matrix_translation(0, 0, 5);
    transform = matrix_matrix_mult(transform, matrix_rot_y(-45));
    transform = matrix_matrix_mult(transform, matrix_rot_x(90));
    transform = matrix_matrix_mult(transform, matrix_scalation(10, 0.01, 10));
    left_wall = new_object(ELID_SP, &transform, &material);

    transform = matrix_translation(0, 0, 5);
    transform = matrix_matrix_mult(transform, matrix_rot_y(45));
    transform = matrix_matrix_mult(transform, matrix_rot_x(90));
    transform = matrix_matrix_mult(transform, matrix_scalation(10, 0.01, 10));
    right_wall = new_object(ELID_SP, &transform, &material);

    transform = matrix_translation(-0.5, 1, 0.5);
    material = def_material();
    material.color = color_set(0.1, 1.0, 0.5);
    material.diffuse = 0.7;
    material.specular = 0.3;
    middle = new_object(ELID_SP, &transform, &material);

    transform = matrix_translation(1.5, 0.5, -0.5);
    transform = matrix_matrix_mult(transform, matrix_scalation(0.5, 0.5, 0.5));
    material = def_material();
    material.color = color_set(0.5, 1.0, 0.5);
    material.diffuse = 0.7;
    material.specular = 0.3;
    right = new_object(ELID_SP, &transform, &material);

    transform = matrix_translation(-1.5, 0.33, -0.75);
    transform = matrix_matrix_mult(transform, matrix_scalation(0.33, 0.33, 0.33));
    material = def_material();
    material.color = color_set(1.0, 0.8, 0.1);
    material.diffuse = 0.7;
    material.specular = 0.3;
    left = new_object(ELID_SP, &transform, &material);

    world = new_world();
    world.l = new_light(tuple_point(-10, 10, -10), color_set(1, 1, 1), 1);
    object_append(&world.objs, floor);
    object_append(&world.objs, left_wall);
    object_append(&world.objs, right_wall);
    object_append(&world.objs, middle);
    object_append(&world.objs, right);
    object_append(&world.objs, left);
    camera = new_camera(1920, 1080, M_PI / 3);
    camera.trans = view_transform(tuple_point(0, 1.5, -5),
                                  tuple_point(0, 1, 0),
                                  tuple_vector(0, 1, 0));
    canvas = render(camera, world);
    canvas_to_ppm(*canvas, "first_render.ppm");
}
