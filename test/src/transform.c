#include "../../inc/liblinmath/src/linmath.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(transform, translate)
{
    t_ray r;
    t_matrix m;

    r = new_ray(tuple_point(1, 2, 3), tuple_vector(0, 1, 0));
    m = matrix_translation(3, 4, 5);

    r = transform(r, m);
    cr_expect(tuple_eq(r.o, tuple_point(4, 6, 8)));
    cr_expect(tuple_eq(r.d, tuple_vector(0, 1, 0)));
}

Test(transform, scaling)
{
    t_ray r;
    t_matrix m;

    r = new_ray(tuple_point(1, 2, 3), tuple_vector(0, 1, 0));
    m = matrix_scalation(2, 3, 4);

    r = transform(r, m);
    cr_expect(tuple_eq(r.o, tuple_point(2, 6, 12)));
    cr_expect(tuple_eq(r.d, tuple_vector(0, 3, 0)));
}

Test(transform, sphere)
{
    t_object obj;
    t_matrix m;
    t_ray r;
    float is[3];


    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    cr_expect(matrix_eq(obj.data.sp.trans, matrix_identity(4)));

    m = matrix_translation(2, 3, 4);
    set_transform(&obj, m);
    cr_expect(matrix_eq(obj.data.sp.trans, matrix_translation(2, 3, 4)));

    r = new_ray(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));
    obj.data.sp = new_sphere();
    set_transform(&obj, matrix_scalation(2, 2, 2));
    calc_ray_sp_intersects(is, &r, &(obj.data.sp));
    cr_expect_eq(is[0], 2.0, "%f vs %f\n", is[0], 2.0);
    cr_expect_eq(is[1], 3.0, "%f vs %f\n", is[1], 3.0);
    cr_expect_eq(is[2], 7.0, "%f vs %f\n", is[2], 7.0);

    obj.data.sp = new_sphere();
    set_transform(&obj, matrix_translation(5, 0, 0));
    calc_ray_sp_intersects(is, &r, &(obj.data.sp));
    cr_expect_eq(is[0], 0.0, "%f vs %f\n", is[0], 0.0);
    cr_expect_eq(is[1], 0.0, "%f vs %f\n", is[1], 0.0);
    cr_expect_eq(is[2], 0.0, "%f vs %f\n", is[2], 0.0);
}
