#include "minirt.h"

// TODO Implement new_plane NOT FINISHED
t_plane new_plane(void)
{
    t_plane pl;

    pl.p = tuple_point(0, 0, 0);
    pl.v = tuple_vector(0, 0, 0);
    pl.mat = def_material();
    pl.t = matrix_identity(4);
    return (pl);
}

// TODO Implement funtion to take raw data plane and convert it into matrix
// and material and set plane data
void set_plane_from_raw_data(t_plane *pl, t_raw_plane *rpl)
{
    (void)pl;
    (void)rpl;
    return ;
}

t_tuple	plane_normal_at(t_plane plane, t_tuple point)
{
    t_tuple tret;

    (void)plane;
    (void)point;
    tret = tuple_point(0, 0, 0); //temporary
    return (tret);
}
