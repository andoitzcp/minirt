#include "minirt.h"

// TODO Implement new_cylinder NOT FINISHED
t_cylinder new_cylinder(void)
{
    t_cylinder cy;

    cy.dia = 1;
    cy.hei = 1;
    return (cy);
}

// TODO Implement funtion to take raw data cylinder and convert it into matrix
// and material and set cylinder data
t_object *new_cylinder_from_raw_data(t_raw_cylinder *rcy, t_amblight *ambl)
{
    t_matrix trans;
    t_material mat;

    trans = matrix_translation(rcy->p.x, rcy->p.y, rcy->p.z);
    // put here rotations
    //trans = matrix_matrix_mult(trans, )
    trans = matrix_matrix_mult(trans,
                               matrix_scalation(rcy->dia,
                                                rcy->hei / 2,
                                                rcy->dia));
    mat = new_material_from_raw_data(&rcy->col, ambl);
    return (new_object(ELID_CY, &trans, &mat));
}
