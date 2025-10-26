#include "../../inc/liblinmath/src/linmath.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(calc_ray_sp_intersects, twopoints)
{
    t_ray r;
    t_sphere sp;
    float array[3];

    r = ray_new(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));
    sp = new_sphere();
    calc_ray_sp_intersects(array, &r, &sp);

    cr_expect_eq(array[0], 2);
    cr_expect(float_eq(array[1], 4), "%f, %f\n", array[1], (float)4);
    cr_expect(float_eq(array[2], 6), "%f, %f\n", array[2], (float)6);
}


Test(calc_ray_sp_intersects, tangent)
{
    t_ray r;
    t_sphere sp;
    float array[3];

    r = ray_new(tuple_point(0, 1, -5), tuple_vector(0, 0, 1));
    sp = new_sphere();
    calc_ray_sp_intersects(array, &r, &sp);

    cr_expect_eq(array[0], 2);
    cr_expect(float_eq(array[1], 5), "%f, %f\n", array[1], (float)0);
    cr_expect(float_eq(array[2], 5), "%f, %f\n", array[2], (float)0);
}

Test(calc_ray_sp_intersects, miss)
{
    t_ray r;
    t_sphere sp;
    float array[3];

    r = ray_new(tuple_point(0, 2, -5), tuple_vector(0, 0, 1));
    sp = new_sphere();
    calc_ray_sp_intersects(array, &r, &sp);

    cr_expect_eq(array[0], 0);
    cr_expect(float_eq(array[1], 0), "%f, %f\n", array[1], (float)0);
    cr_expect(float_eq(array[2], 0), "%f, %f\n", array[2], (float)0);
}

Test(calc_ray_sp_intersects, inside)
{
    t_ray r;
    t_sphere sp;
    float array[3];

    r = ray_new(tuple_point(0, 0, 0), tuple_vector(0, 0, 1));
    sp = new_sphere();
    calc_ray_sp_intersects(array, &r, &sp);

    cr_expect_eq(array[0], 2);
    cr_expect(float_eq(array[1], -1), "%f, %f\n", array[1],(float) -1);
    cr_expect(float_eq(array[2], 1 ), "%f, %f\n", array[2], (float) 1);
}

Test(calc_ray_sp_intersects, behind)
{
    t_ray r;
    t_sphere sp;
    float array[3];

    r = ray_new(tuple_point(0, 0, 5), tuple_vector(0, 0, 1));
    sp = new_sphere();
    calc_ray_sp_intersects(array, &r, &sp);

    cr_expect_eq(array[0], 2);
    cr_expect(float_eq(array[1], -6), "%f, %f\n", array[1], (float)-6);
    cr_expect(float_eq(array[2], -4), "%f, %f\n", array[2], (float)-4);
}

// TODO add calc_ray_pl_intersects Tests
// TODO add calc_ray_cy_intersects Tests

Test(get_ray_el_intersects, order)
{
    t_ray r;
    t_object obj;
    t_intersects *inters;
    int i;

    r = ray_new(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, 5);
    get_ray_el_intersects(&r, &obj);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, 1);
    get_ray_el_intersects(&r, &obj);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, 3);
    get_ray_el_intersects(&r, &obj);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, 0);
    get_ray_el_intersects(&r, &obj);

    float array[8] = {4, 5, 6, 7, 7, 9, 9, 11};
    inters = r.i;
    i = 0;
    while (inters != NULL)
    {
        //print_intersections(&(r.i));
        cr_expect(float_eq(inters->i, array[i]), "iter: %d, ex: %f, ac: %f", i, array[i], inters->i);
        cr_expect(i < 8);
        inters = inters->next;
        i++;
    }
    cr_expect_eq(i, 8, "%d vs 8", i);
}

/*
** Regla para medir cuanta distancia hay entre 2 puntos.
** -5 -4 -3 -2 -1  0  1  2  3  4  5
**  .--.--.--.--.--.--.--.--.--.--.
**  0--1--2--3--4--5--6--7--8--9--10
*/

Test(hit, general)
{
    t_ray r;
    t_object obj;
    float h;

    r = ray_new(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, -50);
    get_ray_el_intersects(&r, &obj);

    h = hit(&(&r)->i);
    cr_expect_eq(h, -1, "hit: %f vs expect %f\n", h, -1.0);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, -30);
    get_ray_el_intersects(&r, &obj);

    h = hit(&(&r)->i);
    cr_expect_eq(h, -1, "hit: %f vs expect %f\n", h, -1.0);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, 5);
    get_ray_el_intersects(&r, &obj);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, 1);
    get_ray_el_intersects(&r, &obj);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, 3);
    get_ray_el_intersects(&r, &obj);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, 0);
    get_ray_el_intersects(&r, &obj);

    h = hit(&(&r)->i);
    cr_expect_eq(h, 4, "hit: %f vs expect %f\n", h, 4.0);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, -3);
    get_ray_el_intersects(&r, &obj);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, -4);
    get_ray_el_intersects(&r, &obj);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, -8);
    get_ray_el_intersects(&r, &obj);

    h = hit(&(&r)->i);
    cr_expect_eq(h, 1, "hit: %f vs expect %f\n", h, 1.0);

    obj.type = ELID_SP;
    obj.data.sp = new_sphere();
    obj.data.sp.p = tuple_point(0, 0, -3.5);
    get_ray_el_intersects(&r, &obj);

    h = hit(&(&r)->i);
    cr_expect_eq(h, 0.5, "hit: %f vs expect %f\n", h, 0.5);
}

