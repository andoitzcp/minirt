#include "minirt.h"

t_amblight new_amblight(t_color color, float ratio)
{
    t_amblight amblight;

    amblight.col = color;
    amblight.ratio = ratio;
    return (amblight);
}

t_amblight convert_amblight_from_raw(t_raw_amblight raw_amblight)
{
    t_amblight amblight;

    amblight.ratio = raw_amblight.ratio;
    amblight.col.r = raw_amblight.col.r / 255;
    amblight.col.g = raw_amblight.col.g / 255;
    amblight.col.b = raw_amblight.col.b / 255;
    return (amblight);
}

t_amblight def_amblight(void)
{
    t_amblight amblight;

    amblight.ratio = 1;
    amblight.col = color_set(1, 1, 1);
    return (amblight);
}
