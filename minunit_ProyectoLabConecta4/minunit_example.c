#include "minunit.h"
#include "../ProyectoLabConecta4/funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILAS 6
#define COLUMNAS 7

MU_TEST(test_revisahorizontal)
{
    mu_check( revisa_horizontal("X0XX") == 0); //revisa si hay 4 fichas iguales ubicadas horizontalmente
}

MU_TEST(test_revisahorizontal2)
{
    mu_check( revisa_horizontal("XOXO") == 0);
}

MU_TEST(test_revisahorizontal3)
{
    mu_check( revisa_horizontal("XXXX") == 1);
}

MU_TEST(test_revisahorizontal4)
{
    mu_check( revisa_horizontal("OOOO") == 1);
}

MU_TEST(test_revisavertical)
{
    mu_check( revisa_vertical("XXXX")== 0);
}

MU_TEST(test_revisavertical2)
{
    mu_check( revisa_vertical("OOOO")== 0);
}

MU_TEST(test_revisasigana)
{
    mu_check( revisa_si_gana("OOOO")== 1);
}

MU_TEST(test_revisasigana2)
{
    mu_check( revisa_si_gana("XXXX")== 1);
}

MU_TEST(test_revisa)
{
    mu_check( revisa_horizontal("XXXX") == 1);
}

MU_TEST(test_revisa2)
{
    mu_check( revisa_si_gana("XXOX") == 0);
}


MU_TEST(test_revisa3)
{
    mu_check( revisa_si_gana("OOOX") == 0);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_revisahorizontal);
    MU_RUN_TEST(test_revisahorizontal2);
    MU_RUN_TEST(test_revisahorizontal3);
    MU_RUN_TEST(test_revisahorizontal4);
    MU_RUN_TEST(test_revisavertical);
    MU_RUN_TEST(test_revisavertical2);
    MU_RUN_TEST(test_revisasigana);
    MU_RUN_TEST(test_revisasigana2);
    MU_RUN_TEST(test_revisa);
    MU_RUN_TEST(test_revisa2);
    MU_RUN_TEST(test_revisa3);
}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
}

