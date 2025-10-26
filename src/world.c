#include "minirt.h"

t_world def_world(void)
{
    t_world world;
    t_matrix t;
    t_material mat;
    t_object *obj;

    world.res.x_sz = DEF_RESOLUTION_X;
    world.res.y_sz = DEF_RESOLUTION_Y;
    world.ali = def_amblight();
    world.l = def_light();
    world.c = def_camera();
    t = matrix_scalation(0.5, 0.5, 0.5);
    mat = def_material();
    mat.color = color_set(0.8, 1.0, 0.6);
    mat.diffuse = 0.7;
    mat.specular = 0.2;
    obj = new_object(ELID_SP, &t, NULL);
    object_append(&world.objs, obj);
    obj = new_object(ELID_SP, NULL, &mat);
    return (world);
}
