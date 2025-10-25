#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../src/minirt.h"

Test(parsing, is_valid_input_file)
{
    cr_expect(is_valid_input_file("") == FALSE, "Expected to return FALSE when empty string is handed.");
    cr_expect(is_valid_input_file("bar") == FALSE, "Expected to return FALSE when extension is not present.");
    cr_expect(is_valid_input_file("bar.rg") == FALSE, "Expected to return FALSE when extension is incorrect.");
    cr_expect(is_valid_input_file("baño.rg") == FALSE, "Expected to return FALSE when file contains non ASCII chars.");

    // testing very large path
    char str[5000];
    memset(str, 'a', 5000);
    str[4999] = '\0';
    cr_expect(is_valid_input_file(str) == FALSE, "Expected to return FALSE when path is too large.");

    // testing a valid file paths
    cr_expect(is_valid_input_file("bar.rt") == TRUE, "Expected to return TRUE when valid file.");
    cr_expect(is_valid_input_file("../bar.rt") == TRUE, "Expected to return TRUE when valid file with relative path.");
    cr_expect(is_valid_input_file("/$HOME/minirt/bar.rt") == TRUE, "Expected to return TRUE when valid file with env variables.");
}

// TODO crear test de parse general (ficheros)
// TODO crear test de get_data_geometrics
// TODO crear test de get_data_common
// TODO crear test de get_data_basics
// TODO crear test de lines
// TODO crear test de boundaries
