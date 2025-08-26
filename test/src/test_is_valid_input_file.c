#include <criterion/criterion.h>
#include "../../src/minirt.h"


Test(parsing, is_valid_input_file)
{
    cr_expect(is_valid_input_file("") == FALSE, "Expected \"Test\" to return FALSE when empty string is handed.");
    cr_expect(is_valid_input_file("bar") == FALSE, "Expected \"Test\" to return FALSE when extension is not present.");
    cr_expect(is_valid_input_file("bar.rg") == FALSE, "Expected \"Test\" to return FALSE when extension is incorrect.");
    cr_expect(is_valid_input_file("baño.rg") == FALSE, "Expected \"Test\" to return FALSE when file contains non ASCII chars.");

    // testing very large path
    char str[5000];
    memset(str, 'a', 5000);
    str[4999] = '\0';
    cr_expect(is_valid_input_file(str) == FALSE, "Expected \"Test\" to return FALSE when path is too large.");

    // testing a valid file paths
    cr_expect(is_valid_input_file("bar.rt") == TRUE, "Expected \"Test\" to return TRUE when valid file.");
    cr_expect(is_valid_input_file("../bar.rt") == TRUE, "Expected \"Test\" to return TRUE when valid file with relative path.");
    cr_expect(is_valid_input_file("/$HOME/minirt/bar.rt") == TRUE, "Expected \"Test\" to return TRUE when valid file with env variables.");
}
