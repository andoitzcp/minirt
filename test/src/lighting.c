#include "test.h"
#include <math.h>

Test(sphere_normal_at, x)
{
	t_sphere	s;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	s = new_sphere();
	p = tuple_point(1, 0, 0);
	ret = sphere_normal_at(s, p);
	expec = tuple_vector(1, 0, 0);
	expect_tuple_eq(ret, expec);
}

Test(sphere_normal_at, y)
{
	t_sphere	s;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	s = new_sphere();
	p = tuple_point(0, 1, 0);
	ret = sphere_normal_at(s, p);
	expec = tuple_vector(0, 1, 0);
	expect_tuple_eq(ret, expec);
}

Test(sphere_normal_at, z)
{
	t_sphere	s;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	s = new_sphere();
	p = tuple_point(0, 0, 1);
	ret = sphere_normal_at(s, p);
	expec = tuple_vector(0, 0, 1);
	expect_tuple_eq(ret, expec);
}

Test(sphere_normal_at, other_point)
{
	t_sphere	s;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	s = new_sphere();
	p = tuple_point(sqrtf(3)/3,sqrtf(3)/3,sqrtf(3)/3);
	ret = sphere_normal_at(s, p);
	expec = tuple_vector(sqrtf(3)/3,sqrtf(3)/3,sqrtf(3)/3);
	expect_tuple_eq(ret, expec);
}

Test(sphere_normal_at, is_normalized)
{
	t_sphere	s;
	t_tuple		p;
	t_tuple		ret;
	t_tuple		expec;

	s = new_sphere();
	p = tuple_point(sqrtf(3)/3,sqrtf(3)/3,sqrtf(3)/3);
	ret = sphere_normal_at(s, p);
	ret = tuple_normalize(ret);
	expec = tuple_vector(sqrtf(3)/3,sqrtf(3)/3,sqrtf(3)/3);
	expect_tuple_eq(ret, expec);
}


Test(sphere_normal_at, transformed_sphere_point_1)
{
	t_sphere	s;
	t_matrix	m;
	t_tuple		ret;
	t_tuple		expec;
	t_tuple		p;

	s = new_sphere();
	m = matrix_translation(0, 1, 0);
	set_sphere_transform(&s, m);

	p = tuple_point(0, 1.70711, -0.70711);
	ret = sphere_normal_at(s, p);
	expec = tuple_vector(0, 0.707107, -0.707107);
	expect_tuple_eq(ret, expec);
}

Test(sphere_normal_at, transformed_sphere_point_2)
{
	t_sphere	s;
	t_matrix	m;
	t_matrix	aux;
	t_tuple		ret;
	t_tuple		expec;
	t_tuple		p;

	s = new_sphere();
	m = matrix_scalation(1, 0.5, 1);
	aux = matrix_rot_z(radians_to_degrees(M_PI/5));
	m = matrix_matrix_mult(m, aux);
	set_sphere_transform(&s, m);

	p = tuple_point(0, sqrtf(2)/2, -sqrtf(2)/2);
	ret = sphere_normal_at(s, p);
	expec = tuple_vector(0, 0.970143, -0.242536);
	expect_tuple_eq(ret, expec);
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
	expect_tuple_eq(ret, expec);
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
	expect_tuple_eq(ret, expec);
}

Test(lighting, aligned_light_eye_normal)
{
	t_tuple e;
	t_tuple n;
	t_light l;
	t_color ret;
	t_color expec;

	e = tuple_vector(0, 0, -1);
	n = tuple_vector(0, 0, -1);
	l = light(tuple_point(0, 0, -10), color_set(1,1,1));
	ret = lighting(def_material(), tuple_point(0,0,0), l, e, n);
	expec = color_set(1.9, 1.9, 1.9);
	expect_color_eq(ret, expec, "lighting", 1);
}

Test(lighting, eye_45_from_normal)
{
	t_tuple e;
	t_tuple n;
	t_light l;
	t_color ret;
	t_color expec;

	e = tuple_vector(0, sqrt(2)/2, sqrtf(2)/2);
	n = tuple_vector(0, 0, -1);
	l = light(tuple_point(0, 0, -10), color_set(1,1,1));
	ret = lighting(def_material(), tuple_point(0,0,0), l, e, n);
	expec = color_set(1, 1, 1);
	expect_color_eq(ret, expec, "lighting", 2);
}

Test(lighting, light_45_from_normal)
{
	t_tuple e;
	t_tuple n;
	t_light l;
	t_color ret;
	t_color expec;

	e = tuple_vector(0, 0, -1);
	n = tuple_vector(0, 0, -1);
	l = light(tuple_point(0, 10, -10), color_set(1,1,1));
	ret = lighting(def_material(), tuple_point(0,0,0), l, e, n);
	expec = color_set(0.736396, 0.736396, 0.736396);
	expect_color_eq(ret, expec, "lighting", 2);
}

Test(lighting, eye_and_light_45_from_normal)
{
	t_tuple e;
	t_tuple n;
	t_light l;
	t_color ret;
	t_color expec;

	e = tuple_vector(0, -sqrt(2)/2, -sqrtf(2)/2);
	n = tuple_vector(0, 0, -1);
	l = light(tuple_point(0, 10, -10), color_set(1,1,1));
	ret = lighting(def_material(), tuple_point(0,0,0), l, e, n);
	expec = color_set(1.636385, 1.636385, 1.636385);
	expect_color_eq(ret, expec, "lighting", 2);
}

Test(lighting, light_oposite_to_normal)
{
	t_tuple e;
	t_tuple n;
	t_light l;
	t_color ret;
	t_color expec;

	e = tuple_vector(0, 0, -1);
	n = tuple_vector(0, 0, -1);
	l = light(tuple_point(0, 0, 10), color_set(1,1,1));
	ret = lighting(def_material(), tuple_point(0,0,0), l, e, n);
	expec = color_set(0.1, 0.1, 0.1);
	expect_color_eq(ret, expec, "lighting", 1);
}
