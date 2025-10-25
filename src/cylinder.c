#include "minirt.h"

// TODO Implement new_cylinder NOT FINISHED
t_cylinder new_cylinder(void)
{
    t_cylinder cy;

    cy.p = tuple_point(0, 0, 0);
    cy.v = tuple_vector(0, 0, 0);
    cy.dia = 1;
    cy.hei = 1;
    cy.mat = default_material();
    cy.t = matrix_identity(4);
    return (cy);
}

// TODO Implement funtion to take raw data cylinder and convert it into matrix
// and material and set cylinder data
void set_cylinder_from_raw_data(t_cylinder *cy, t_raw_cylinder *rcy)
{
    (void)cy;
    (void)rcy;
    return ;
}
