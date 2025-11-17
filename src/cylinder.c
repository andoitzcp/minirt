#include "minirt.h"

t_cylinder	def_cylinder(void)
{
	t_cylinder	cy;

	cy.dia = 1;
	cy.hei = 1;
	cy.axis = tuple_vector(0, 1, 0);
	cy.intersect = NULL;
	cy.normal_at = NULL;
	return (cy);
}

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
    t_matrix t;
	t_matrix s;
    t_matrix r;
    t_matrix trans;
    t_material mat;

    t = matrix_translation(rcy->p.x, rcy->p.y, rcy->p.z);
	r = matrix_rotation(rcy->v);
    s = matrix_scalation(rcy->dia, rcy->hei / 2, rcy->dia);
	trans = matrix_matrix_mult(t, r);
	trans = matrix_matrix_mult(trans, s);
    mat = new_material_from_raw_data(&rcy->col, ambl);
    return (new_object(ELID_CY, &trans, &mat));
}
