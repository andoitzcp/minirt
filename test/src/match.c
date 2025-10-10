#include "../../inc/libregex/src/libregex.h"
#include "../../src/minirt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(match, re_float)
{
    t_re **re;


    re = re_new(RE_FLOAT);
    cr_assert(match(re, "1.0") == 1);
    cr_assert(match(re, "1000.0") == 1);
    cr_assert(match(re, "-1000.0") == 1);
    cr_assert(match(re, "0.0") == 1);
    cr_assert(match(re, "-0.0") == 1);
    cr_assert(match(re, ".0") == 1);
    cr_assert(match(re, "-.0") == 1);
    cr_assert(match(re, "0") == 1);
    cr_assert(match(re, "1") == 1);
    cr_assert(match(re, "-1") == 1);
    cr_assert(match(re, "42") == 1);
    cr_assert(match(re, "-42") == 1);
    cr_assert(match(re, "--42") == 0);
    cr_assert(match(re, "a-42") == 0);
    cr_assert(match(re, "-42..") == 0);
    cr_assert(match(re, "-42.0.") == 0);
    cr_assert(match(re, "-42a") == 0);
}

Test(match, re_int)
{
    t_re **re;

    re = re_new(RE_INT);
    cr_assert(match(re, "1") == 1);
    cr_assert(match(re, "-1") == 1);
    cr_assert(match(re, "0") == 1);
    cr_assert(match(re, "-0") == 1);
    cr_assert(match(re, "99999999") == 1);
    cr_assert(match(re, "-99999999") == 1);
    cr_assert(match(re, "--1") == 0);
    cr_assert(match(re, "-1.0") == 0);
    cr_assert(match(re, "a1") == 0);
    cr_assert(match(re, "1a") == 0);
}
/*
** In theese regex the contents of each element don't matter only the structure of
** the line
*/
Test(match, re_el_a)
{
    t_re **re;

    re = re_new(RE_EL_A);
    cr_assert(match(re, "A 0.3 255,255,255") == 1);
    cr_assert(match(re, "   A     0.3   255,255,255  ") == 1);
    cr_assert(match(re, "   A     0.3   2552,255,255  ") == 1);
    cr_assert(match(re, "A 0.3 255a,255,255") == 1);
    cr_assert(match(re, "A 0.3a 255,255,255") == 1);
    cr_assert(match(re, "A 0.3 255,255,255,255") == 0);
    cr_assert(match(re, "A 0.3,a 255,255,255,255") == 0);
    cr_assert(match(re, "AA 0.3,a 255,255,255,255") == 0);
}

Test(match, re_el_c)
{
    t_re **re;

    re = re_new(RE_EL_C);
    cr_assert(match(re, "C -300,0,0 1,0,0.2 50") == 1);
    cr_assert(match(re, "  C    -300,0,0   1,0,0.2   50 ") == 1);
    cr_assert(match(re, "C -30a0,0,0 1,0,0.2 50") == 1);
    cr_assert(match(re, "C -300,0,0 1,a0,0.2 50") == 1);
    cr_assert(match(re, "C -300,0,0 1,0,0.2 a50") == 1);
    cr_assert(match(re, "C -300,0,0 1,0,0.2 1,50") == 0);
    cr_assert(match(re, "C -300,0,0 1,0,0.2,1 50") == 0);
    cr_assert(match(re, "C -300,0,0,1 1,0,0.2 50") == 0);
    cr_assert(match(re, "C -300,0,0 1,0,0.2 50 1") == 0);
    cr_assert(match(re, "CC -300,0,0 1,0,0.2 a50") == 0);
}

Test(match, re_el_l)
{
    t_re **re;

    re = re_new(RE_EL_L);
    cr_assert(match(re, "L -300,10.0,100.0 0.6 255,255,255") == 1);
    cr_assert(match(re, "  L    -300,10.0,100.0   0.6    255,255,255   ") == 1);
    cr_assert(match(re, "L -300a,10.0,100.0 a0.6 a255,255,255") == 1);
    cr_assert(match(re, "La -300,10.0,100.0 0.6 255,255,255") == 0);
    cr_assert(match(re, "L -300,,10.0,100.0 0.6 255,255,255") == 0);
    cr_assert(match(re, "L -300,10.0,100.0 ,0.6 255,255,255") == 0);
    cr_assert(match(re, "L -300,10.0,100.0 0.6 1,255,255,255") == 0);
}

Test(match, re_el_sp)
{
    t_re **re;

    re = re_new(RE_EL_SP);
    cr_assert(match(re, "sp 25.0,50.0,20.6 102.6 10,0,255") == 1);
    cr_assert(match(re, " sp    25.0,50.0,20.6   102.6  10,0,255 ") == 1);
    cr_assert(match(re, "sp 25a.0,5aa0.0,2a0.6 10a2.6 1a0,a0,a255") == 1);
    cr_assert(match(re, "spa 25.0,50.0,20.6 102.6 10,0,255") == 0);
    cr_assert(match(re, "sp 102.6 10,0,255") == 0);
    cr_assert(match(re, "sp 25,.0,50.0,20.6 102.6 10,0,255") == 0);
    cr_assert(match(re, "sp 25.0,50.0,20.6 1,02.6 10,0,255") == 0);
    cr_assert(match(re, "sp 25.0,50.0,20.6 102.6 10,0,2,55") == 0);
}

Test(match, re_el_cy)
{
    t_re **re;

    re = re_new(RE_EL_CY);
    cr_assert(match(re, "cy 20.0,-100.0,20.6 0.5,1,0.50 140.2 200.42 0,200,255") == 1);
    cr_assert(match(re, "cy 80.0,-100.0,0.6 0,1,0 140.2 2000.42 200,200,55") == 1);
    cr_assert(match(re, "cy 2000.0,10.0,-100.6 0,0,1 140.2 2000.42 200,0,55") == 1);
    cr_assert(match(re, "   cy  a2000.0,a10.0,-1a00.6   0a,a0,a1   1a40.2 2a000.42  20a0,0a,a55a   ") == 1);
    cr_assert(match(re, "cya 2000.0,10.0,-100.6 0,0,1 140.2 2000.42 200,0,55") == 0);
    cr_assert(match(re, "cy 2,000.0,10.0,-100.6 0,0,1 140.2 2000.42 200,0,55") == 0);
}

Test(match, re_el_pl)
{
    t_re **re;

    re = re_new(RE_EL_PL);
    cr_assert(match(re, "pl 0.0,-100.0,0.0 0.0,1.0,0.0 255,255,225") == 1);
    cr_assert(match(re, " pl  0.0,-100.0,0.0    0.0,1.0,0.0    255,255,225  ") == 1);
    cr_assert(match(re, "apl 0.0,-100.0,0.0 0.0,1.0,0.0 255,255,225") == 0);
    cr_assert(match(re, "pl 0.0,-100.0,,0.0 0.0,1.0,0.0 255,255,225") == 0);
}

Test(match, re_el_blank)
{
    t_re **re;

    re = re_new(RE_EL_BLANK);
    cr_assert(match(re, "\n") == 1);
    cr_assert(match(re, "a\n") == 0);
}
