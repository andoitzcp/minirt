#include "../../inc/liblinmath/src/linmath.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(world, default_world)
{
    t_world w;

    w = def_world();
    /* cr_expect(w.res.x_sz = DEF_RESOLUTION_X); */
    /* cr_expect(w.res.y_sz = DEF_RESOLUTION_Y); */
    /* cr_expect(float_eq(w.ali.ratio, 1.0)); */
    /* cr_expect(float_eq(w.ali.ratio, 1.0)); */
    /* cr_expect(float_eq(w.ali.col.r , 1.0)); */
    /* cr_expect(float_eq(w.ali.col.g , 1.0)); */
    /* cr_expect(float_eq(w.ali.col.b , 1.0)); */

    cr_expect(tuple_eq(w.l.p, tuple_point(-10, -10, -10)));
    cr_expect(float_eq(w.l.col.r , 1.0));
    cr_expect(float_eq(w.l.col.g , 1.0));
    cr_expect(float_eq(w.l.col.b , 1.0));
    cr_expect(float_eq(w.l.abr, 1.0));

    cr_expect(w.objs->type = ELID_SP);
    cr_expect(tuple_eq(w.objs->data.sp.p, tuple_point(0, 0, 0)));
    cr_expect(float_eq(w.objs->data.sp.mat.diffuse, 0.7));
    cr_expect(float_eq(w.objs->data.sp.mat.specular, 0.2));
    cr_expect(float_eq(w.objs->data.sp.mat.color.r, 0.8));
    cr_expect(float_eq(w.objs->data.sp.mat.color.g, 1.0));
    cr_expect(float_eq(w.objs->data.sp.mat.color.b, 0.6));

    cr_expect(w.objs->type = ELID_SP);
    cr_expect(tuple_eq(w.objs->data.sp.p, tuple_point(0, 0, 0)));
    cr_expect(matrix_eq(w.objs->next->data.sp.trans, matrix_scalation(0.5, 0.5, 0.5)));
    return ;
}

Test(world, world_intersect)
{
    t_world w;
    t_ray r;
    t_intersects *current;

    w = def_world();
    r = ray_new(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));
    intersect_world(&w, &r);

    current = r.i;
    int i = 0;
    float array[4] = {4.0, 4.5, 5.5, 6.0};
    while (current != NULL)
    {
        //print_intersections(&(r.i));
        cr_expect(float_eq(current->i, array[i]), "iter: %d, ex: %f, ac: %f", i, array[i], current->i);
        cr_expect(i < 4);
        current= current->next;
        i++;
    }
    cr_expect_eq(i, 4, "%d vs 4", i);
}

Test(world, prep_comps)
{
    t_ray r;
    t_object *o;
    t_intersects i;
    t_comps c;

    r = ray_new(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));
    o = new_object(ELID_SP, NULL, NULL);
    i.obj = o;
    i.i = 4.0;

    c = prep_comps(&i, &r);
    cr_assert(float_eq(c.t, i.i));
    cr_assert(c.obj == o);
    cr_assert(tuple_eq(c.point, tuple_point(0, 0, -1)));
    cr_assert(tuple_eq(c.eyev, tuple_vector(0, 0, -1)));
    cr_assert(tuple_eq(c.normv, tuple_vector(0, 0, -1)));
    return ;
}

Test(world, prep_comps_outside)
{
    t_ray r;
    t_object *o;
    t_intersects i;
    t_comps c;

    r = ray_new(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));
    o = new_object(ELID_SP, NULL, NULL);
    i.obj = o;
    i.i = 4.0;

    c = prep_comps(&i, &r);
    cr_assert(c.is_inside == 0);
    return ;
}

Test(world, prep_comps_inside)
{
    t_ray r;
    t_object *o;
    t_intersects i;
    t_comps c;

    r = ray_new(tuple_point(0, 0, 0), tuple_vector(0, 0, 1));
    o = new_object(ELID_SP, NULL, NULL);
    i.obj = o;
    i.i = 1.0;

    c = prep_comps(&i, &r);
    cr_assert(c.is_inside == 1);
    cr_assert(tuple_eq(c.point, tuple_point(0, 0, 1)));
    cr_assert(tuple_eq(c.eyev, tuple_vector(0, 0, -1)));
    cr_assert(tuple_eq(c.normv, tuple_vector(0, 0, -1)));
    return ;
}

Test(world, shade_hit_outside)
{
    t_world w;
    t_ray r;
    t_object *o;
    t_intersects i;
    t_comps c;
    t_color col;

    w = def_world();
    r = ray_new(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));
    o = w.objs;
    i.i = 4.0;
    i.obj = o;
    c = prep_comps(&i, &r);

    col = shade_hit(&w, &c);
    cr_assert(float_eq(col.r, 0.38066));
    cr_assert(float_eq(col.g, 0.47583));
    cr_assert(float_eq(col.b, 0.28550));
}

Test(world, shade_hit_inside)
{
    t_world w;
    t_ray r;
    t_object *o;
    t_intersects i;
    t_comps c;
    t_color col;

    w = def_world();
    w.l = new_light(tuple_point(0, 0.25, 0), color_set(1, 1, 1), 1);
    r = ray_new(tuple_point(0, 0, 0), tuple_vector(0, 0, 1));
    o = w.objs->next;
    i.i = 0.5;
    i.obj = o;
    c = prep_comps(&i, &r);

    col = shade_hit(&w, &c);
    cr_assert(float_eq(col.r, 0.90498));
    cr_assert(float_eq(col.g, 0.90498));
    cr_assert(float_eq(col.b, 0.90498));
}
