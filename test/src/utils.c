#include "test.h"

void expect_tuple_eq(t_tuple a, t_tuple b){
	cr_expect(float_eq(a.x, b.x), ": expected x:%f, returned x:%f.", b.x, a.x);
	cr_expect(float_eq(a.y, b.y), ": expected y:%f, returned y:%f.", b.y, a.y);
	cr_expect(float_eq(a.z, b.z), ": expected z:%f, returned z:%f.", b.z, a.z);
	cr_expect(float_eq(a.w, b.w), ": expected w:%f, returned w:%f.", b.w, a.w);
}

void assert_tuple_eq(t_tuple a, t_tuple b) {
	cr_assert(float_eq(a.x, b.x), ": expected x:%f, returned x:%f.", b.x, a.x);
	cr_assert(float_eq(a.y, b.y), ": expected y:%f, returned y:%f.", b.y, a.y);
	cr_assert(float_eq(a.z, b.z), ": expected z:%f, returned z:%f.", b.z, a.z);
	cr_assert(float_eq(a.w, b.w), ": expected w:%f, returned w:%f.", b.w, a.w);
}

void expect_tuples_is_nan(t_tuple a) {
	cr_expect(isnan(a.x), ": expected x:%f, returned x:%f.", NAN, a.x);
	cr_expect(isnan(a.y), ": expected x:%f, returned x:%f.", NAN, a.y);
	cr_expect(isnan(a.z), ": expected x:%f, returned x:%f.", NAN, a.z);
	cr_expect(isnan(a.w), ": expected x:%f, returned x:%f.", NAN, a.w);
}

void expect_color_eq(t_color a, t_color b, char *flag, int i) {
	cr_expect(float_eq(a.r, b.r), "%s %i: expected r:%f, returned r:%f.", flag, i, b.r, a.r);
	cr_expect(float_eq(a.g, b.g), "%s %i: expected g:%f, returned g:%f.", flag, i, b.g, a.g);
	cr_expect(float_eq(a.b, b.b), "%s %i: expected b:%f, returned b:%f.", flag, i, b.b, a.b);
}

void expect_color_is_nan(t_color a,char *flag, int i) {
	cr_expect(isnan(a.r), "%s %i: expected r:%f, returned r:%f.", flag, i, NAN, a.r);
	cr_expect(isnan(a.g), "%s %i: expected g:%f, returned g:%f.", flag, i, NAN, a.g);
	cr_expect(isnan(a.b), "%s %i: expected b:%f, returned b:%f.", flag, i, NAN, a.b);
}
