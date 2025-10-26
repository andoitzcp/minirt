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
    r = new_ray(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));
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
