#include "test.h"
#include <math.h>

Test(camera, creation)
{
    int hsize;
    int vsize;
    float fov;
    t_camera c;

    hsize = 160;
    vsize = 120;
    fov = M_PI_2;

    c = new_camera(hsize, vsize, fov);
    cr_expect(c.hsize = hsize);
    cr_expect(c.vsize = vsize);
    cr_expect(c.fov = fov);
    cr_expect(matrix_eq(c.trans, matrix_identity(4)));
}


Test(camera, canvas_horizontal)
{
    t_camera c;

    c = new_camera(200, 125, M_PI_2);
    cr_expect(float_eq(c.pix_sz, 0.01), "%f vs %f", c.pix_sz, 0.01);
}

Test(camera, canvas_vertical)
{
    t_camera c;

    c = new_camera(125, 200, M_PI_2);
    cr_expect(float_eq(c.pix_sz, 0.01), "%f vs %f", c.pix_sz, 0.01);
}

Test(camera, ray_canvas_center)
{
    t_camera c;
    t_ray r;

    c = new_camera(201, 101, M_PI_2);
    r = ray_for_pixel(c, 100 , 50);
    cr_expect(tuple_eq(r.o, tuple_point(0, 0, 0)));
    cr_expect(tuple_eq(r.d, tuple_vector(0, 0, -1)));
}

Test(camera, ray_canvas_corner)
{
    t_camera c;
    t_ray r;

    c = new_camera(201, 101, M_PI_2);
    r = ray_for_pixel(c, 0 , 0);
    cr_expect(tuple_eq(r.o, tuple_point(0, 0, 0)));
    cr_expect(tuple_eq(r.d, tuple_vector(0.66519, 0.33259, -0.66851)));
}

Test(camera, ray_canvas_camera_transformed)
{
    t_camera c;
    t_ray r;

    c = new_camera(201, 101, M_PI_2);
    c.trans = matrix_matrix_mult(matrix_rot_y(45), matrix_translation(0, -2, 5));
    r = ray_for_pixel(c, 100 , 50);
    cr_expect(tuple_eq(r.o, tuple_point(0, 2, -5)));
    cr_expect(tuple_eq(r.d, tuple_vector(sqrtf(2)/2, 0.0, -sqrtf(2)/2)));
}

Test(camera, render)
{
    t_world w;
    t_camera c;
    t_tuple from;
    t_tuple to;
    t_tuple up;
    t_canvas *image;
    t_color pix;


    w = def_world();
    c = new_camera(11, 11, M_PI_2);
    from = tuple_point(0, 0, -5);
    to = tuple_point(0, 0, 0);
    up = tuple_vector(0, 1, 0);
    c.trans = view_transform(from, to, up);
    image = render(c, w);
    pix = canvas_get_pixel(*image, 5, 5);
    cr_expect(float_eq(pix.r, 0.38066), "%f vs %f\n", pix.r, 0.38066);
    cr_expect(float_eq(pix.g, 0.47583), "%f vs %f\n", pix.g, 0.47583);
    cr_expect(float_eq(pix.b, 0.2855), "%f vs %f\n", pix.b, 0.2855);
}
