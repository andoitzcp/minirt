#include "minirt.h"

t_world def_world(void)
{
    t_world world;

    world.res.x_sz = 1080;
    world.res.y_sz = 1920;
    world.ali = def_amblight();
    world.l = def_light();
    world.c = def_camera();
    return (world);
}
