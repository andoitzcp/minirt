#include "minirt.h"

int main(int argc, char **argv)
{
    (void)argc;
    t_data data;

    data.emf = 0;
    parse(&data, argv[1]);
}
