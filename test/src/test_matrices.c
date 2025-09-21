# include "../../src/linmath.h"
# include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(Matrix, size2) {
	t_matrix matrix;
	float values[16] = {0.1, 0.2, 0.3, 0.4};

	matrix = matrix_from_array(2, values);
	cr_expect(float_eq(matrix.value[0][0], 0.1) == true);
	cr_expect(float_eq(matrix.value[0][1], 0.2) == true);
	cr_expect(float_eq(matrix.value[0][2], 0) == true);
	cr_expect(float_eq(matrix.value[0][3], 0) == true);
	
	cr_expect(float_eq(matrix.value[1][0], 0.3) == true);
	cr_expect(float_eq(matrix.value[1][1], 0.4) == true);
	cr_expect(float_eq(matrix.value[1][2], 0) == true);
	cr_expect(float_eq(matrix.value[1][3], 0) == true);

	cr_expect(float_eq(matrix.value[2][0], 0) == true);
	cr_expect(float_eq(matrix.value[2][1], 0) == true);
	cr_expect(float_eq(matrix.value[2][2], 0) == true);
	cr_expect(float_eq(matrix.value[2][3], 0) == true);

	cr_expect(float_eq(matrix.value[3][0], 0) == true);
	cr_expect(float_eq(matrix.value[3][1], 0) == true);
	cr_expect(float_eq(matrix.value[3][2], 0) == true);
	cr_expect(float_eq(matrix.value[3][3], 0) == true);
}

Test(Matrix, size3) {
	t_matrix matrix;
	float values[16] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

	matrix = matrix_from_array(3, values);
	cr_expect(float_eq(matrix.value[0][0], 0.1) == true);
	cr_expect(float_eq(matrix.value[0][1], 0.2) == true);
	cr_expect(float_eq(matrix.value[0][2], 0.3) == true);
	cr_expect(float_eq(matrix.value[0][3], 0) == true);
	
	cr_expect(float_eq(matrix.value[1][0], 0.4) == true);
	cr_expect(float_eq(matrix.value[1][1], 0.5) == true);
	cr_expect(float_eq(matrix.value[1][2], 0.6) == true);
	cr_expect(float_eq(matrix.value[1][3], 0) == true);

	cr_expect(float_eq(matrix.value[2][0], 0.7) == true);
	cr_expect(float_eq(matrix.value[2][1], 0.8) == true);
	cr_expect(float_eq(matrix.value[2][2], 0.9) == true);
	cr_expect(float_eq(matrix.value[2][3], 0) == true);

	cr_expect(float_eq(matrix.value[3][0], 0) == true);
	cr_expect(float_eq(matrix.value[3][1], 0) == true);
	cr_expect(float_eq(matrix.value[3][2], 0) == true);
	cr_expect(float_eq(matrix.value[3][3], 0) == true);
}

Test(Matrix, size4) {
	t_matrix matrix;
	float values[16] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 
		0.9, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16};

	matrix = matrix_from_array(4, values);
	cr_expect(float_eq(matrix.value[0][0], 0.1) == true);
	cr_expect(float_eq(matrix.value[0][1], 0.2) == true);
	cr_expect(float_eq(matrix.value[0][2], 0.3) == true);
	cr_expect(float_eq(matrix.value[0][3], 0.4) == true);
	
	cr_expect(float_eq(matrix.value[1][0], 0.5) == true);
	cr_expect(float_eq(matrix.value[1][1], 0.6) == true);
	cr_expect(float_eq(matrix.value[1][2], 0.7) == true);
	cr_expect(float_eq(matrix.value[1][3], 0.8) == true);

	cr_expect(float_eq(matrix.value[2][0], 0.9) == true);
	cr_expect(float_eq(matrix.value[2][1], 0.10) == true);
	cr_expect(float_eq(matrix.value[2][2], 0.11) == true);
	cr_expect(float_eq(matrix.value[2][3], 0.12) == true);

	cr_expect(float_eq(matrix.value[3][0], 0.13) == true);
	cr_expect(float_eq(matrix.value[3][1], 0.14) == true);
	cr_expect(float_eq(matrix.value[3][2], 0.15) == true);
	cr_expect(float_eq(matrix.value[3][3], 0.16) == true);
}

Test(Matrix, matrix_eq) {
	t_matrix a;
	t_matrix b;
	float values[16] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 
		0.9, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16};
	float values_2[16] = {0.10001, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 
		0.9, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16};
	
	a = matrix_from_array(2, values);
	b = matrix_zero();
	cr_expect(matrix_eq(a, b) == 0);

	a = matrix_from_array(2, values);
	b = matrix_from_array(3, values);
	cr_expect(matrix_eq(a, b) == 0);
	
	a = matrix_zero();
	b = matrix_from_array(4, values);
	cr_expect(matrix_eq(a, b) == 0);
	
	a = matrix_from_array(2, values);
	b = matrix_from_array(2, values);
	cr_expect(matrix_eq(a, b) == 1);
	
	a = matrix_from_array(3, values);
	b = matrix_from_array(3, values);
	cr_expect(matrix_eq(a, b) == 1);
	
	a = matrix_from_array(4, values);
	b = matrix_from_array(4, values);
	cr_expect(matrix_eq(a, b) == 1);
	
	a = matrix_from_array(4, values);
	b = matrix_from_array(4, values_2);
	cr_expect(matrix_eq(a, b) == 0);
}

Test(Matrix, identity) {
	t_matrix a;
	t_matrix b;
	
	float values2[16] = 
	{1, 0,
	 0, 1};
	a = matrix_from_array(2, values2);
	b = matrix_identity(2);
	cr_expect(matrix_eq(a, b) == 1);
	
	
	float values3[16] = 
	{1, 0, 0,
	 0, 1, 0,
	 0, 0, 1};
	a = matrix_from_array(3, values3);
	b = matrix_identity(3);
	cr_expect(matrix_eq(a, b) == 1);
	
	float values4[16] = 
	{1, 0, 0, 0,
	 0, 1, 0, 0,
	 0, 0, 1, 0,
	 0, 0, 0, 1};
	a = matrix_from_array(4, values4);
	b = matrix_identity(4);
	cr_expect(matrix_eq(a, b) == 1);
}

Test(Matrix, mult_mxm) {
	t_matrix a;
	t_matrix b;

	float ar_a[16] = 
	{1, 2, 3, 4,
	 5, 6, 7, 8,
	 9, 8, 7, 6,
	 5, 4, 3, 2};
	float ar_b[16] = 
	{-2 , 1 , 2 , 3 ,
	 3 , 2 , 1 , -1 ,
	 4 , 3 , 6 , 5 ,
	 1 , 2 , 7 , 8};
	float ar_c[16] =
	{20, 22 , 50 , 48 ,
	 44, 54 , 114 , 108 ,
	 40, 58 , 110 , 102 ,
	 16, 26 , 46 , 42};
	a = matrix_from_array(4, ar_a);
	b = matrix_from_array(4, ar_b);
	a = matrix_matrix_mult(a, b);
	b = matrix_from_array(4, ar_c);
	cr_expect(matrix_eq(a,b));
}

Test(Matrix, mult_mxt) {
	t_matrix m;
	float ar_a[16] = 
	{1 , 2 , 3 , 4 ,
	 2 , 4 , 4 , 2 ,
	 8 , 6 , 4 , 1 ,
	 0 , 0 , 0 , 1};

	t_tuple a;
	t_tuple b;
	t_tuple c;

	m = matrix_from_array(4, ar_a);
	a = tuple_set(1, 2, 3, 1);
	b = tuple_set(18, 24, 33, 1);
	c = matrix_tuple_mult(m, a);
	cr_expect(tuple_eq(b, c));
}

Test(Matrix, translation) {
	t_matrix m;
	t_tuple t;
	t_tuple	e;
	t_tuple r;

	m = matrix_translation(1, 2, 3);
	t = tuple_point(0, 0, 0);
	e = tuple_point(1, 2, 3);
	r = matrix_tuple_mult(m, t);
	cr_expect(tuple_eq(e, r) == 1);
	
	m = matrix_translation(-1, -2, -3);
	t = tuple_point(0, 0, 0);
	e = tuple_point(-1, -2, -3);
	r = matrix_tuple_mult(m, t);
	cr_expect(tuple_eq(e, r) == 1);
}

Test(Matrix, scalation) {
	t_matrix m;
	t_tuple t;
	t_tuple	e;
	t_tuple r;

	m = matrix_scalation(1, 2, 3);
	t = tuple_point(2, 2, 2);
	e = tuple_point(2, 4, 6);
	r = matrix_tuple_mult(m, t);
	cr_expect(tuple_eq(e, r) == 1);
	
	m = matrix_scalation(-1, -2, -3);
	t = tuple_point(2, 2, 2);
	e = tuple_point(-2, -4, -6);
	r = matrix_tuple_mult(m, t);
	cr_expect(tuple_eq(e, r) == 1);
}

Test(matrix, rotation) {

	t_matrix a;
	t_matrix b;
	
	float values_x[16] = 
	{1, 0, 0, 0,
	 0, 0, -1, 0,
	 0, 1, 0, 0,
	 0, 0, 0, 1};
	a = matrix_from_array(4, values_x);
	b = matrix_rot_x(90);
	cr_expect(matrix_eq(a,b));
	
	float values_x2[16] = 
	{1, 0, 0, 0,
	 0, -1, 0, 0,
	 0, 0, -1, 0,
	 0, 0, 0, 1};
	a = matrix_from_array(4, values_x2);
	b = matrix_rot_x(180);
	cr_expect(matrix_eq(a,b));
	
	float values_x3[16] = 
	{1, 0, 0, 0,
	 0, 0.939692, -0.342020, 0,
	 0, 0.342020, 0.939692, 0,
	 0, 0, 0, 1};
	a = matrix_from_array(4, values_x3);
	b = matrix_rot_x(20);
	cr_expect(matrix_eq(a,b));
}
