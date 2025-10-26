#include "minirt.h"

t_world default_world(void)
{
    t_world world;

    world.res.x_sz = 1080;
    world.res.y_sz = 1920;
    world.ali = default_amblight();
    world.l = def_light();
    world.c = default_camera();
    return (world);
}
