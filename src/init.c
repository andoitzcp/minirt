#include "minirt.h"


static void init_re_element_types(t_data *data)
{
    size_t i;
    t_re ***re_array;

    re_array = data->raw.re_el_types;
    data->emf = data->emf | EMF_REET;
    re_array[ELID_A] = re_new(RE_EL_A);
    re_array[ELID_C] = re_new(RE_EL_C);
    re_array[ELID_L] = re_new(RE_EL_L);
    re_array[ELID_SP] = re_new(RE_EL_SP);
    re_array[ELID_PL] = re_new(RE_EL_PL);
    re_array[ELID_CY] = re_new(RE_EL_CY);
    re_array[ELID_BLANK_LINE] = re_new(RE_EL_BLANK);
    re_array[RE_TYPE_QTY] = NULL;
    i = 0;
    while (i < RE_TYPE_QTY)
    {
        if (re_array[i++] == NULL)
            ft_exit(data, ERRORS006);
    }
}

/* void init_element_array(t_data *data) */
/* { */
/*     uint i; */
/*     t_elements *els; */
/*     t_rawlines *rawl; */

/*     i = 0; */
/*     els = data->els; */
/*     rawl = *(data->rawl); */
/*     if (data->nels != get_element_qty(data->rawl)) */
/*         ft_exit(data, ERRORS004); */
/*     data->els = ft_calloc(data->nels, sizeof(t_elements)); */
/*     if (data->els == NULL) */
/*         ft_exit(data, ERRORS003); */
/*     //while (i < data->nels) */
/*         //init_element_node(&(data->els[i++])); */


/* } */

void init(t_data *data)
{
    init_re_element_types(data);
    data->raw.lines = NULL;
    data->raw.re_float = re_new(RE_FLOAT);
    data->raw.re_int = re_new(RE_INT);
}
