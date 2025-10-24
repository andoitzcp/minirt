#include "minirt.h"

t_ray transform(t_ray r, t_matrix m)
{
    t_ray rret;

    rret.o = matrix_tuple_mult(m, r.o);
    rret.d = matrix_tuple_mult(m, r.d);
    return (rret);
}

void set_transform(t_elements *el, t_matrix m)
{
    if (el->type == ELID_SP)
        el->elda.sp.t = m;
    else if (el->type == ELID_PL)
        el->elda.pl.t = m;
    else if (el->type == ELID_CY)
        el->elda.cy.t = m;
    return ;
}
