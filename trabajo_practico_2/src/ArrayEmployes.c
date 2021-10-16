/*
 * ArrayEmployes.c
 *
 *  Created on: 16 oct. 2021
 *      Author: G
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"


int initEmployees(Employee list[], int len)
{
    int error=1;
    if(list!= NULL && len >0)
    {
        for(int i= 0; i < len ; i++)
        {
            list[i].isEmpty=0;
        }
        error= 0;
    }
    return error;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{   int error = -1;
    int indice;
    if(list != NULL && len > 0 && id >0 && name != NULL && lastName != NULL && salary > 0 && sector > 0)
    {
        indice = searchFree(list,len);
        if(indice != -1)
        {
            list[indice].id = id;
            strcpy(list[indice].name, name);
            strcpy(list[indice].lastName, lastName);
            list[indice].salary = salary;
            list[indice].sector = sector;
            list[indice].isEmpty = 1;
            error = 0;
        }

    }
    return error;
}

int findEmployeeById(Employee list[], int len, int id)
{
    int indice= -1;
    for(int i = 0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 1)
        {
            indice = i ;
            break;
        }
    }
    return indice;
}

void printEmployee(Employee empleado)
{
    printf(" %3d %15s %15s %14.3f %13d\n",
           empleado.id,
           empleado.name,
           empleado.lastName,
           empleado.salary,
           empleado.sector);
}

int printEmployees(Employee list[], int len)
{
    int error = 1;
    if(list != NULL && len >0)
    {
        system("cls");
        printf(" ________________________________________________________________\n");
        printf("|                                                                |\n");
        printf("| Id          Nombre        Apellido        Salario        Sector|\n");
        printf("|________________________________________________________________|\n\n");


        for(int i = 0 ; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                printEmployee(list[i]);
                error= 0;
            }
        }
        if(error==1)
        {
            printf("\n\nNo Hay personas que mostrar\n\n");
        }
        printf("\n\n");
    }
    return error;
}

int searchFree(Employee list[], int len)
{
    int indice= -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                indice = i ;
                break;
            }
        }
    }
    return indice;
}



int removeEmployee(Employee list[], int len, int id)
{
    int error = 1;
    int indice;
    char confirma;

    if(list != NULL && len > 0 && id > 0)
    {
        indice = findEmployeeById(list, len, id);
        if(indice == -1)
        {
            printf("\n\nNo existe esa persona con ese ID\n\n");
        }
        else
        {
            system("cls");
            printf(" ________________________________________________________________\n");
            printf("|                                                                |\n");
            printf("|          ************* Baja de empleado *************          |\n");
            printf("|________________________________________________________________|\n");
            printf("|                                                                |\n");
            printf("| Id          Nombre        Apellido        Salario        Sector|\n");
            printf("|________________________________________________________________|\n\n");
            printEmployee(list[indice]);

            printf("\nconfirma borrado (si/s): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                list[indice].isEmpty = 0;
                error= 0;
            }
        }
    }
    return error;
}

int sortEmployees(Employee list[], int len, int oreder)
{
    int retorno = 1;
    Employee auxEmpleado;

    if(list != NULL && len>0 )
    {
        for( int i = 0; i < len-1; i++)
        {
            for( int j= i+1; j < len ; j++)
            {
                if(((list[i].sector > list[j].sector && oreder == 0) ||
                    (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0 && oreder == 0))||
                    ((list[i].sector < list[j].sector && oreder == 1) ||
                    (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0 && oreder == 1)))
                {
                    auxEmpleado = list[i];
                    list[i]= list[j];
                    list[j]= auxEmpleado;

                }

                retorno= 0;
            }
        }
    }
    return retorno;
}

int sortEmployeesById(Employee empleado[], int tam)
{
    int retorno = 1;
    Employee auxEmpleado;

    if(empleado != NULL && tam>0 )
    {
        for( int i = 0; i < tam-1; i++)
        {
            for( int j= i+1; j< tam ; j++)
            {
                if(empleado[i].id > empleado[j].id)
                {
                    auxEmpleado = empleado[i];
                    empleado[i]= empleado[j];
                    empleado[j]= auxEmpleado;

                }

                retorno= 0;
            }
        }
    }
    return retorno;
}



