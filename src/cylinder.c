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

// TODO move to liblinmath
t_matrix matrix_from_tuples(t_tuple x, t_tuple y, t_tuple z)
{
	t_matrix	m;

	m = matrix_zero();
	m.value[0][0] = x.x;
	m.value[1][0] = x.y;
	m.value[2][0] = x.z;
	m.value[0][1] = y.x;
	m.value[1][1] = y.y;
	m.value[2][1] = y.z;
	m.value[0][2] = z.x;
	m.value[1][2] = z.y;
	m.value[2][2] = z.z;
	m.value[3][3] = 1;
	return (m);
}

// TODO get matrix rotation from a source and destiny vector
// TODO move to liblinmath
t_matrix matrix_rotation(t_tuple dest)
{
	t_matrix	r;
	t_tuple		tmp;
	t_tuple		xp;
	t_tuple		yp;
	t_tuple		zp;

	dest = tuple_normalize(dest);
	yp = dest;
	if (fabs(dest.y) < 0.9)
		tmp = tuple_vector(0, 1, 0);
	else
		tmp = tuple_vector(1, 0, 0);
	xp = tuple_cross(tmp, yp);
	xp = tuple_normalize(xp);
	zp = tuple_cross(yp, xp);
	zp = tuple_normalize(zp);
	r = matrix_from_tuples(xp, yp, zp);
	return (r);
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
