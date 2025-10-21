#include "../../inc/liblinmath/src/linmath.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(ray, ray_new)
{
    t_tuple point;
    t_tuple vector;
    t_ray ray;

    point = tuple_point(1, 2, 3);
    vector = tuple_vector(4, 5, 6);
    ray = ray_new(point, vector);

    cr_expect_eq(ray.o.x, 1);
    cr_expect_eq(ray.o.y, 2);
    cr_expect_eq(ray.o.z, 3);
    cr_expect_eq(ray.o.w, 1);

    cr_expect_eq(ray.d.x, 4);
    cr_expect_eq(ray.d.y, 5);
    cr_expect_eq(ray.d.z, 6);
    cr_expect_eq(ray.d.w, 0);
}

Test(ray, position)
{
    t_ray ray;
    t_tuple pos;

    ray = ray_new(tuple_point(2, 3, 4), tuple_vector(1, 0, 0));
    pos = position(ray, 0);
    cr_expect(tuple_eq(pos, tuple_point(2, 3, 4)));
    pos = position(ray, 1);
    cr_expect(tuple_eq(pos, tuple_point(3, 3, 4)));
    pos = position(ray, -1);
    cr_expect(tuple_eq(pos, tuple_point(1, 3, 4)));
    pos = position(ray, 2.5);
    cr_expect(tuple_eq(pos, tuple_point(4.5, 3, 4)));
}
