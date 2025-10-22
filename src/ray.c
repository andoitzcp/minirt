#include "minirt.h"

t_ray ray_new(t_tuple origin, t_tuple direction)
{
    t_ray r;

    r.o = origin;
    r.d = direction;
    r.i = NULL;
    return (r);
}

t_tuple position(t_ray ray, float t)
{
    t_tuple pret;

    pret = tuple_scale_up(ray.d, t);
    pret = tuple_add(pret, ray.o);
    return (pret);
}
