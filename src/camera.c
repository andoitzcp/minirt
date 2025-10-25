#include "minirt.h"

t_camera new_camera(t_tuple point, t_tuple vector, float fov)
{
    t_camera camera;

    camera.p = point;
    camera.v = vector;
    camera.fov = fov;
    return (camera);
}

t_camera convert_camera_from_raw(t_raw_camera raw_camera)
{
    t_camera camera;

    camera.p = raw_camera.p;
    camera.v = raw_camera.v;
    camera.fov = raw_camera.fov / 180;
    return (camera);
}

t_camera default_camera(void)
{
    t_camera camera;

    camera.p = tuple_point(0, 0, 0);
    camera.v = tuple_vector(0, 0, 1);
    camera.fov = 180;
    return (camera);
}
