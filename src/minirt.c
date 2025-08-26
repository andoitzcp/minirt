#include "minirt.h"

int main(int argc, char **argv)
{
    (void)argc;
    t_data data;

    printf("hola mundo\n");
    parse(&data, argv[1]);
}
