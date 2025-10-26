#include "../../inc/liblinmath/src/linmath.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(world, default_world)
{
    t_world w;
    t_matrix t;
    t_material mat;
    t_object *o1;
    t_object *o2;

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

}
