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
    t_tuple over_point;

    over_point = tuple_add(comps->point, tuple_scale_up(comps->normv, EPS));
    comps->is_shadowed = is_shadowed(world, over_point);
    comps->light = world->l;
    if (comps->obj->type == ELID_SP)
    {
        comps->mat = comps->obj->data.sp.mat;
        //return (lighting(comps->obj->data.sp.mat, comps->point, world->l, comps->eyev, comps->normv));
    }
    else if (comps->obj->type == ELID_PL)
    {
        comps->mat = comps->obj->data.sp.mat;
        //return (lighting(comps->obj->data.pl.mat, comps->point, world->l, comps->eyev, comps->normv));
    }
    else
    {
        comps->mat = comps->obj->data.sp.mat;
        //return (lighting(comps->obj->data.cy.mat, comps->point, world->l, comps->eyev, comps->normv));
    }
    return (lighting(*comps));
}

t_intersects *get_hit_intersect(t_ray *ray, float hit)
{
    t_intersects *current;

    current = ray->i;
    while (current != NULL)
    {
        if (float_eq(current->i, hit))
            return (current);
        current = current->next;
    }
    return NULL;
}

t_color color_at(t_world *world, t_ray *ray)
{
    float h;
    t_intersects *i;
    t_comps c;

    intersect_world(world, ray);
    h = hit(&ray->i);
    if (h == -1)
        return (color_set(0, 0, 0));
    i = get_hit_intersect(ray, h);
    c = prep_comps(i, ray);
    return (shade_hit(world, &c));
}

t_ray ray_for_pixel(t_camera c, int px, int py)
{
    float offset[2];
    float world[2];
    t_tuple pixel;
    t_tuple rod[2];
    t_ray ray;


    offset[0] = (px + 0.5) * c.pix_sz;
    offset[1] = (py + 0.5) * c.pix_sz;
    world[0] = c.half_width - offset[0];
    world[1] = c.half_height - offset[1];
    pixel = matrix_tuple_mult(matrix_inverse(c.trans), tuple_point(world[0], world[1], -1));
    rod[0] = matrix_tuple_mult(matrix_inverse(c.trans), tuple_point(0, 0, 0));
    rod[1] = tuple_normalize(tuple_sub(pixel, rod[0]));
    ray = new_ray(rod[0], rod[1]);
    return (ray);
}

t_canvas *render(t_camera c, t_world w)
{
    int i;
    int j;
    t_canvas *image;
    t_ray r;
    t_color col;

    image = canvas_init(c.hsize, c.vsize);
    i = 0;
    while (i < c.vsize)
    {
        j = 0;
        while(j < c.hsize)
        {
            r = ray_for_pixel(c, j, i);
            col = color_at(&w, &r);
            canvas_set_pixel(image, j, i, col);
            j++;
        }
        i++;
    }
    return (image);
}
