# include "../../src/linmath.h"
# include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <math.h>
#include <stdio.h>

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

Test(Matrix, translation) {
	t_matrix a;
	t_matrix b;
	
	float values4[16] = 
	{1, 0, 0, 1,
	 0, 1, 0, 2,
	 0, 0, 1, 3,
	 0, 0, 0, 1};
	a = matrix_from_array(4, values4);
	b = matrix_translation(1, 2, 3);
	cr_expect(matrix_eq(a, b) == 1);
	
	float values5[16] = 
	{1, 0, 0, -1,
	 0, 1, 0, -2,
	 0, 0, 1, -3,
	 0, 0, 0, 1};
	a = matrix_from_array(4, values5);
	b = matrix_translation(-1, -2, -3);
	cr_expect(matrix_eq(a, b) == 1);
}

Test(Matrix, scalation) {
	t_matrix a;
	t_matrix b;
	
	float values4[16] = 
	{1, 0, 0, 0,
	 0, 2, 0, 0,
	 0, 0, 3, 0,
	 0, 0, 0, 1};
	a = matrix_from_array(4, values4);
	b = matrix_scalation(1, 2, 3);
	cr_expect(matrix_eq(a, b) == 1);
	
	float values5[16] = 
	{-1, 0, 0, 0,
	 0, -2, 0, 0,
	 0, 0, -3, 0,
	 0, 0, 0, 1};
	a = matrix_from_array(4, values5);
	b = matrix_scalation(-1, -2, -3);
	cr_expect(matrix_eq(a, b) == 1);
}
