#ifndef TEST_H
#define TEST_H

#include "../../inc/liblinmath/src/linmath.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>


void expect_tuple_eq(t_tuple a, t_tuple b);
void assert_tuple_eq(t_tuple a, t_tuple b);
void expect_tuples_is_nan(t_tuple a);
void expect_color_eq(t_color a, t_color b, char *flag, int i);
void expect_color_is_nan(t_color a,char *flag, int i);

#endif 
