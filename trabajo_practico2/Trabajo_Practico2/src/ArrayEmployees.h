/*
 * ArrayEmployees.h
 *
 *  Created on: 5 oct. 2020
 *      Author: A.G.J.C
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
} typedef empleados;

#endif /* ARRAYEMPLOYEES_H_ */

/** \brief menu de opciones
 * \return valor elegido de las opciones
 *
 */
int menu ();

/** \brief  pone posiciones vacias en true, isEmpty = 1
 *
 * \param gente[] empleados , nombrel de array de estructuras
 * \param tam int tama?o de array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int initEmployees(empleados gente[], int tam);

/** \brief solicita y agrega datos en la primera posicion vacia encontrada
 *
 * \param persona[] empleados, nombrel de array de estructuras
 * \param tam int, tama?o del array
 * \param rangoId int* nombre de variable ya definido, para entregar id automatico
 * \return int 1 si hay error/0 si esta bien
 *
 */
int addEmployees(empleados persona[], int tam, int* idAutomatico);

/** \brief devuelve la posicion del id ingresado
 *
 * \param persona[] empleados, nombrel de array de estructuras
 * \param tam int, tama?o del array
 * \param id int,
 * \return int , devulve la posicion del empleado o -1, en caso de error o empleado no encontrado
 *
 */
int findEmployeeById(empleados persona[], int tam, int id);

/** \brief Elimina de manera l?gica un empleado
 *
 * \param persona[] empleados, nombre del array de estructuras
 * \param tam int, tama?o del array
 * \return int ,0 baja confirmada 1 en caso de error, 2 baja cancelada
 *
 */
int removeEmployee(empleados persona[], int tam);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * \param persona[] nombre del array de estructuras
 * \param tam int,  tama?o del array
 * \param ascDesc int, indica a la funcion de que manera quiere ordenar el array
 * \return int , 0 si se ordeno corectamente,1 en caso de error
 *
 */
int sortEmployees(empleados persona[], int tam,int ascDesc);

/** \brief Imprime el array de empleados de forma encolumnada
 *
 * \param persona[] nombre del array de estructuras
 * \param tam int tama?o del array
 * \return int 0 si se mostro correctamente , 1 en caso de error
 *
 */
int printEmployees(empleados persona[], int tam);

/** \brief modifica los datos de un campo del array especifico
 *
 * \param persona[] empleados, tama?o del array
 * \param tam int,  tama?o del array
 * \return int 0 cambio confirmado, 1 en caso de error, 2 modificacion cancelada
 *
 */
int modificarEmpleado(empleados persona[], int tam);

/** \brief devuelve indice vacio dentro del array,
 *
 * \param persona[] empleados
 * \param tam int
 * \return int
 *
 */
int buscarLibre(empleados persona[], int tam);

/** \brief muestra los datos de una posicion dentro del array
 *
 * \param persona empleados, posicion del que se desea saber los datos
 * \return void
 *
 */
void mostrarpersona(empleados persona);

/** \brief valida que los caracteres ingresados solo sean letras
 *
 * \param cadena[] char, nombre de la variable cadena
 * \return void
 *
 */
void validacionCadenaCaracteres(char cadena[]);

/** \brief verifica que lo ingresado no sea mayor
que el tama?o de la cadena
 * \param cadena[] char, nombre de cadena de caracteres
 * \return void
 *
 */
void validacionCadenaLongitud(char cadena[]);

/** \brief valida la confirmacion
 *
 * \return char, (s)salir , (n)no salir
 *
 */
char validacionSalir();
