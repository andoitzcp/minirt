#include "minirt.h"

t_light new_light(t_tuple point, t_color color, float ratio)
{
    t_light light;

    light.p = point;
    light.col = color;
    light.abr = ratio;
    return (light);
}

t_light convert_light_from_raw(t_raw_light raw_light)
{
    t_light light;

    light.p = raw_light.p;
    light.abr = raw_light.abr;
    light.col.r = raw_light.col.r / 255;
    light.col.g = raw_light.col.g / 255;
    light.col.b = raw_light.col.b / 255;
    return (light);
}

t_light default_light(void)
{
    t_light light;

    light.p = tuple_point(-10, -10, -10);
    light.abr = 1;
    light.col = color_set(1, 1, 1);
    return (light);
}
