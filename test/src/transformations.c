#include "test.h"

Test(sphere_transformation, translation)
{
	t_sphere	s;
	t_matrix	m;
	t_tuple		ret;
	t_tuple		expec;

	s = new_sphere();
	m = matrix_translation(0, 1, 0);
	set_sphere_transform(&s, m);
	ret = s.p;
	expec = tuple_point(0, 1, 0);
	expect_tuple_eq(ret, expec);
}

Test(sphere_transformation, scalation)
{
	t_sphere	s;
	t_matrix	m;
	t_tuple		ret;
	t_tuple		expec;

	s = new_sphere();
	m = matrix_scalation(2, 2, 2);
	set_sphere_transform(&s, m);
	ret = s.p;
	expec = tuple_point(0, 0, 0);
	expect_tuple_eq(ret, expec);
}

Test(sphere_transformation, combination)
{
	t_sphere	s;
	t_matrix	m;
	t_matrix	aux;
	t_tuple		ret;
	t_tuple		expec;

	s = new_sphere();
	m = matrix_translation(0, 1, 5);
	aux = matrix_scalation(9, 9, 9);
	m = matrix_matrix_mult(m, aux);
	set_sphere_transform(&s, m);
	ret = s.p;
	expec = tuple_point(0, 1, 5);
	expect_tuple_eq(ret, expec);
}


Test(transformation, view_transform_default_orientation)
{
	t_tuple from;
	t_tuple to;
	t_tuple up;
	t_matrix t;

	from = tuple_point(0, 0, 0);
	to = tuple_point(0, 0, -1);
	up = tuple_vector(0, 1, 0);
	t = view_transform(from, to, up);
	//print_matrix(&t);
	cr_expect(matrix_eq(t, matrix_identity(4)));
}

Test(transformation, view_transform_positive_z)
{
	t_tuple from;
	t_tuple to;
	t_tuple up;
	t_matrix t;
	t_matrix s;

	from = tuple_point(0, 0, 0);
	to = tuple_point(0, 0, 1);
	up = tuple_vector(0, 1, 0);
	t = view_transform(from, to, up);
	s = matrix_scalation(-1, 1, -1);
	//print_matrix(&t);
	//print_matrix(&s);
	cr_expect(matrix_eq(t, s));
}

Test(transformation, view_transform_move_world)
{
	t_tuple from;
	t_tuple to;
	t_tuple up;
	t_matrix t;

	from = tuple_point(0, 0, 8);
	to = tuple_point(0, 0, 0);
	up = tuple_vector(0, 1, 0);
	t = view_transform(from, to, up);
	cr_expect(matrix_eq(t, matrix_translation(0, 0, -8)));
}

Test(transformation, view_transform_arbitrary)
{
	t_tuple from;
	t_tuple to;
	t_tuple up;
	t_matrix t1;
	t_matrix t2;
	//float array[16];

	t2.size = 4;
	t2.value[0][0]  = -0.50709;
	t2.value[0][1]  = 0.50709;
	t2.value[0][2]  = 0.67612;
	t2.value[0][3]  = -2.36643;
	t2.value[1][0]  = 0.76772;
	t2.value[1][1]  = 0.60609;
	t2.value[1][2]  = 0.12122;
	t2.value[1][3]  = -2.82843;
	t2.value[2][0]  = -0.35857;
	t2.value[2][1]  = 0.59761;
	t2.value[2][2] = -0.71714;
	t2.value[2][3] = 0.0;
	t2.value[3][0] = 0.0;
	t2.value[3][1] = 0.0;
	t2.value[3][2] = 0.0;
	t2.value[3][3] = 1.0;

	from = tuple_point(1, 3, 2);
	to = tuple_point(4, -2, 8);
	up = tuple_vector(1, 1, 0);
	t1 = view_transform(from, to, up);
	cr_expect(matrix_eq(t1, t2));
}
