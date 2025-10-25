#include "test.h"

Test(sphere_transformation, translation)
{
	t_sphere	s;
	t_matrix	m;
	t_tuple		ret;
	t_tuple		expec;
	float		d;

	s = sphere();
	m = matrix_translation(0, 1, 0);
	set_sphere_transform(&s, m);
	ret = s.p;
	expec = tuple_point(0, 1, 0);
	d = 1;
	expect_tuple_eq(ret, expec);
	cr_expect(float_eq(d, s.dia));
}

Test(sphere_transformation, scalation)
{
	t_sphere	s;
	t_matrix	m;
	t_tuple		ret;
	t_tuple		expec;
	float		d;

	s = sphere();
	m = matrix_scalation(2, 2, 2);
	set_sphere_transform(&s, m);
	ret = s.p;
	expec = tuple_point(0, 0, 0);
	d = 2;
	expect_tuple_eq(ret, expec);
	cr_expect(float_eq(d, s.dia));
}

Test(sphere_transformation, combination)
{
	t_sphere	s;
	t_matrix	m;
	t_matrix	aux;
	t_tuple		ret;
	t_tuple		expec;
	float		d;

	s = sphere();
	m = matrix_translation(0, 1, 5);
	aux = matrix_scalation(9, 9, 9);
	m = matrix_matrix_mult(m, aux);
	set_sphere_transform(&s, m);
	ret = s.p;
	expec = tuple_point(0, 1, 5);
	d = 9;
	expect_tuple_eq(ret, expec);
	cr_expect(float_eq(d, s.dia));
}

