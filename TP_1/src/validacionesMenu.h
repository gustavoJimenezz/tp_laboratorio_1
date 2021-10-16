/*
 * validacionesMenu.h
 *
 *  Created on: 25 sep. 2021
 *      Author: G
 */

#ifndef VALIDACIONESMENU_H_
#define VALIDACIONESMENU_H_

//funciones de menu me (faltan los doxigen)

/** \brief muestra el menu completo
 *
 * \param int trigger1 condicional para otra funcion dentro de esta funcion menu
 * \param int trigger2 condicional para funcion dentro de esta funcion menu
 * \param int trigger3 condicional para funcion dentro de esta funcion menu
 * \param int operandoA valor de operando A
 * \param int operandoB valor de operando B
 * \return opcion elegida por el usuario
 *
 */
int menu (int trigger1, int trigger2,int trigger3,int operandoA, int operandoB);

/** \brief intercambia valor X y Y por valores ingresados(dentro de funcion menu)
 *
 * \param   char texto1 texto sin intercambio de valores
 * \param   char texto2 texto con intercambio de valores
 * \return void
 *
 */
void menuOpc3 (int trigger,int operandoA, int operandoB);

/** \brief valida que el entero ingresado sea positivo
 *
 * \param char texto[]  texto para ingresar dato
 * \param int operando numero ingresado para la validacion
 * \return int  valor que se ingreso ya validado
 */
int peticionNumPositivo(char texto[], char textoError[], int operando);

/** \brief muestra error en caso de que el trigger no este activado
 *
 * \param textoError[] texto de error
 * \param trigger int trigger que activa o desactiva el mensaje de error
 * \return int cero si es error , uno si es valido
 *
 */
int activador(char textoError[],int trigger);


#endif /* VALIDACIONESMENU_H_ */
