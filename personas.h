/*
 * personas.h
 *
 *  Created on: 29 ago. 2021
 *      Author: utnso
 */

#include "./archivoC.h"

#ifndef PERSONAS_H_
#define PERSONAS_H_


typedef struct persona {
	char* region;
	int edad;
	int documento;
	char nombreApellido[30];
	char numeroTelefono;
} persona;


char* leer_lineas(archivo archivoPersonas);



#endif /* PERSONAS_H_ */
