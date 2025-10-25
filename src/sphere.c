#include "minirt.h"

t_sphere new_sphere(void)
{
    t_sphere sp;

    sp.p = tuple_point(0, 0, 0);
    sp.dia = 1;
    sp.mat = default_material();
    sp.t = matrix_identity(4);
    return (sp);
}

// TODO Implement funtion to take raw data plane and convert it into matrix
// and material and set plane data
void set_sphere_from_raw_data(t_sphere *sp, t_raw_sphere *rsp)
{
    (void)sp;
    (void)rsp;
    return ;
}
