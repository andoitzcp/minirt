#include "minirt.h"

static void swap(float *a, float *b)
{
    float c;

    c = *a;
    *a = *b;
    *b = c;
    return ;
}

static void bzero_array(float *array, size_t sz)
{
    size_t i;

    i = 0;
    while (i < sz)
        array[i++] = 0;
    return ;
}

void calc_ray_sp_intersects(float *array, t_ray *ray)
{
    t_tuple sp_to_ray;
    float dotp[3];
    float dis;

    sp_to_ray = tuple_sub(ray->o, tuple_point(0, 0, 0));
    dotp[0] = tuple_dot(ray->d, ray->d);
    dotp[1] = 2 * tuple_dot(ray->d, sp_to_ray);
    dotp[2] = tuple_dot(sp_to_ray, sp_to_ray) - 1;
    dis = powf(dotp[1], 2) -4 * dotp[0] * dotp[2];
    bzero_array(array, 3);
    if (dis < 0)
        return ;
    array[0] = 2;
    array[1] = (-dotp[1] - sqrtf(dis)) / (2 * dotp[0]);
    array[2] = (-dotp[1] + sqrtf(dis)) / (2 * dotp[0]);
    if (array[1] > array[2])
        swap(&(array[1]), &(array[2]));
    return ;
}

// TODO implement plane intersects
void calc_ray_pl_intersects(float *array, t_ray *ray)
{
    bzero_array(array, 3);
    if (fabs(ray->d.y) < EPS)
        return ;
    array[0] = 1;
    array[1] = -ray->o.y / ray->d.y;
    return ;
}

// TODO implement plane intersects
void calc_ray_cy_intersects(float *array, t_ray *ray)
{
    float abc[3];
    float disc;

    bzero_array(array, 3);
    abc[0] = powf(ray->d.x, 2) + powf(ray->d.z, 2);
    if (float_eq(abc[0], 0))
        return ;
    abc[1] = 2 *ray->o.x * ray->d.x + 2*ray->o.z * ray->d.z;
    abc[2] = powf(ray->o.x, 2) + powf(ray->o.z, 2) - 1;
    disc = powf(abc[1], 2) -4 * abc[0] * abc[2];
    printf("flag000 a: %f, b: %f, c: %f\n", abc[0], abc[1], abc[2]);
    printf("flag001 %f\n", disc);
    if (disc < 0)
        return ;
    printf("flag002\n");
    array[0] = 2;
    array[1] = (-abc[1] - sqrtf(disc)) / (2 * abc[0]);
    printf("flag0021 %f\n", array[1]);
    array[2] = (-abc[1] + sqrtf(disc)) / (2 * abc[0]);
    printf("flag0022 %f\n", array[2]);
}
