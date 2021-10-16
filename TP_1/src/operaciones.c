#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operaciones.h"
#include "validacionesMenu.h"


int suma (int num1,int num2)
{
    int total;
    total= num1 + num2; ;
    return  total;
}

int resta (int num1, int num2)
{
    int total;
    total = num1-num2;
    return total;
}

int division(int dividendo, int divisor, float* resultado)
{
    int retorno = 0;
    if(divisor)
    {
        * resultado = (float)dividendo/divisor;
        retorno = 1;
    }
    return retorno;
}
int multiplicacion (int num1, int num2)
{
    int total;
    total = (float)num1*num2;
    return total;
}
unsigned long int factorial(int num)
{
    unsigned long int fact;

    if(num==0)
    {
        fact=0;
    }
    else if(num==1)
    {
        fact=1;
    }
    else
    {
        fact= num*factorial(num-1);

    }
    return fact;


}
