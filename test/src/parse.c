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

Test(parsing, get_raw_contet)
{
    t_data data;
    t_rawlines *rawl;
    t_rawlines *node;

    // test an empty file, it should return an empty linked list
    rawl = NULL;
    data.rawl = &rawl;
    data.emf = EMF_NOFREE;
    get_raw_content(&data, "./test/res/empty.rt");

    node = *(data.rawl);
    cr_expect(node == NULL, "Expected to return TRUE when empty file is handled.");
    free_rawl(data.rawl);

    // test an simple dummy file
    rawl = NULL;
    data.rawl = &rawl;
    data.emf = EMF_NOFREE;
    get_raw_content(&data, "./test/res/dummy.rt");

    node = *(data.rawl);
    cr_expect(strncmp(node->line, "foo\n", 5) == 0, "Expected to return TRUE when dummy file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when dummy file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "bar\n", 5) == 0, "Expected to return TRUE when dummy file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when dummy file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "baz\n", 5) == 0, "Expected to return TRUE when dummy file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when dummy file is handled.");
    node = node->next;

    cr_expect(node == NULL, "Expected to return TRUE when dummy file is handled.");
    free_rawl(data.rawl);

    // test an actual example file
    rawl = NULL;
    data.rawl = &rawl;
    data.emf = EMF_NOFREE;
    get_raw_content(&data, "./test/res/example.rt");

    node = *(data.rawl);
    cr_expect(strncmp(node->line, "A 0.3 255,255,255\n", 18) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "\n", 2) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "C -300,0,0 1,0,0.2 50\n", 22) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "\n", 2) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "L -300,10.0,100.0 0.6 255,255,255\n", 34) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "\n", 2) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "sp 25.0,50.0,20.6 102.6 10,0,255\n", 33) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "\n", 2) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "cy 20.0,-100.0,20.6 0.5,1,0.50 140.2 200.42 0,200,255\n", 54) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "cy 80.0,-100.0,0.6 0,1,0 140.2 2000.42 200,200,55\n", 50) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "cy 2000.0,10.0,-100.6 0,0,1 140.2 2000.42 200,0,55\n", 51) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "\n", 2) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(strncmp(node->line, "pl 0.0,-100.0,0.0 0.0,1.0,0.0 255,255,225\n", 42) == 0, "Expected to return TRUE when example file is handled.");
    cr_expect(node->elid == ELID_NULL, "Expected to return TRUE when example file is handled.");
    node = node->next;

    cr_expect(node == NULL, "Expected to return TRUE when example file is handled.");
    free_rawl(data.rawl);
}
