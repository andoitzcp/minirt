#include "../../inc/libft/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

#define EPSILON 0.000001

static int is_equal(float a, float b)
{
    float c;

    //printf("a: %f\n", a);
    //printf("b: %f\n", b);
    c = a - b;
    if (c < 0)
        c *= -1;
    return (c < EPSILON);
}

Test(ft_atof, basic)
{
    cr_expect(is_equal(ft_atof("-100.123"), -100.123));
    cr_expect(is_equal(ft_atof("-100"), -100));
    cr_expect(is_equal(ft_atof("-1.000000001"), -1.000000001));
    cr_expect(is_equal(ft_atof("-1"), -1));
    cr_expect(is_equal(ft_atof("-1.000"), -1));
    cr_expect(is_equal(ft_atof("-0.999999999999"), -0.999999999999));
    cr_expect(is_equal(ft_atof("-0.0"), 0.0));
    cr_expect(is_equal(ft_atof("0.00000000000001"), 0.00000000000001));
    cr_expect(is_equal(ft_atof("0.99999999999"), 0.99999999999));
    cr_expect(is_equal(ft_atof("42.42"), 42.42));
    cr_expect(is_equal(ft_atof(".42"), 0.42));
    cr_expect(is_equal(ft_atof("-.42"), -0.42));
}
