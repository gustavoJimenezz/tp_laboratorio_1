/*
 ============================================================================
 Name        : trabajo_practico_1
 Author      : Gustavo Jimenez Crespo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operaciones.h"
#include "validacionesMenu.h"


int main(void) {
		setbuf(stdout, NULL);

		int operandoA=0;
	    int operandoB=0;

	    int triggerA=0;
	    int triggerB=0;
	    int triggerC=0;

	    int resultSuma;
	    int resultResta;
	    int resultMultiplicacion;
	    float resultDivision;
	    int divisioPorCero;
	    unsigned long int resultFactorialA;
	    unsigned long int resultFactorialB;

	    char seguir;


	    do
	    {
	        system("cls");

	        switch(menu(triggerA,triggerB,triggerC,operandoA,operandoB))
	        {
	        case 1 :
	                operandoA=peticionNumPositivo("Ingrese OperandoA : ", "Error, ingrese numero entero positivo : ", operandoA);
	                triggerA=1;
	            break;
	        case 2 :
	            if(activador("ERROR primero ingrese operando A \n", triggerA))
	            {
	                operandoB=peticionNumPositivo("Ingrese OperandoB : ", "Error, ingrese numero entero positivo : ",operandoB);
	                triggerB=1;
	            }
	            break;
	        case 3:
	            if (activador("ERROR primero ingrese operandos A y B \n", triggerB))
	            {
	                triggerC=1;
	                resultSuma = suma(operandoA,operandoB);
	                resultResta = resta(operandoA,operandoB);
	                resultMultiplicacion = multiplicacion(operandoA,operandoB);
	                divisioPorCero = division(operandoA, operandoB, &resultDivision);
	                resultFactorialA = factorial(operandoA);
	                resultFactorialB = factorial(operandoB);

	            }
	            break;
	        case 4:
	            if (activador("ERROR para mostrar resultado, carge operandos y calcule\n", triggerC))
	            {
	                printf("_____________________________________\n\n");
	                printf("            **Resultados**           \n");
	                printf("_____________________________________\n\n");
	                printf("El resultado de %d+%d es: %d\n", operandoA, operandoB, resultSuma);
	                printf("El resultado de %d-%d es: %d\n", operandoA, operandoB, resultResta);
	                if(divisioPorCero)
	                {
	                    printf("El resultado de %d/%d es: %.2f\n", operandoA, operandoB, resultDivision);
	                }else
	                {
	                    printf("No se puede dividir entre cero\n");
	                }
	                printf("El resultado de %d*%d es: %d\n", operandoA, operandoB, resultMultiplicacion);
	                printf("El factorial de %d es: %lu\n", operandoA, resultFactorialA);
	                printf("El factorial de %d es: %lu\n", operandoB, resultFactorialB);
	                printf("_____________________________________\n");
	                printf("\n");

	            }

	            break;
	        case 5:
	            printf("Desea Seguir? (s / si ) ");
	            fflush(stdin);
	            scanf("%c", &seguir);
	            break;
	        case 6:
	            operandoA=0;
	            operandoB=0;
	            triggerA=0;
	            triggerB=0;
	            triggerC=0;
	            break;
	        default:
	            printf("Opcion invalida!!\n");
	            break;
	        }
	        system("pause");
	    }
	    while(seguir != 's');

	return EXIT_SUCCESS;
}
