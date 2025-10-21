#include "../../inc/liblinmath/src/linmath.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(intersect_sp_old, twopoints)
{
    t_ray r;
    t_sphere sp;
    t_intersect_old xs;

    r = ray_new(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));
    sp.p = tuple_point(0, 0, 0);
    sp.dia = 1;
    sp.col = color_set(1, 0, 0);
    xs = intersect_sp_old(&r, &sp);

    cr_expect_eq(xs.q, 2);
    cr_expect(float_eq(xs.i[0], 4), "%f, %f\n", xs.i[0], (float)4);
    cr_expect(float_eq(xs.i[1], 6), "%f, %f\n", xs.i[1], (float)6);
}


Test(intersect_sp_old, tangent)
{
    t_ray r;
    t_sphere sp;
    t_intersect_old xs;

    r = ray_new(tuple_point(0, 1, -5), tuple_vector(0, 0, 1));
    sp.p = tuple_point(0, 0, 0);
    sp.dia = 1;
    sp.col = color_set(1, 0, 0);
    xs = intersect_sp_old(&r, &sp);

    cr_expect_eq(xs.q, 2, "q=%d\n", xs.q);
    cr_expect(float_eq(xs.i[0], 5), "%f, %f\n", xs.i[0], (float)0);
    cr_expect(float_eq(xs.i[1], 5), "%f, %f\n", xs.i[1], (float)0);
}

Test(intersect_sp_old, miss)
{
    t_ray r;
    t_sphere sp;
    t_intersect_old xs;

    r = ray_new(tuple_point(0, 2, -5), tuple_vector(0, 0, 1));
    sp.p = tuple_point(0, 0, 0);
    sp.dia = 1;
    sp.col = color_set(1, 0, 0);
    xs = intersect_sp_old(&r, &sp);

    cr_expect_eq(xs.q, 0, "q=%d\n", xs.q);
    cr_expect(float_eq(xs.i[0], 0), "%f, %f\n", xs.i[0], (float)0);
    cr_expect(float_eq(xs.i[1], 0), "%f, %f\n", xs.i[1], (float)0);
}

Test(intersect_sp_old, inside)
{
    t_ray r;
    t_sphere sp;
    t_intersect_old xs;

    r = ray_new(tuple_point(0, 0, 0), tuple_vector(0, 0, 1));
    sp.p = tuple_point(0, 0, 0);
    sp.dia = 1;
    sp.col = color_set(1, 0, 0);
    xs = intersect_sp_old(&r, &sp);

    cr_expect_eq(xs.q, 2);
    cr_expect(float_eq(xs.i[0], -1), "%f, %f\n", xs.i[0],(float) -1);
    cr_expect(float_eq(xs.i[1], 1 ), "%f, %f\n", xs.i[1], (float) 1);
}

Test(intersect_sp_old, behind)
{
    t_ray r;
    t_sphere sp;
    t_intersect_old xs;

    r = ray_new(tuple_point(0, 0, 5), tuple_vector(0, 0, 1));
    sp.p = tuple_point(0, 0, 0);
    sp.dia = 1;
    sp.col = color_set(1, 0, 0);
    xs = intersect_sp_old(&r, &sp);

    cr_expect_eq(xs.q, 2);
    cr_expect(float_eq(xs.i[0], -6), "%f, %f\n", xs.i[0], (float)-6);
    cr_expect(float_eq(xs.i[1], -4), "%f, %f\n", xs.i[1], (float)-4);
}
