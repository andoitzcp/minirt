#include "test.h"
#include <math.h>

Test(sphere_normal_at, x)
{
	t_object *o;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	o = new_object(ELID_SP, NULL, NULL);
	p = tuple_point(1, 0, 0);
	ret = normal_at(o, p);
	expec = tuple_vector(1, 0, 0);
	cr_expect(tuple_eq(ret, expec));
}

Test(sphere_normal_at, y)
{
	t_object *o;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	o = new_object(ELID_SP, NULL, NULL);
	p = tuple_point(0, 1, 0);
	ret = normal_at(o, p);
	expec = tuple_vector(0, 1, 0);
	cr_expect(tuple_eq(ret, expec));
}

Test(sphere_normal_at, z)
{
	t_object *o;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	o = new_object(ELID_SP, NULL, NULL);
	p = tuple_point(0, 0, 1);
	ret = normal_at(o, p);
	expec = tuple_vector(0, 0, 1);
	cr_expect(tuple_eq(ret, expec));
}

Test(sphere_normal_at, other_point)
{
	t_object *o;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	o = new_object(ELID_SP, NULL, NULL);
	p = tuple_point(sqrtf(3)/3,sqrtf(3)/3,sqrtf(3)/3);
	ret = normal_at(o, p);
	expec = tuple_vector(sqrtf(3)/3,sqrtf(3)/3,sqrtf(3)/3);
	cr_expect(tuple_eq(ret, expec));
}

Test(sphere_normal_at, is_normalized)
{
	t_object *o;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	o = new_object(ELID_SP, NULL, NULL);
	p = tuple_point(sqrtf(3)/3,sqrtf(3)/3,sqrtf(3)/3);
	ret = normal_at(o, p);
	ret = tuple_normalize(ret);
	expec = tuple_vector(sqrtf(3)/3,sqrtf(3)/3,sqrtf(3)/3);
	cr_expect(tuple_eq(ret, expec));
}


Test(sphere_normal_at, transformed_sphere_point_1)
{
	t_object *o;
	t_matrix	m;
	t_tuple		ret;
	t_tuple		expec;
	t_tuple		p;

	m = matrix_translation(0, 1, 0);
	o = new_object(ELID_SP, &m, NULL);

	p = tuple_point(0, 1.70711, -0.70711);
	ret = normal_at(o, p);
	expec = tuple_vector(0, 0.707107, -0.707107);
	cr_expect(tuple_eq(ret, expec));
}

Test(sphere_normal_at, transformed_sphere_point_2)
{
	t_object *o;
	t_matrix	m;
	t_matrix	aux;
	t_tuple		ret;
	t_tuple		expec;
	t_tuple		p;

	m = matrix_scalation(1, 0.5, 1);
	aux = matrix_rot_z(radians_to_degrees(M_PI/5));
	m = matrix_matrix_mult(m, aux);
	o = new_object(ELID_SP, &m, NULL);

	p = tuple_point(0, sqrtf(2)/2, -sqrtf(2)/2);
	ret = normal_at(o, p);
	expec = tuple_vector(0, 0.970143, -0.242536);
	cr_expect(tuple_eq(ret, expec));
}

Test(reflex, angle_45)
{
	t_tuple v;
	t_tuple n;
	t_tuple ret;
	t_tuple expec;

	v = tuple_vector(1, -1, 0);
	n = tuple_vector(0, 1, 0);
	ret = reflect(v, n);
	expec = tuple_vector(1, 1, 0);
	cr_expect(tuple_eq(ret, expec));
}

Test(reflex, surface_45)
{
	t_tuple v;
	t_tuple n;
	t_tuple ret;
	t_tuple expec;

	v = tuple_vector(0, -1, 0);
	n = tuple_vector(sqrt(2)/2, sqrtf(2)/2, 0);
	ret = reflect(v, n);
	expec = tuple_vector(1, 0, 0);
	cr_expect(tuple_eq(ret, expec));
}

Test(lighting, aligned_light_eye_normal)
{
	t_color ret;
	t_color expec;
	t_comps comps;
	
	comps.point = tuple_point(0,0,0);
	comps.mat = def_material();
	comps.eyev = tuple_vector(0, 0, -1);
	comps.normv = tuple_vector(0, 0, -1);
	comps.light = new_light(tuple_point(0, 0, -10), color_set(1,1,1), 1);
	ret = lighting(comps);
	expec = color_set(1.9, 1.9, 1.9);
	expect_color_eq(ret, expec, "lighting", 1);
}

Test(lighting, eye_45_from_normal)
{
	t_color ret;
	t_color expec;
	t_comps comps;

	comps.point = tuple_point(0,0,0);
	comps.mat = def_material();
	comps.eyev = tuple_vector(0, sqrt(2)/2, sqrtf(2)/2);
	comps.normv = tuple_vector(0, 0, -1);
	comps.light = new_light(tuple_point(0, 0, -10), color_set(1,1,1), 1);
	ret = lighting(comps);
	expec = color_set(1, 1, 1);
	expect_color_eq(ret, expec, "lighting", 2);
}

Test(lighting, light_45_from_normal)
{
	t_color ret;
	t_color expec;
	t_comps comps;

	comps.point = tuple_point(0,0,0);
	comps.mat = def_material();
	comps.eyev = tuple_vector(0, 0, -1);
	comps.normv = tuple_vector(0, 0, -1);
	comps.light = new_light(tuple_point(0, 10, -10), color_set(1,1,1), 1);
	ret = lighting(comps);
	expec = color_set(0.736396, 0.736396, 0.736396);
	expect_color_eq(ret, expec, "lighting", 2);
}

Test(lighting, eye_and_light_45_from_normal)
{
	t_color ret;
	t_color expec;
	t_comps comps;

	comps.point = tuple_point(0,0,0);
	comps.mat = def_material();
	comps.eyev = tuple_vector(0, -sqrt(2)/2, -sqrtf(2)/2);
	comps.normv = tuple_vector(0, 0, -1);
	comps.light = new_light(tuple_point(0, 10, -10), color_set(1,1,1), 1);
	ret = lighting(comps);
	expec = color_set(1.636385, 1.636385, 1.636385);
	expect_color_eq(ret, expec, "lighting", 2);
}

Test(lighting, light_oposite_to_normal)
{
	t_color ret;
	t_color expec;
	t_comps comps;

	comps.point = tuple_point(0,0,0);
	comps.mat = def_material();
	comps.eyev = tuple_vector(0, 0, -1);
	comps.normv = tuple_vector(0, 0, -1);
	comps.light = new_light(tuple_point(0, 0, 10), color_set(1,1,1), 1);
	ret = lighting(comps);
	expec = color_set(0.1, 0.1, 0.1);
	expect_color_eq(ret, expec, "lighting", 1);
}
