/*
 ============================================================================
 Name        : trabajo_practico_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "funciones.h"

#define TAM 10
#define TAMCARGA 8
#define LONGITUD_LIMITE 51
#define CANT_INTENTOS 3

int main(void) {
		setbuf(stdout, NULL);

		Employee listaEmpleados[TAM];
	    initEmployees(listaEmpleados, TAM);
	    int proximoId = 1;
	    int almenosUnEmpleado = 0;
	    int retornoBorrar = 0;
	    int retornoModificar = 0;
	    int idIngresado;

	    int cantSalarios = 0;
	    float totalSalarios = 0;
	    float promedioSalarios = 0;
	    int salariosArribaDelPromedio = 0;


	    char seguir;
	    do
	    {
	        system("cls");
	        switch(menuEmpleados())
	        {
	        case 1:
	            if(peticionesDatosEmpleados(listaEmpleados, TAM, proximoId, LONGITUD_LIMITE, CANT_INTENTOS) == 0 )
	            {
	                proximoId++;
	                almenosUnEmpleado = 1;
	                printf("\n\nAlta exitosa!!\n\n");
	            }
	            else
	            {
	                printf("\n\nProblema para realizar el alta \n\n");
	            }
	            break;
	        case 2:     /////////modificar empleado/////////
	            if(almenosUnEmpleado == 1)
	            {
	                system("cls");
	                sortEmployeesById(listaEmpleados, TAM);
	                printEmployees(listaEmpleados, TAM);
	                switch(submenuIdSalir())
	                {
	                case 1:
	                    printf("\nIngrese ID : ");
	                    scanf("%d", &idIngresado);
	                    retornoModificar = modificarEmpleado(listaEmpleados, TAM, LONGITUD_LIMITE, CANT_INTENTOS, idIngresado);
	                    if(retornoModificar == 0)
	                    {
	                        printf("\n\nModificado con exito");
	                    }
	                    else
	                    {
	                        printf("\n\nProblemas para realizar la modificacion\n\n");
	                    }
	                    break;
	                default:
	                    break;
	                }
	            }
	            else
	            {
	                printf("\n\nGenere almenos un Alta de empleado\n\n");
	            }
	            break;
	        case 3:    /////////borrar empleado/////////
	            if(almenosUnEmpleado == 1)
	            {
	                system("cls");
	                sortEmployeesById(listaEmpleados, TAM);
	                printEmployees(listaEmpleados, TAM);

	                switch(submenuIdSalir())
	                {
	                case 1:
	                    printf("Ingrese ID : ");
	                    scanf("%d", &idIngresado);
	                    retornoBorrar = removeEmployee(listaEmpleados, TAM, idIngresado);
	                    if(retornoBorrar == 0)
	                    {
	                        printf("\n\nBaja de empleado con exito\n\n");
	                    }
	                    else
	                    {
	                        printf("\n\nProblemas para realizar la Baja de empleado\n\n");
	                    }
	                    break;
	                default:
	                    break;
	                }

	            }
	            else
	            {
	                printf("\n\nGenere almenos un Alta de empleado\n\n");
	            }
	            break;
	        case 4:
	            if(almenosUnEmpleado == 1)
	            {
	                switch(subMenuAscDes())
	                {
	                    case 1:
	                        sortEmployees(listaEmpleados, TAM, 0);
	                        break;
	                    case 2:
	                        sortEmployees(listaEmpleados, TAM, 1);
	                        break;
	                    default:
	                        break;

	                }

	                printEmployees(listaEmpleados, TAM);
	                totalYcantSalarios(listaEmpleados, TAM, &cantSalarios, &totalSalarios);
	                promedioSalarios = (float)totalSalarios / cantSalarios;
	                salariosArribaDelPromedio = salariosMayPromedio(listaEmpleados, TAM, promedioSalarios);

	                printf("_________________________________________________________________\n");
	                printf("\n\nSuma total de salarios : %.3f\n", totalSalarios);
	                printf("Salario promedio : %.3f\n", promedioSalarios);
	                printf("Cantidad de salarios arriba del promedio  : %d\n\n", salariosArribaDelPromedio);
	                printf("_________________________________________________________________\n\n");
	            }
	            else
	            {
	                printf("\n\nGenere almenos un Alta de empleado\n\n");
	            }
	            break;
	        case 5:
	            printf("Desea Salir? (si/s)(no/n) : ");
	            fflush(stdin);
	            scanf("%c", &seguir);
	            seguir = tolower(seguir);
	            break;
	        default:
	            break;
	        }
	        system("pause");

	    }
	    while(seguir != 's');

	    return 0;
	return EXIT_SUCCESS;
}
