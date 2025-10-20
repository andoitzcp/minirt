#include "minirt.h"

uint8_t check_color_bounds(t_color *color)
{
    if (color->r < 0 || color->r > 255)
        return (0);
    if (color->g < 0 || color->g > 255)
        return (0);
    if (color->b < 0 || color->b > 255)
        return (0);
    return (1);
}

uint8_t check_nvector_bounds(t_tuple *vector)
{
    if (vector->w != 1)
        return (0);
    if (vector->x < 0 || vector->x > 1)
        return (0);
    if (vector->y < 0 || vector->y > 1)
        return (0);
    if (vector->z < 0 || vector->z > 1)
        return (0);
    return (1);
}
