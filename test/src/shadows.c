#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdlib.h>
#include "test.h"
#include "../../src/minirt.h"

Test(is_shadowed, lps_triangle) {
	t_world	w;
	t_tuple	p;
	t_material m;
	t_object *obj;

    w.res.x_sz = DEF_RESOLUTION_X;
    w.res.y_sz = DEF_RESOLUTION_Y;
    w.ali = def_amblight();
    w.l = def_light();
	w.l.p = tuple_point(-10, 10, 0);
    w.c = def_camera();
	p = tuple_point(0, 10, 0);
    w.objs = NULL;
	m = def_material();
	obj = new_object(ELID_SP, NULL, &m); 
	object_append(&w.objs, obj);

	int	ret;
	int	expec;

	ret = is_shadowed(&w, p);
	expec = 0;
	cr_expect(ret == expec);
}

Test(is_shadowed, lsp_diagonal) {
	t_world	w;
	t_tuple	p;
	t_material m;
	t_object *obj;

    w.res.x_sz = DEF_RESOLUTION_X;
    w.res.y_sz = DEF_RESOLUTION_Y;
    w.ali = def_amblight();
    w.l = def_light();
	w.l.p = tuple_point(-10, 10, 0);
    w.c = def_camera();
	p = tuple_point(5, -5, 0);
    w.objs = NULL;
	m = def_material();
	obj = new_object(ELID_SP, NULL, &m); 
	object_append(&w.objs, obj);

	int	ret;
	int	expec;

	ret = is_shadowed(&w, p);
	expec = 1;
	cr_expect(ret == expec);
}

Test(is_shadowed, pls_diagonal) {
	t_world	w;
	t_tuple	p;
	t_material m;
	t_object *obj;

    w.res.x_sz = DEF_RESOLUTION_X;
    w.res.y_sz = DEF_RESOLUTION_Y;
    w.ali = def_amblight();
    w.l = def_light();
	w.l.p = tuple_point(-10, 10, 0);
    w.c = def_camera();
	p = tuple_point(-20, 20, 0);
    w.objs = NULL;
	m = def_material();
	obj = new_object(ELID_SP, NULL, &m); 
	object_append(&w.objs, obj);

	int	ret;
	int	expec;

	ret = is_shadowed(&w, p);
	expec = 0;
	cr_expect(ret == expec);
}

Test(is_shadowed, lps_diagonal) {
	t_world	w;
	t_tuple	p;
	t_material m;
	t_object *obj;

    w.res.x_sz = DEF_RESOLUTION_X;
    w.res.y_sz = DEF_RESOLUTION_Y;
    w.ali = def_amblight();
    w.l = def_light();
	w.l.p = tuple_point(-10, 10, 0);
    w.c = def_camera();
	p = tuple_point(-5, 5, 0);
    w.objs = NULL;
	m = def_material();
	obj = new_object(ELID_SP, NULL, &m); 
	object_append(&w.objs, obj);

	int	ret;
	int	expec;

	ret = is_shadowed(&w, p);
	expec = 0;
	cr_expect(ret == expec);
}
