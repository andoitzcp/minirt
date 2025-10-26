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

void calc_ray_sp_intersects(float *array, t_ray *ray, t_sphere *sp)
{
    t_ray raytmp;
    t_tuple sp_to_ray;
    float dotp[3];
    float dis;

    raytmp = transform(*ray, matrix_inverse((*sp).trans));
    sp_to_ray = tuple_sub(raytmp.o, sp->p);
    dotp[0] = tuple_dot(raytmp.d, raytmp.d);
    dotp[1] = 2 * tuple_dot(raytmp.d, sp_to_ray);
    dotp[2] = tuple_dot(sp_to_ray, sp_to_ray) - 1;
    dis = powf(dotp[1], 2) -4 * dotp[0] * dotp[2];
    if (dis < 0)
        bzero_array(array, 3);
    else
    {
        array[0] = 2;
        array[1] = (-dotp[1] - sqrtf(dis)) / (2 * dotp[0]);
        array[2] = (-dotp[1] + sqrtf(dis)) / (2 * dotp[0]);
    }
    if (array[1] > array[2])
        swap(&(array[1]), &(array[2]));
}

// TODO implement plane intersects
void calc_ray_pl_intersects(float *array, t_ray *ray, t_plane *pl)
{
    (void)array;
    (void)ray;
    (void)pl;
}

// TODO implement plane intersects
void calc_ray_cy_intersects(float *array, t_ray *ray, t_cylinder *cy)
{
    (void)array;
    (void)ray;
    (void)cy;
}

t_intersects *new_intersect(t_object *obj, float i)
{
    t_intersects *node;

    node = malloc(sizeof(t_intersects));
    if (node == NULL)
        return (NULL);
    node->obj = obj;
    node->i = i;
    node->next = NULL;
    return (node);
}


void insert_ray_intersect(t_intersects **head, t_intersects *node)
{
    t_intersects *current;
    t_intersects *prev;

    current = *head;
    if (current == NULL)
    {
        *head = node;
        return ;
    }
    if (node->i < current->i)
    {
        node->next = current;
        *head = node;
        return ;
    }
    while (current != NULL)
    {
        if (current->i > node->i)
            break ;
        prev = current;
        current = current->next;
    }
    if (current != NULL)
        node->next = current;
    prev->next = node;
    return ;
}

void get_ray_el_intersects(t_ray *ray, t_object *obj)
{
    int i;
    float array[3];
    t_intersects *node;

    if (obj->type == ELID_SP)
        calc_ray_sp_intersects(array, ray, &(obj->data.sp));
    if (obj->type == ELID_PL)
        calc_ray_pl_intersects(array, ray, &(obj->data.pl));
    if (obj->type == ELID_CY)
        calc_ray_cy_intersects(array, ray, &(obj->data.cy));
    i = 0;
    while (i++ < (int)array[0])
    {
        node = new_intersect(obj, array[i]);
        insert_ray_intersect(&(ray->i), node);
    }
    return ;

}

float hit(t_intersects **head)
{
    t_intersects *current;

    current = *head;
    while (current != NULL)
    {
        if (current->i > 0)
            break ;
        current = current->next;
    }
    if (current != NULL)
        return (current->i);
    return (-1);
}
