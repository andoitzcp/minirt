#include "minirt.h"

// TODO Implement funtion to take raw data plane and convert it into matrix
// and material and set plane data
t_object *new_plane_from_raw_data(t_raw_plane *rpl, t_amblight *ambl)
{
    t_matrix trans;
    t_material mat;

    trans = matrix_translation(rpl->p.x, rpl->p.y, rpl->p.z);
    // put here rotations
    //trans = matrix_matrix_mult(trans, )
    mat = new_material_from_raw_data(&rpl->col, ambl);
    return (new_object(ELID_PL, &trans, &mat));
}
