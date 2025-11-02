#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdlib.h>
#include "test.h"
#include "../../src/minirt.h"

Test(is_shadowed, lps_triangle) {
	t_world	w;
	t_tuple	p;

	w = def_world();
	p = tuple_point(0, 10, 0);

	int	ret;
	int	expec;

	ret = is_shadowed(&w, p);
	expec = 0;
	cr_expect(ret == expec);
}

Test(is_shadowed, lsp_diagonal) {
	t_world	w;
	t_tuple	p;

	w = def_world();
	w.l.p = tuple_point(-10, 10 , -10);
	p = tuple_point(10, -10, 10);

	int	ret;
	int	expec;

	ret = is_shadowed(&w, p);
	expec = 1;
	cr_expect(ret == expec);
}

Test(is_shadowed, pls_diagonal) {
	t_world	w;
	t_tuple	p;

	w = def_world();
	p = tuple_point(-20, 20, -20);

	int	ret;
	int	expec;

	ret = is_shadowed(&w, p);
	expec = 0;
	cr_expect(ret == expec);
}


Test(is_shadowed, lps_diagonal) {
	t_world	w;
	t_tuple	p;

	w = def_world();
	p = tuple_point(-2, 2, -2);

	int	ret;
	int	expec;

	ret = is_shadowed(&w, p);
	expec = 0;
	cr_expect(ret == expec);
}

Test(is_shadowed, overpoint)
{
	t_world	w;
	t_object *obj;
	t_object *obj2;
	t_matrix	t;

	w = new_world();
	w.l.p = tuple_point(0, 0, -10);
	obj = new_object(ELID_SP, NULL, NULL); 
	object_append(&w.objs, obj);
	t = matrix_translation(0, 0, 10);
	obj2 = new_object(ELID_SP, &t, NULL); 
	object_append(&w.objs, obj2);
	
	t_intersects i;
	t_ray	r;
	t_comps	comps;
	r = new_ray(tuple_point(0, 0, 5), tuple_vector(0, 0, 1));
	i.i = 4;
	i.obj = obj2;
	comps = prep_comps(&i, &r);

	t_color	ret;
	t_color	expec;
	ret = shade_hit(&w, &comps);
	expec = color_set(0.1, 0.1, 0.1);
	expect_color_eq(ret, expec, "shadowed_shade_hit", 1);
}

Test(shade_hit, overpoint) 
{
	t_ray	r;
	t_object *obj;
	t_intersects i;
	t_comps		comps;
	t_material m;
	t_matrix	t;

	r = new_ray(tuple_point(0, 0, -5), tuple_vector(0, 0, 1));

	m = def_material();
	t = matrix_translation(0, 0, 10);
	obj = new_object(ELID_SP, &t, &m);
	
	i.i = 5.0;
	i.obj = obj;

	comps = prep_comps(&i, &r);
	cr_expect(comps.op.z < -EPS / 2);
	cr_expect(comps.point.z > comps.op.z);
}
