#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <math.h>
#include "../../src/minirt.h"

/* void expect_color_eq(t_color a, t_color b, char *flag, int i) { */
/* 	cr_expect(float_eq(a.r, b.r), "%s %i: expected r:%f, returned r:%f.", flag, i, b.r, a.r); */
/* 	cr_expect(float_eq(a.g, b.g), "%s %i: expected g:%f, returned g:%f.", flag, i, b.g, a.g); */
/* 	cr_expect(float_eq(a.b, b.b), "%s %i: expected b:%f, returned b:%f.", flag, i, b.b, a.b); */
/* } */

/* void assert_color_eq(t_color a, t_color b, char *flag, int i) { */
/* 	cr_assert(float_eq(a.r, b.r), "%s %i: expected r:%f, returned r:%f.", flag, i, b.r, a.r); */
/* 	cr_assert(float_eq(a.g, b.g), "%s %i: expected g:%f, returned g:%f.", flag, i, b.g, a.g); */
/* 	cr_assert(float_eq(a.b, b.b), "%s %i: expected b:%f, returned b:%f.", flag, i, b.b, a.b); */
/* } */

/* void expect_color_is_nan(t_color a,char *flag, int i) { */
/* 	cr_expect(isnan(a.r), "%s %i: expected r:%f, returned r:%f.", flag, i, NAN, a.r); */
/* 	cr_expect(isnan(a.g), "%s %i: expected g:%f, returned g:%f.", flag, i, NAN, a.g); */
/* 	cr_expect(isnan(a.b), "%s %i: expected b:%f, returned b:%f.", flag, i, NAN, a.b); */
/* } */

/* Test(color, set) { */
/* 	char	*flag = "color_set"; */
/* 	int		i = 1; */

/* 	t_color c; */
/* 	float ret; */
/* 	float expec; */

/* 	c = color_set(0,0,0); */
/* 	ret = c.r; */
/* 	expec = 0; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* 	ret = c.g; */
/* 	expec = 0; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* 	ret = c.b; */
/* 	expec = 0; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */

/* 	c = color_set(50,100,150); */
/* 	ret = c.r; */
/* 	expec = 50; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* 	ret = c.g; */
/* 	expec = 100; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* 	ret = c.b; */
/* 	expec = 150; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* } */

/* Test(color, limit) { */
/* 	char	*flag = "color_limit"; */
/* 	int		i = 1; */

/* 	t_color c; */
/* 	float ret; */
/* 	float expec; */

/* 	c.r = 50; */
/* 	c.g = 100; */
/* 	c.b = 150; */
/* 	c = color_limit(c); */
/* 	ret = c.r; */
/* 	expec = 50; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* 	ret = c.g; */
/* 	expec = 100; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* 	ret = c.b; */
/* 	expec = 150; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */

/* 	c.r = -INFINITY; */
/* 	c.g = INFINITY; */
/* 	c.b = NAN; */
/* 	c = color_limit(c); */
/* 	ret = c.r; */
/* 	expec = 0; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* 	ret = c.g; */
/* 	expec = 255; */
/* 	cr_expect(ret == expec, "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* 	ret = c.b; */
/* 	expec = NAN; */
/* 	cr_expect(isnan(ret), "%s %i: Returned: %f, Expected: %f\n", flag, i++, ret, expec); */
/* } */

/* Test(color, clamp) { */
/* 	char	*flag = "color_clamp"; */
/* 	int		i = 1; */

/* 	t_color a; */
/* 	t_color b; */

/* 	a = color_set(1, 0.5, 0); */
/* 	a = color_clamp(a); */
/* 	b = color_set(255, 128, 0); */
/* 	expect_color_eq(a,b, flag, i++); */

/* 	a = color_set(-1, 0.25, 0.75); */
/* 	a = color_clamp(a); */
/* 	b = color_set(0, 64, 191); */
/* 	expect_color_eq(a,b, flag, i++); */
/* } */

/* Test(color, add) { */
/* 	char	*flag = "color_add"; */
/* 	int		i = 1; */

/* 	t_color a; */
/* 	t_color b; */

/* 	a = color_set(120, 50, 80); */
/* 	b = color_set(100, 100, 100); */
/* 	a = color_add(a, b); */
/* 	b = color_set(220, 150, 180); */
/* 	expect_color_eq(a,b, flag, i++); */

/* 	a = color_set(120, 50, 80); */
/* 	b = color_set(-200, -200, -200); */
/* 	a = color_add(a, b); */
/* 	b = color_set(-80, -150, -120); */
/* 	expect_color_eq(a,b, flag, i++); */
/* } */

/* Test(color, sub) { */
/* 	char	*flag = "color_sub"; */
/* 	int		i = 1; */

/* 	t_color a; */
/* 	t_color b; */

/* 	a = color_set(120, 50, 80); */
/* 	b = color_set(100, 100, 100); */
/* 	a = color_sub(a, b); */
/* 	b = color_set(20, -50, -20); */
/* 	expect_color_eq(a,b, flag, i++); */

/* 	a = color_set(120, 50, 80); */
/* 	b = color_set(-200, -200, -200); */
/* 	a = color_sub(a, b); */
/* 	b = color_set(320, 250, 280); */
/* 	expect_color_eq(a,b, flag, i++); */
/* } */

/* Test(color, scale_up) { */
/* 	char	*flag = "color_scale_up"; */
/* 	int		i = 1; */

/* 	t_color a; */
/* 	t_color b; */
/* 	float n; */

/* 	a = color_set(120, 50, 80); */
/* 	n = 2; */
/* 	a = color_scale_up(a, n); */
/* 	b = color_set(240, 100, 160); */
/* 	expect_color_eq(a,b, flag, i++); */

/* 	a = color_set(120, 50, 80); */
/* 	n = 0.5; */
/* 	a = color_scale_up(a, n); */
/* 	b = color_set(60, 25, 40); */
/* 	expect_color_eq(a,b, flag, i++); */
/* } */

/* Test(color, scale_down) { */
/* 	char	*flag = "color_scale_down"; */
/* 	int		i = 1; */

/* 	t_color a; */
/* 	t_color b; */
/* 	float n; */

/* 	a = color_set(120, 50, 80); */
/* 	n = 2; */
/* 	a = color_scale_down(a, n); */
/* 	b = color_set(60, 25, 40); */
/* 	expect_color_eq(a,b, flag, i++); */

/* 	a = color_set(120, 50, 80); */
/* 	n = 0.5; */
/* 	a = color_scale_down(a, n); */
/* 	b = color_set(240, 100, 160); */
/* 	expect_color_eq(a,b, flag, i++); */

/* 	a = color_set(120, 50, 80); */
/* 	n = 0; */
/* 	a = color_scale_down(a, n); */
/* 	expect_color_is_nan(a, flag, i++); */
/* } */

/* Test(color, blend) { */
/* 	char	*flag = "color_blend"; */
/* 	int		i = 1; */

/* 	t_color a; */
/* 	t_color b; */

/* 	a = color_set(120, 50, 80); */
/* 	b = color_set(2, 3, 0.5); */
/* 	a = color_blend(a, b); */
/* 	b = color_set(240, 150, 40); */
/* 	expect_color_eq(a,b, flag, i++); */

/* 	a = color_set(120, 50, 80); */
/* 	b = color_set(-2, -3, -0.5); */
/* 	a = color_blend(a, b); */
/* 	b = color_set(-240, -150, -40); */
/* 	expect_color_eq(a,b, flag, i++); */
/* } */
