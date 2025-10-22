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

void calc_ray_sp_intersects(float *array, t_ray *ray, t_sphere *sp)
{
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
        array[0] = 0;
        array[1] = 0;
        array[2] = 0;
    }
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

t_intersects *new_intersect(t_elements *el, float i)
{
    t_intersects *node;

    node = malloc(sizeof(t_intersects));
    if (node == NULL)
        return (NULL);
    node->el = el;
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

void get_ray_el_intersects(t_ray *ray, t_elements *el)
{
    int i;
    float array[3];
    t_intersects *node;

    if (el->type == ELID_SP)
        calc_ray_sp_intersects(array, ray, &(el->elda.sp));
    if (el->type == ELID_PL)
        calc_ray_pl_intersects(array, ray, &(el->elda.pl));
    if (el->type == ELID_CY)
        calc_ray_cy_intersects(array, ray, &(el->elda.cy));
    i = 0;
    while (i++ < (int)array[0])
    {
        node = new_intersect(el, array[i]);
        insert_ray_intersect(&(ray->i), node);
    }
    return ;

}
