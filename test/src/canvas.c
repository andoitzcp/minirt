#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

void expect_color_eq(t_color a, t_color b, char *flag, int i) {
	cr_expect(float_eq(a.r, b.r), "%s %i: expected r:%f, returned r:%f.", flag, i, b.r, a.r);
	cr_expect(float_eq(a.g, b.g), "%s %i: expected g:%f, returned g:%f.", flag, i, b.g, a.g);
	cr_expect(float_eq(a.b, b.b), "%s %i: expected b:%f, returned b:%f.", flag, i, b.b, a.b);
}

Test(canvas, init) {
	char	*flag = "canvas_init";
	int		i = 1;

	t_canvas	*can;
	t_color		color = color_set(0, 0, 0);

	can = canvas_init(0, 1);
	cr_expect(can == NULL, "%s %i: expected: %p, returned: %p\n", flag, i++, NULL, can);
	
	can = canvas_init(1, 0);
	cr_expect(can == NULL, "%s %i: expected: %p, returned: %p\n", flag, i++, NULL, can);
	
	can = canvas_init(10, 10);
	cr_expect(can != NULL, "%s %i: canvas ptr is NULL when it should not\n", flag, i++);
	cr_expect(can->width == 10, "%s %i: expected: %i, returned: %i\n", flag, i++, 10, can->width);
	cr_expect(can->height == 10, "%s %i: expected: %i, returned: %i\n", flag, i++, 10, can->height);
	expect_color_eq(can->image[0][0], color, flag, i++);
	expect_color_eq(can->image[9][9], color, flag, i++);
}

Test(canvas, set_color) {
	char	*flag = "canvas_set_color";
	int		i = 1;

	t_canvas	*can;
	t_color		color = color_set(0, 0, 0);

	can = canvas_init(10, 10);
	expect_color_eq(can->image[0][0], color, flag, i++);
	expect_color_eq(can->image[9][9], color, flag, i++);
	color = color_set(255, 255, 255);
	canvas_set_color(can, color);
	expect_color_eq(can->image[0][0], color, flag, i++);
	expect_color_eq(can->image[9][9], color, flag, i++);
}

Test(canvas, canvas_set_pixel) {
	char	*flag = "canvas_set_pixel";
	int		i = 1;

	t_canvas	*can;
	t_color		color = color_set(0, 0, 0);

	can = canvas_init(10, 10);
	expect_color_eq(can->image[5][5], color, flag, i++);
	color = color_set(255, 0, 0);
	canvas_set_pixel(can, 5, 5, color);
	expect_color_eq(can->image[5][5], color, flag, i++);
	// expect_color_eq(can->image[1][5], color, flag, i++);
}

Test(canvas, canvas_get_pixel) {
	char	*flag = "canvas_get_pixel";
	int		i = 1;

	t_canvas	*can;
	t_color		color = color_set(0, 0, 0);
	t_color		pixel;

	can = canvas_init(10, 10);
	pixel = canvas_get_pixel(*can, 5, 5);
	expect_color_eq(pixel, color, flag, i++);
	color = color_set(255, 0, 0);
	canvas_set_pixel(can, 5, 5, color);
	pixel = canvas_get_pixel(*can, 5, 5);
	expect_color_eq(pixel, color, flag, i++);
	// pixel = canvas_get_pixel(*can, 1, 5);
	// expect_color_eq(pixel, color, flag, i++);
}

Test(canvas, to_ppm) {
	char	*flag = "canvas_to_ppm";
	int		i = 1;

	t_canvas	*can;
	t_color		color = color_set(0, 0, 0);
	t_color		pixel;

	int	ret;
	int	expec;

	can = canvas_init(20, 20);

	ret = canvas_to_ppm(*can, NULL);
	cr_expect(ret == 1, "%s %i: expected: %i, returned: %i\n", flag, i++, 1, ret);
	
	ret = canvas_to_ppm(*can, "");
	cr_expect(ret == 1, "%s %i: expected: %i, returned: %i\n", flag, i++, 1, ret);

	ret = canvas_to_ppm(*can, "ppm");
	cr_expect(ret == 0, "%s %i: expected: %i, returned: %i\n", flag, i++, 0, ret);

	canvas_set_pixel(can, 9, 9, color_set(255,255,255));
	ret = canvas_to_ppm(*can, "ppm");
	cr_expect(ret == 0, "%s %i: expected: %i, returned: %i\n", flag, i++, 0, ret);
}
