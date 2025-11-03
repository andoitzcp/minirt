#include "../../inc/liblinmath/src/linmath.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>


Test(cilinder, miss)
{
    float array[3];
    t_tuple o1;
    t_tuple o2;
    t_tuple o3;
    t_tuple d1;
    t_tuple d2;
    t_tuple d3;
    t_ray r;

    o1 = tuple_point(1, 0, 0);
    o2 = tuple_point(0, 0, 0);
    o3 = tuple_point(0, 0, -5);
    d1 = tuple_vector(0, 1, 0);
    d2 = tuple_vector(0, 1, 0);
    d3 = tuple_vector(1, 1, 1);

    array[0] = 0;
    array[1] = 0;
    array[2] = 0;
    r = new_ray(o1, d1);
    calc_ray_cy_intersects(array, &r);
    cr_expect(float_eq(array[0], 0));
    cr_expect(float_eq(array[1], 0));
    cr_expect(float_eq(array[2], 0));

    array[0] = 0;
    array[1] = 0;
    array[2] = 0;
    r = new_ray(o2, d2);
    calc_ray_cy_intersects(array, &r);
    cr_expect(float_eq(array[0], 0));
    cr_expect(float_eq(array[1], 0));
    cr_expect(float_eq(array[2], 0));

    array[0] = 0;
    array[1] = 0;
    array[2] = 0;
    r = new_ray(o3, d3);
    calc_ray_cy_intersects(array, &r);
    cr_expect(float_eq(array[0], 0));
    cr_expect(float_eq(array[1], 0));
    cr_expect(float_eq(array[2], 0));
}

Test(cilinder, hit)
{
    float array[3];
    t_tuple o1;
    t_tuple o2;
    t_tuple o3;
    t_tuple d1;
    t_tuple d2;
    t_tuple d3;
    float t01;
    float t02;
    float t03;
    float t11;
    float t12;
    float t13;
    t_ray r;

    o1 = tuple_point(1, 0, -5);
    o2 = tuple_point(0, 0, -5);
    o3 = tuple_point(0.5, 0, -5);
    d1 = tuple_vector(0, 0, 1);
    d2 = tuple_vector(0, 0, 1);
    d3 = tuple_vector(0.1, 1, 1);
    t01 = 5;
    t02 = 4;
    t03 = 6.80798;
    t11 = 5;
    t12 = 6;
    t13 = 7.08872;

    printf("flag200\n");
    array[0] = 0;
    array[1] = 0;
    array[2] = 0;
    r = new_ray(o1, d1);
    calc_ray_cy_intersects(array, &r);
    cr_expect(float_eq(array[0], 2.0),   "%f vs %f\n", array[0], (float)2);
    cr_expect(float_eq(array[1], t01), "%f vs %f\n", array[1], t01);
    cr_expect(float_eq(array[2], t11), "%f vs %f\n", array[2], t11);

    array[0] = 0;
    array[1] = 0;
    array[2] = 0;
    r = new_ray(o2, d2);
    calc_ray_cy_intersects(array, &r);
    cr_expect(float_eq(array[0], 2.0),   "%f vs %f\n", array[0], (float)2);
    cr_expect(float_eq(array[1], t02), "%f vs %f\n", array[1], t02);
    cr_expect(float_eq(array[2], t12), "%f vs %f\n", array[2], t12);

    array[0] = 0;
    array[1] = 0;
    array[2] = 0;
    r = new_ray(o3, d3);
    calc_ray_cy_intersects(array, &r);
    cr_expect(float_eq(array[0], 2.0),   "%f vs %f\n", array[0], (float)2);
    cr_expect(float_eq(array[1], t03), "%f vs %f\n", array[1], t03);
    cr_expect(float_eq(array[2], t13), "%f vs %f\n", array[2], t13);
}
