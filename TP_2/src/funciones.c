/*
 * funciones.c
 *
 *  Created on: 16 oct. 2021
 *      Author: G
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funciones.h"

int menuEmpleados()
{
    int opcion;
    printf(" _____________________________\n");
    printf("|                             |\n");
    printf("|******* ABM Empleados *******|\n");
    printf("|_____________________________|\n");
    printf("|                             |\n");
    printf("|1. ALTAS                     |\n");
    printf("|2. MODIFICAR                 |\n");
    printf("|3. BAJA                      |\n");
    printf("|4. INFORMAR                  |\n");
    printf("|5. SALIR                     |\n");
    printf("|_____________________________|\n");
    printf("\n   opcion : ");
    scanf("%d", &opcion);

    return opcion;
}

int subMenuModificar()
{
    int opcion;
    printf("\n\nQue desea modificar?\n\n");
    printf("1. NOMBRE\n");
    printf("2. APELLIDO\n");
    printf("3. SALARIO\n");
    printf("4. SECTOR \n");
    printf("5. SALIR\n");
    printf("\n\nIngrese opcion : ");
    scanf("%d", &opcion);

    return opcion;
}

int submenuIdSalir()
{
    int opcion;
    printf("1. Ingresar ID\n");
    printf("2. Salir\n");
    printf("opcion : ");
    scanf("%d", &opcion);
    return opcion;
}

int subMenuAscDes()
{
    int opcion;
    printf("\n\n1. Acs\n");
    printf("2. Desc\n");
    scanf("%d", &opcion);
    return opcion;
}

int peticionesDatosEmpleados(Employee listaEmpleados[], int tam, int idNum, int longLimCadena, int intentos)
{
    int retorno=1 ;
    char nombre[longLimCadena];
    char apellido[longLimCadena];
    float salario;
    int sector;

    if ( listaEmpleados != NULL && tam > 0 && longLimCadena > 0 && intentos > 0 )
    {
        system("cls");
        printf(" _____________________________\n");
        printf("|                             |\n");
        printf("|****** Alta de empleado *****|\n");
        printf("|_____________________________|\n\n");


            if(!peticionNombreApellido(nombre, "Ingrese nombre : ", longLimCadena, intentos))
            {
                retorno = 0;
            }
            strcpy(nombre, strlwr(nombre));
            nombre[0] = toupper(nombre[0]);

            if(retorno == 0 && peticionNombreApellido(apellido, "Ingrese apellido : ", longLimCadena, intentos))
            {
                retorno = 1;
            }
            strcpy(apellido, strlwr(apellido));
            apellido[0] = toupper(apellido[0]);

            if(retorno == 0 && peticionFloatPositivo(&salario, "Ingrese salario : ", 3))
            {
                retorno = 1;
            }

            if(retorno == 0 && peticionEnteroPositivo(&sector, "Ingrese sector : ", 3))
            {
                retorno = 1;
            }

            if(retorno == 0)
            {
                if(addEmployee(listaEmpleados, tam, idNum, nombre, apellido, salario, sector) == -1)
                {
                    printf("\n\nError, sistema esta lleno\n\n");
                    retorno = 1;
                }
            }
    }
    return retorno;
}

int peticionNombreApellido(char cadena[], char textoPeticion[], int tamLimite, int intentos)
{
    int retorno = 1;
    int tamCadena = 0;
    char cadenaAux[1024];
    int cadenaSinNumeros = 0;

    if(cadena != NULL && textoPeticion != NULL && tamLimite > 0 && intentos > 0)
    {
        printf("%s", textoPeticion);
        fflush(stdin);
        gets(cadenaAux);
        tamCadena = strlen(cadenaAux);
        cadenaSinNumeros = caracteresAlfabeto(cadenaAux, tamCadena);

        while(tamCadena >= tamLimite || cadenaSinNumeros == 0 )
        {
            printf("Error, caracteres incorrectos(intentos %d)\n", intentos);
            printf("%s ", textoPeticion);
            scanf("%s", cadenaAux);
            fflush(stdin);
            tamCadena = strlen(cadenaAux);
            cadenaSinNumeros = caracteresAlfabeto(cadenaAux, tamCadena);
            intentos--;
            if( intentos == 0)
            {
                break;
            }

        }

        if(intentos != 0)
        {
            retorno = 0;
            strcpy(cadena, cadenaAux);
        }
    }

    return retorno;
}

int peticionFloatPositivo(float* numFlotante, char texto[], int intentos)
{
    int retorno = 1;
    float numAux;
    int esNum;

    if(numFlotante != NULL && texto != NULL && intentos > 0)
    {

        printf("%s", texto);
        esNum = scanf("%f", &numAux);
        fflush(stdin);
        while(numAux <= 0 || esNum != 1)
        {
            printf("Error, solo numeros flotantes positivos, intentos %d\n", intentos);
            printf("%s", texto);
            esNum = scanf("%f", &numAux);
            fflush(stdin);
            intentos--;
            if( intentos == 0)
            {
                break;
            }
        }
        if(intentos != 0)
        {
            *numFlotante = numAux;
            retorno = 0;
        }
    }
    return retorno;
}

int peticionEnteroPositivo(int* numEntero, char texto[], int intentos)
{
    int retorno = 1;
    int numAux;
    int esNum;
    if (texto != NULL && intentos > 0)
    {

        printf("%s", texto);
        esNum = scanf("%d", &numAux);
        fflush(stdin);
        while(numAux <= 0 || esNum != 1)
        {
            printf("Error, solo numeros positivos intentos %d\n", intentos);
            printf("%s", texto);
            esNum = scanf("%d", &numAux);
            fflush(stdin);
            intentos--;
            if( intentos == 0)
            {
                break;
            }
        }
        if(intentos != 0)
        {
            *numEntero = numAux;
            retorno = 0;
        }
    }
    return retorno;
}

int modificarEmpleado(Employee listEmpleados[], int tam, int longMaxCad, int intentos, int  id)
{
    int error = 1;
    int opcionSalir = 0;
    int indice;
    char confirma;
    char seguir;
    Employee empleadoAux;

    if(listEmpleados != NULL && tam > 0)
    {
        indice = findEmployeeById(listEmpleados, tam, id);
        if(indice == -1)
        {
            printf("\nError, ID inexistente\n\n");
        }
        else
        {
            empleadoAux = listEmpleados[indice];
            do
            {
                system("cls");
                printf(" ________________________________________________________________\n");
                printf("|                                                                |\n");
                printf("|          ************* Modificar datos **************          |\n");
                printf("|________________________________________________________________|\n");
                printf("|                                                                |\n");
                printf("| Id          Nombre        Apellido        Salario        Sector|\n");
                printf("|________________________________________________________________|\n\n");
                printEmployee(empleadoAux);
                printf("_________________________________________________________________\n\n");

                switch(subMenuModificar())
                {
                case 1:
                    if(!peticionNombreApellido(empleadoAux.name, "Ingrese nombre : ", longMaxCad, intentos ))
                    {
                        empleadoAux.name[0]= toupper(empleadoAux.name[0]);
                    }
                    break;
                case 2:
                    if(!peticionNombreApellido(empleadoAux.lastName, "Ingrese apellido : ", longMaxCad, intentos ) == 0)
                    {
                        empleadoAux.lastName[0]= toupper(empleadoAux.lastName[0]);
                    }
                    break;
                case 3:
                    peticionFloatPositivo(&empleadoAux.salary, "Ingrese salario : ", 3);
                    break;
                case 4:
                    peticionEnteroPositivo(&empleadoAux.sector, "Ingrese sector : ", 3);
                    break;
                default:
                    opcionSalir = 1;
                    break;
                }
                if(opcionSalir != 1)
                {
                    printf("\nDesea seguir modificando? (si/s)(no/n) : ");
                    fflush(stdin);
                    scanf("%c", &seguir);
                }
            }
            while(seguir == 's' && opcionSalir != 1);
            system("cls");
            printf("\nConfirma modificacion? (si/s)(no/n) : ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                error= 0;
                listEmpleados[indice] = empleadoAux;
            }
        }
    }
    return error;
}


int totalYcantSalarios(Employee empleados[], int tam, int* cantSalarios, float* totalSalarios)
{
    int retorno = 0;
    int contador = 0;
    float acumulador = 0;

    if(empleados != NULL && tam >0)
    {

        for (int i = 0; i < tam; i++)
        {
            if(empleados[i].isEmpty == 1)
            {
                contador++;
                acumulador += empleados[i].salary;
            }
        }
        *cantSalarios = contador;
        *totalSalarios = acumulador;
        retorno = 1;
    }
    return retorno;
}

int salariosMayPromedio(Employee empleados[], int tam, float promedio)
{
    int cantEmpleados = 0;
    if(empleados != NULL && tam >0)
    {
        for (int i = 0; i < tam; i++)
        {
            if(empleados[i].isEmpty == 1 && empleados[i].salary > promedio)
            {
                cantEmpleados += 1;
            }
        }
    }
    return cantEmpleados;
}


int caracteresAlfabeto(char cadena[], int tamCadena)
{
    int retorno = 1;
    if(cadena != NULL && tamCadena > 0)
    {


        for(int i = 0; i < tamCadena; i++)
        {
           if(!isalpha(cadena[i]) || cadena[i] == ' ')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}



