/*
 * operaciones.h
 *
 *  Created on: 25 sep. 2021
 *      Author: G
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/** \brief suma dos enteros
 *
 * \param int primer entero a sumar
 * \param int segundo entero a sumar
 * \return total de la suma
 *
 */
int suma (int num1,int num2);

/** \brief resta dos enteros
 *
 * \param int primer entero a restar
 * \param int segundo entero a restar
 * \return total de la resta
 *
 */
int resta (int num1, int num2);

/** \brief division de dos enteros
 *
 * \param int dividendo
 * \param int divisor
 * \return total de la division
 *
 */
int division(int dividendo, int divisor, float* resultado);

/** \brief multiplicacion de dos enteros
 *
 * \param int primer entero a multiplicar
 * \param int segundo entero a multiplicar
 * \return total de la multiplicacion
 *
 */
int multiplicacion (int num1, int num2);

/** \brief factorial de un entero
 *
 * \param int entero
 * \return int 0 si el entero es 0, 1 si el entero es 1, si es mayor de 0 o 1 devuelve el total
 *
 */
unsigned long int factorial(int num);




#endif /* OPERACIONES_H_ */
