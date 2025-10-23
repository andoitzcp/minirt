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

Test(matrix, transpose) {

	t_matrix a;
	t_matrix b;
	
	float values_a[16] = 
	{0, 9, 3, 0,
	 9, 8, 0, 8,
	 1, 8, 5, 3,
	 0, 0, 5, 8};
	float values_b[16] = 
	{0, 9, 1, 0,
	 9, 8, 8, 0,
	 3, 0, 5, 5,
	 0, 8, 3, 8};

	a = matrix_from_array(4, values_a);
	b = matrix_from_array(4, values_b);
	a = matrix_transpose(a);
	cr_expect(matrix_eq(a, b));
}

Test(matrix, determinant_2x2) {
	
	t_matrix a;
	float	ret;
	float	expec;
	
	float values_a[16] = 
	{1, 5, -3, 2};
	a = matrix_from_array(2, values_a);
	ret = matrix_determinant(a);
	expec = 17;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
}

Test (matrix, submatrix_1) {
	
	t_matrix a;
	t_matrix b;

	float values_a[16] = 
	{0, 9, 3,
	 0, 9, 8,
	 0, 5, 8};
	float values_b[16] = 
	{9, 3,
	 5, 8};

	a = matrix_from_array(3, values_a);
	b = matrix_from_array(2, values_b);
	a = matrix_submatrix(a, 1, 0);
	cr_expect(matrix_eq(a, b));
}


Test (matrix, submatrix_2) {
	
	t_matrix a;
	t_matrix b;

	float values_a[16] = 
	{-6, 1, 3, 5,
	  0, 9, 8, 2,
	  3, 0, 5, 5,
	  1, 5, 8, 7};
	float values_b[16] = 
	{-6, 1, 5,
	  3, 0, 5,
	  1, 5, 7};

	a = matrix_from_array(4, values_a);
	b = matrix_from_array(3, values_b);
	a = matrix_submatrix(a, 1, 2);
	cr_expect(matrix_eq(a, b));
}

Test(matrix, minor) {

	t_matrix a;
	t_matrix b;
	float	ret; 
	float	expec;

	float values_a[16] = 
	{ 3, 5, 0,
	  2, -1, -7,
	  6, -1, 5 };
	float values_b[16] = 
	{ 5, 0,
	  -1, 5 };
	a = matrix_from_array(3, values_a);
	b = matrix_from_array(2, values_b);
	ret = matrix_minor(a, 1, 0);
	expec = 25;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
	a = matrix_submatrix(a, 1, 0);
	cr_expect(matrix_eq(a, b));
}

Test(matrix, cofactors) {
	
	t_matrix a;
	float	ret; 
	float	expec;

	float values_a[16] = 
	{ 3, 5, 0,
	  2, -1, -7,
	  6, -1, 5 };

	a = matrix_from_array(3, values_a);
	
	ret = matrix_minor(a, 0, 0);
	expec = -12;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);

	ret = matrix_cofactor(a, 0, 0);
	expec = -12;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);

	ret = matrix_minor(a, 1, 0);
	expec = 25;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);

	ret = matrix_cofactor(a, 1, 0);
	expec = -25;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
}

Test(matrix, determinant_3x3) {

	t_matrix a;
	float	ret; 
	float	expec;

	float values_a[16] = 
	{ 1, 2, 6,
	 -5, 8,-4,
	  2, 6, 4 };

	a = matrix_from_array(3, values_a);
	
	ret = matrix_cofactor(a, 0, 0);
	expec = 56;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);

	ret = matrix_cofactor(a, 0, 1);
	expec = 12;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);

	ret = matrix_cofactor(a, 0, 2);
	expec = -46;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);

	ret = matrix_determinant(a);
	expec = -196;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
}

Test(matrix, determinant_4x4) {

	t_matrix a;
	float	ret; 
	float	expec;

	float values_a[16] = 
	{ -2,-8, 3, 5,
	  -3, 1, 7, 3,
	   1, 2,-9, 6,
	  -6, 7, 7,-9 };

	a = matrix_from_array(4, values_a);
	
	ret = matrix_cofactor(a, 0, 0);
	expec = 690;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);

	ret = matrix_cofactor(a, 0, 1);
	expec = 447;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);

	ret = matrix_cofactor(a, 0, 2);
	expec = 210;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);

	ret = matrix_cofactor(a, 0, 3);
	expec = 51;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
	
	ret = matrix_determinant(a);
	expec = -4071;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
}

Test(matrix, is_invertible) {
	
	t_matrix a;
	float	ret; 
	float	expec;

	float values_a[16] = 
	{  6, 4, 4, 4,
	   5, 5, 7, 6,
	   4,-9, 3,-7,
	   9, 1, 7,-6 };

	a = matrix_from_array(4, values_a);

	ret = matrix_determinant(a);
	expec = -2120;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
	
	ret = matrix_is_invertible(a);
	expec = 1;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
}

Test(matrix, non_invertible) {
	
	t_matrix a;
	float	ret; 
	float	expec;

	float values_a[16] = 
	{ -4, 2,-2,-3,
	   9, 6, 2, 6,
	   0,-5, 1,-5,
	   0, 0, 0, 0 };

	a = matrix_from_array(4, values_a);

	ret = matrix_determinant(a);
	expec = 0;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
	
	ret = matrix_is_invertible(a);
	expec = 0;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
}

Test(matrix, inverse) {
	
	t_matrix a;
	t_matrix b;
	t_matrix inverse;
	float	ret; 
	float	expec;

	float values_a[16] = 
	{ -5, 2, 6,-8,
	   1,-5, 1, 8,
	   7, 7,-6,-7,
	   1,-3, 7, 4 };
	float values_b[16] = 
	{ 0.21805, 0.45113, 0.24060,-0.04511,
	 -0.80827,-1.45677,-0.44361, 0.52068,
	 -0.07895,-0.22368,-0.05263, 0.19737,
	 -0.52256,-0.81391,-0.30075, 0.30639 };

	a = matrix_from_array(4, values_a);
	b = matrix_from_array(4, values_b);

	ret = matrix_determinant(a);
	expec = 532;
	cr_expect(float_eq(ret, expec) == true, "Expected: %f, Returned: %f", expec, ret);
	
	inverse = matrix_inverse(a);
	b = matrix_identity(4);
	a = matrix_matrix_mult(a, inverse);
	cr_expect(matrix_eq(a, b));
}
