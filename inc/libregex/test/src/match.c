#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(match, basic)
{
    cr_expect(match(re_new("abc"), "abc") == 1);
    cr_expect(match(re_new("abc"), "abd") == 0);
    cr_expect(match(re_new(""), "abc") == 1);
    cr_expect(match(re_new("abc"), "") == 0);
}

Test(match, char_classes)
{
    cr_expect(match(re_new("[a]"), "a") == 1);
    cr_expect(match(re_new("[a]"), "b") == 0);
    cr_expect(match(re_new("[a-z]"), "b") == 1);
    cr_expect(match(re_new("[^a-z]"), "1") == 1);
}

Test(match, quantifiers)
{
    cr_expect(match(re_new("a*"), "") == 1);
    cr_expect(match(re_new("a*"), "aaa") == 1);
    cr_expect(match(re_new("a*"), "b") == 1);
    cr_expect(match(re_new("a{1}"), "ab") == 1);
    cr_expect(match(re_new("a{1}"), "aaaab") == 1);
    cr_expect(match(re_new("a{1}"), "b") == 0);
    cr_expect(match(re_new("a{1}"), "") == 0);
    cr_expect(match(re_new("a{1}{3}"), "ab") == 1);
    cr_expect(match(re_new("a{1}{3}"), "aaab") == 1);
    cr_expect(match(re_new("^a{1}{3}b$"), "aaaab") == 0);
    cr_expect(match(re_new("^a{1}{3}ba{1}{3}$"), "aabaa") == 1);
    cr_expect(match(re_new("^a{1}{3}ba{1}{2}$"), "aabaaa") == 0);
    cr_expect(match(re_new("^a.*b"), "a123456789b") == 1);
}

Test(match, anchor)
{
    cr_expect(match(re_new("^abc"), "abcde") == 1);
    cr_expect(match(re_new("^abc"), "0abcde") == 0);
    cr_expect(match(re_new("cde$"), "abcde") == 1);
    cr_expect(match(re_new("cde$"), "abcdex") == 0);
    cr_expect(match(re_new("^abcde$"), "abcde") == 1);
    cr_expect(match(re_new("^abcde$"), "abcdex") == 0);
    cr_expect(match(re_new("^abcde$"), "0abcde") == 0);
    cr_expect(match(re_new("^abcde$"), "0abcdex") == 0);
}

Test(match, escaping)
{
    cr_expect(match(re_new("\\."), ".") == 1);
    cr_expect(match(re_new("\\*"), "*") == 1);
    cr_expect(match(re_new("\\\\"), "\\") == 1);
}

Test(match, edge_cases)
{
    char *very_long_string = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    cr_expect(match(re_new("a*"), very_long_string) == 1);
}

Test(match, real_float)
{
    char *float_re = "^-{0}{1}[0-9]*\\.{0}{1}[0-9]{1}$";

    cr_expect(match(re_new(float_re), "0.5") == 1);
    cr_expect(match(re_new(float_re), "0.556") == 1);
    cr_expect(match(re_new(float_re), "0.556a") == 0);
    cr_expect(match(re_new(float_re), "0.") == 0);
    cr_expect(match(re_new(float_re), ".123") == 1);
    cr_expect(match(re_new(float_re), "1234.123") == 1);
    cr_expect(match(re_new(float_re), "1234") == 1);
    cr_expect(match(re_new(float_re), "") == 0);
    cr_expect(match(re_new(float_re), ".") == 0);
    cr_expect(match(re_new(float_re), "1234.") == 0);
    cr_expect(match(re_new(float_re), "abc12.") == 0);
    cr_expect(match(re_new(float_re), "1234.5678.") == 0);
    cr_expect(match(re_new(float_re), "1234.5678.9") == 0);
    cr_expect(match(re_new(float_re), "-1234.567") == 1);
    cr_expect(match(re_new(float_re), "-1234") == 1);
}

Test(match, real_int)
{
    char *int_re = "^-{0}{1}[0-9]{1}$";

    cr_expect(match(re_new(int_re), "1234") == 1);
    cr_expect(match(re_new(int_re), "-1234") == 1);
    cr_expect(match(re_new(int_re), "0") == 1);
    cr_expect(match(re_new(int_re), "") == 0);
    cr_expect(match(re_new(int_re), "-1234.12") == 0);
}
