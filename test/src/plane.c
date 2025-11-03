#include "../../inc/liblinmath/src/linmath.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>


Test(plane, normal_at)
{
    t_object *plane;
    t_tuple n1;
    t_tuple n2;
    t_tuple n3;

    plane = new_object(ELID_PL, NULL, NULL);
    n1 = local_normal_at(plane, tuple_vector(0, 0, 0));
    n2 = local_normal_at(plane, tuple_vector(10, 0, -10));
    n3 = local_normal_at(plane, tuple_vector(-5, 0, 150));
    cr_expect(tuple_eq(n1, tuple_vector(0, 1, 0)));
    cr_expect(tuple_eq(n2, tuple_vector(0, 1, 0)));
    cr_expect(tuple_eq(n3, tuple_vector(0, 1, 0)));

}

Test(plane, pararell)
{
    //t_object *o;
    t_ray r;
    float array[3];

    //o = new_object(ELID_PL, NULL, NULL);
    r = new_ray(tuple_point(0, 0, 0), tuple_vector(0, 0, 1));
    calc_ray_pl_intersects(array, &r);
    cr_expect(float_eq(array[0], 0));
    cr_expect(float_eq(array[1], 0));
    cr_expect(float_eq(array[2], 0));
}

Test(plane, coplanar)
{
    //t_object *o;
    t_ray r;
    float array[3];

    //o = new_object(ELID_PL, NULL, NULL);
    r = new_ray(tuple_point(0, 10, 0), tuple_vector(0, 0, 1));
    calc_ray_pl_intersects(array, &r);
    cr_expect(float_eq(array[0], 0));
    cr_expect(float_eq(array[1], 0));
    cr_expect(float_eq(array[2], 0));
}

Test(plane, above)
{
    //t_object *o;
    t_ray r;
    float array[3];

    //o = new_object(ELID_PL, NULL, NULL);
    r = new_ray(tuple_point(0, 1, 0), tuple_vector(0, -1, 0));
    calc_ray_pl_intersects(array, &r);
    cr_expect(float_eq(array[0], 1));
    cr_expect(float_eq(array[1], 1));
    cr_expect(float_eq(array[2], 0));
}

Test(plane, bellow)
{
    //t_object *o;
    t_ray r;
    float array[3];

    //o = new_object(ELID_PL, NULL, NULL);
    r = new_ray(tuple_point(0, -1, 0), tuple_vector(0, 1, 0));
    calc_ray_pl_intersects(array, &r);
    cr_expect(float_eq(array[0], 1));
    cr_expect(float_eq(array[1], 1));
    cr_expect(float_eq(array[2], 0));
}
