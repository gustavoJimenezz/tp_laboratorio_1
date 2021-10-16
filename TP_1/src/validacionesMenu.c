/*
 * validacionesMenu.c
 *
 *  Created on: 25 sep. 2021
 *      Author: G
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operaciones.h"
#include "validacionesMenu.h"


int menu (int trigger1, int trigger2,int trigger3,int operandoA, int operandoB)
{
    int comando;
        printf("_____________________________________\n\n");
        printf("          ***Calculadora***          \n");
        printf("_____________________________________\n");
        printf("                                     \n");
    if(trigger1)
    {
        printf("1. Ingresar 1er operando (A=%d)\n", operandoA);
    }else
    {
        printf("1. Ingresar 1er operando (A=x)\n");
    }

    if(trigger2)
    {
        printf("2. Ingresar 2do operando (B=%d)\n", operandoB);
    }else
    {
        printf("2. Ingresar 2do operando (B=y)\n");
    }

        printf("3. Calcular todas las operaciones\n");
    menuOpc3(trigger3,operandoA,operandoB);

        printf("4. Informar resultados\n");
        printf("5.Salir\n");
        printf("6.Reiniciar\n");
        printf("_____________________________________\n\n");
        printf("opcion : ");
    scanf("%d",&comando);
    return comando;
}

void menuOpc3 (int trigger, int operandoA, int operandoB)
{
    if (!trigger)
    {
        printf(" a) Calcular la suma (A+B)\n");
        printf(" b) Calcular la resta (A-B)\n");
        printf(" c) Calcular la division (A/B)\n");
        printf(" d) Calcular la multiplicacion (A*B)\n");
        printf(" e) Calcular el factorial (A!) y (B!)\n");

    }
    else if(  trigger==1)
    {
        printf(" a) Calcular la suma (%d+%d)\n",operandoA, operandoB);
        printf(" b) Calcular la resta (%d+%d)\n",operandoA, operandoB);
        printf(" c) Calcular la division (%d+%d)\n",operandoA, operandoB);
        printf(" d) Calcular la multiplicacion (%d+%d)\n",operandoA, operandoB);
        printf(" e) Calcular el factorial (%d!) y (%d!)\n",operandoA,operandoB);
    }

}

int peticionNumPositivo(char texto[], char textoError[], int operando)
{
    int numero;
    printf("%s", texto);
    scanf("%d", &numero);

    while(numero < 0)
    {
        printf("%s", textoError);
        scanf("%d", &numero) ;

    }

    return numero;
}

int activador(char textoError[],int trigger)
{
    int valor;

    if(!trigger)
    {
        printf("%s",textoError);
        valor=0;
    }
    else
    {
        valor=1;
    }
    return valor ;
}

