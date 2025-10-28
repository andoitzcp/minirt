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
    world.objs = NULL;
    obj = new_object(ELID_SP, NULL, &mat);
    object_append(&world.objs, obj);
    obj = new_object(ELID_SP, &t, NULL);
    object_append(&world.objs, obj);
    return (world);
}

void intersect_world(t_world *world, t_ray *ray)
{
    t_object *obj;

    obj = world->objs;
    while (obj != NULL)
    {
        get_ray_el_intersects(ray, obj);
        obj = obj->next;
    }
}

t_tuple normal_at(t_object *obj, t_tuple point)
{
    if (obj->type == ELID_SP)
        return (sphere_normal_at(obj->data.sp, point));
    if (obj->type == ELID_PL)
        return (plane_normal_at(obj->data.pl, point));
    if (obj->type == ELID_CY)
        return (cylinder_normal_at(obj->data.cy, point));
    return (tuple_point(0, 0, 0));
}

t_comps prep_comps(t_intersects *intersection, t_ray *ray)
{
    t_comps comps;

    comps.t = intersection->i;
    comps.obj = intersection->obj;
    comps.point = position(*ray, comps.t);
    comps.eyev = tuple_negate(ray->d);
    comps.normv = normal_at(comps.obj, comps.point);
    comps.is_inside = 0;
    if (tuple_dot(comps.normv, comps.eyev) < 0)
    {
        comps.is_inside = 1;
        comps.normv = tuple_negate(comps.normv);
    }
    return (comps);
}

t_color shade_hit(t_world *world, t_comps *comps)
{

    return (lighting(comps->obj.

}
