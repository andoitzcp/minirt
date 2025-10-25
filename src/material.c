#include "minirt.h"

//TODO TEMPORAL Replace when shadows branch is merged
t_material default_material(void)
{
    t_material m;

    m.color = color_set(1, 1, 1);
    m.ambient = 1;
    m.diffuse = 1;
    m.shininess = 1;
    m.specular = 1;
    return (m);
}

//TODO IF NOT EXIST when shadows branch merge keep it
void set_material(t_object *object, t_material material)
{
    if (object->type == ELID_SP)
        object->data.sp.mat = material;
    else if (object->type == ELID_PL)
        object->data.pl.mat = material;
    else if (object->type == ELID_CY)
        object->data.cy.mat = material;
    return ;
}
