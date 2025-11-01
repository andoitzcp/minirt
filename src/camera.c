#include "minirt.h"

t_camera new_camera_old(t_tuple point, t_tuple vector, float fov)
{
    t_camera camera;

    camera.p = point;
    camera.v = vector;
    camera.fov = fov;
    return (camera);
}

t_camera new_camera(int hsize, int vsize, float fov)
{
    t_camera camera;

    camera.hsize = hsize;
    camera.vsize = vsize;
    camera.fov = fov;
    camera.trans = matrix_identity(4);
    camera_comps(&camera);
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

t_camera def_camera(void)
{
    t_camera camera;

    camera.p = tuple_point(0, 0, 0);
    camera.v = tuple_vector(0, 0, 1);
    camera.fov = 180;
    return (camera);
}

void camera_comps(t_camera *camera)
{
    float half_view;
    float aspect;

    half_view = tan((float)camera->fov / 2);
    aspect = (float)camera->hsize / camera->vsize;
    if (aspect >= 1)
    {
        camera->half_width = half_view;
        camera->half_height = half_view / aspect;
    }
    else
    {
        camera->half_width = half_view * aspect;
        camera->half_height = half_view;
    }
    camera->pix_sz = (camera->half_width * 2) / camera->hsize;
}
