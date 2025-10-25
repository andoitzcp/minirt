#include "minirt.h"

t_object *new_object(int type, t_matrix transform, t_material material)
{
    t_object *obj;

    obj = malloc(sizeof(t_object));
    if (obj == NULL)
        return (NULL);
    obj->type = type;
    if (type == ELID_SP)
        obj->data.sp = new_sphere();
    if (type == ELID_PL)
        obj->data.pl = new_plane();
    if (type == ELID_CY)
        obj->data.cy = new_cylinder();
    set_transform(obj, transform);
    set_material(obj, material);
    obj->next = NULL;
    return (obj);
}

void object_append(t_object **head, t_object *node)
{
    t_object *current;

    if (*head == NULL)
    {
        *head = node;
        return ;
    }
    current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = node;
    return ;
}
