/*
 * persona.h
 *
 *  Created on: 27 ago. 2021
 *      Author: utnso
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#include "stdlib.h"
#include <commons/string.h>


typedef struct t_persona {
	char* region;
	char* nombre_apellido;
	int edad;
	int telefono;
	int dni;
	double saldo;
} persona;

persona crear_persona_desde_string (char* linea);

void persona_destroy(persona* p);

#endif /* PERSONA_H_ */
