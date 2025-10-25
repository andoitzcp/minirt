#include "minirt.h"

// TODO Implement new_plane NOT FINISHED
t_plane new_plane(void)
{
    t_plane pl;

    pl.p = tuple_point(0, 0, 0);
    pl.v = tuple_vector(0, 0, 0);
    pl.col = color_set(0, 0, 0);
    return (pl);
}

// TODO Implement new_cylinder NOT FINISHED
t_cylinder new_cylinder(void)
{
    t_cylinder cy;

    cy.p = tuple_point(0, 0, 0);
    cy.v = tuple_vector(0, 0, 0);
    cy.dia = 1;
    cy.hei = 1;
    cy.col = color_set(0, 0, 0);
    return (cy);
}
