#include "minirt.h"

static void swap(float *a, float *b)
{
    float c;

    c = *a;
    *a = *b;
    *b = c;
    return ;
}

t_intersect_old intersect_sp_old(t_ray *ray, t_sphere *sp)
{
    t_intersect_old xs;
    t_tuple sp_to_ray;
    float dotp[3];
    float dis;

    sp_to_ray = tuple_sub(ray->o, sp->p);
    dotp[0] = tuple_dot(ray->d, ray->d);
    dotp[1] = 2 * tuple_dot(ray->d, sp_to_ray);
    dotp[2] = tuple_dot(sp_to_ray, sp_to_ray) - 1;
    dis = powf(dotp[1], 2) -4 * dotp[0] * dotp[2];
    if (dis < 0)
    {
        xs.q = 0;
        xs.i[0] = 0;
        xs.i[1] = 0;
    }
    else
    {
        xs.q = 2;
        xs.i[0] = (-dotp[1] - sqrtf(dis)) / (2 * dotp[0]);
        xs.i[1] = (-dotp[1] + sqrtf(dis)) / (2 * dotp[0]);
    }
    if (xs.i[0] > xs.i[1])
        swap(&(xs.i[0]), &(xs.i[1]));
    return (xs);
}

//TODO modify interst_sp_old to
