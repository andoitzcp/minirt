/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:45:05 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/22 20:30:32 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINMATH_H
# define LINMATH_H
# include <math.h>

// Constants
# define EPS 1e-6f

// Float utils
int		float_eq(float a, float b);
float	float_limit(float n, float min, float max);

// Angle utils
float	degrees_to_radians(float deg);

// Tuples: points and vectors
typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

t_tuple	tuple_set(float x, float y, float z, float w);
float	*tuple_to_array(t_tuple t, float ar[4]);
int		tuple_eq(t_tuple a, t_tuple b);

t_tuple	tuple_point(float x, float y, float z);
t_tuple	tuple_vector(float x, float y, float z);
int		tuple_is_point(t_tuple t);
int		tuple_is_vector(t_tuple t);

t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_sub(t_tuple a, t_tuple b);
t_tuple	tuple_scale_up(t_tuple v, float n);
t_tuple	tuple_scale_down(t_tuple v, float n);
t_tuple	tuple_negate(t_tuple v);

float	tuple_magnitude(t_tuple v);
t_tuple	tuple_normalize(t_tuple v);
float	tuple_dot(t_tuple a, t_tuple b);
t_tuple	tuple_cross(t_tuple a, t_tuple b);

// Matrices
typedef struct s_matrix {
	int	size;
	float value[4][4];
} t_matrix;

t_matrix	matrix_zero(void);
t_matrix	matrix_identity(int size);
t_matrix	matrix_from_array(int size, float array[16]);
t_matrix	matrix_inverse(t_matrix m);

t_matrix	matrix_matrix_mult(t_matrix a, t_matrix b);
t_tuple		matrix_tuple_mult(t_matrix m, t_tuple t);
t_matrix	matrix_transpose(t_matrix m);
float		matrix_determinant(t_matrix m);

t_matrix	matrix_submatrix(t_matrix m, int row, int col);
float		matrix_minor(t_matrix m, int row, int col);
float		matrix_cofactor(t_matrix m, int row, int col);

t_matrix	matrix_translation(float x, float y, float z);
t_matrix	matrix_scalation(float x, float y, float z);
t_matrix	matrix_shearing(float props[6]);

t_matrix	matrix_rot_x(float angle);
t_matrix	matrix_rot_y(float angle);
t_matrix	matrix_rot_z(float angle);

int			matrix_eq(t_matrix a, t_matrix b);
void		matrix_fill_limits(t_matrix *m, float value);
int			matrix_is_invertible(t_matrix m);

#endif 
