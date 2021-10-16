/*
 * funciones.h
 *
 *  Created on: 16 oct. 2021
 *      Author: G
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


/** \brief Menu con opciones.
 *
 * \return int valor seleccionado.
 *
 */
int menuEmpleados();


/** \brief Submenu con opciones.
 *
 * \return int valor de opciones seleccionado
 *
 */
int subMenuModificar();


/** \brief Submenu de opciones.
 *
 * \return int valor de opcion seleccionado
 *
 */
int submenuIdSalir();


/** \brief Submenu de opciones.
 *
 * \return int valor de opcion seleccionado
 *
 */
int subMenuAscDes();


/** \brief Solicitudes de nombre, apellidos, salario, sector con sus validaciones.
            para cada estructura Empleado.
 * \param listaEmpleados[] Employee
 * \param tam int
 * \param idNum int
 * \param longLimCadena int
 * \param intentos int
 * \return Devuelve (1) si Error [Longitud no válida o puntero NULL o sin
           espacio libre] - (0) si está bien
 *
 */
int peticionesDatosEmpleados(Employee listaEmpleados[], int tam, int idNum, int longLimCadena, int intentos);


/** \brief Solicita una cadena de caracteres validando que no son números ni espacios.
           y restringir un límite de caracteres e intentos.
 *
 * \param cadena[] char
 * \param textoPeticion[]
 * \param tamLimite int
 * \param intentos int
 * \return Devuelve (1) si Error [Longitud no válida o puntero NULL o sin
           espacio libre] - (0) si está bien
 *
 */
int peticionNombreApellido(char cadena[], char textoPeticion[], int tamLimite, int intentos);


/** \brief Se solicita un flotante de validación que no sea un carácter o un flotante negativo.
 *
 * \param numFlotante float
 * \param texto[] char
 * \param intentos int
 * \return Devuelve (1) si Error [Longitud no válida o puntero NULL o sin
           espacio libre] - (0) si está bien
 *
 */
int peticionFloatPositivo(float* numFlotante, char texto[], int intentos);


/** \brief Se solicita un número entero validando que no es un carácter ni un número entero negativo.
 *
 * \param numEntero int
 * \param texto[] char
 * \param intentos int
 * \return Devuelve (1) si Error [Longitud no válida o puntero NULL o sin
           espacio libre] - (0) si está bien
 */
int peticionEnteroPositivo(int* numEntero, char texto[], int intentos);


/** \brief Modifique los datos en la estructura del empleado ingresando una identificación válida.
 *
 * \param listEmpleados[] Employee
 * \param tam int
 * \param longMaxCad int
 * \param intentos int
 * \return Devuelve (1) si Error [Longitud no válida o puntero NULL o sin
           espacio libre] - (0) si está bien
 *
 */
int modificarEmpleado(Employee listEmpleados[], int tam, int longMaxCad, int intentos, int  id);


/** \brief Devuelta por direcion de memoria cantidad de salarios y suma total de salarios
 *         de empleados con isEmpty = 1.
 * \param empleados[] Employee
 * \param tam int
 * \param cantSalarios int*
 * \param totalSalarios float*
 * \return int valor de 1 en caso de error/ valor de 0 en caso de exito
 *
 */
int totalYcantSalarios(Employee empleados[], int tam, int* cantSalarios, float* totalSalarios);


/** \brief Entrega la cantidad de salarios que estan encima del promedi.
 *
 * \param empleados[] Employee vector de Employee
 * \param tam int longitud de vector de ePerson
 * \param promedio float
 * \return int cantidad de salarios encima del promedio
 *
 */
int salariosMayPromedio(Employee empleados[], int tam , float promedio);


/** \brief Verifique que la cadena solo contenga caracteres.
 *
 * \param cadena[] char
 * \param tamCadena int
 * \return Devuelve (1) si Error [Longitud no válida o puntero NULL o sin
           espacio libre] - (0) si está bien
 */
int caracteresAlfabeto(char cadena[], int tamCadena);


#endif /* FUNCIONES_H_ */
