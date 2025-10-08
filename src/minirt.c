#include "minirt.h"

int main(int argc, char **argv)
{
    (void)argc;
    t_data data;

    data.emf = 0;
    init(&data);
    parse(&data, argv[1]);
}
