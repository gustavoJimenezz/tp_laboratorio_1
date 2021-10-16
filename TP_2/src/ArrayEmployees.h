/*
 * ArrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: G
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;


/** \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all
 *         position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief Agrega datos a la estructura Employee en un indice libre.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Devuelve (1) si Error [Longitud no válida o puntero NULL o sin
               espacio libre] - (0) si está bien
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (1) if [Invalid length or NULL
           pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (1) if Error [Invalid length or NULL pointer or if can't
           find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int tam, int id);


/** \brief Sort the elements in the array of employees, the argument order
           indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len, int order);


/** \brief Sort employee matrix by ID in ascending order.
 *
 * \param list[] Employee
 * \param len int
 * \return int Returns (1) if Error [Invalid length or NULL pointer or no
               free space] - (0) if ok
 *
 */
int sortEmployeesById(Employee list[], int len);


/** \brief Displays the first name, last name, salary, factor data of an Employee structure.
 *
 * \param empleado Employee
 * \return void
 *
 */
void printEmployee(Employee empleado);


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int Devuelve (1) si Error [Longitud no válida o puntero NULL o sin
               espacio libre] - (0) si está bien
 *
 */
int printEmployees(Employee list[], int len);



/** \brief Look for a structure with isEmpty of value 0 that is considered free.
 *
 * \param list[] Employee
 * \param len int
 * \return int position in the vector with isEmpty of value 0 or -1 in case of not finding
 *
 */
int searchFree(Employee list[], int len);


#endif /* ARRAYEMPLOYEES_H_ */
