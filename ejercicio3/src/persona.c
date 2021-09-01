/*
 * persona.c
 *
 *  Created on: 28 ago. 2021
 *      Author: utnso
 */

#include "persona.h"

persona* crear_persona_desde_string (char* linea) {
	persona* p = malloc(sizeof(persona));
	char** campos = string_split(linea, ";");
	char* ptr = NULL;

	p->region = strdup(campos[0]);
	p->nombre_apellido = strdup(campos[1]);
	p->edad = strtol(campos[2], &ptr, 10);
	p->telefono = strtol(campos[3], &ptr, 10);
	p->dni = strtol(campos[4], &ptr, 10);
	p->saldo = strtod(campos[5], &ptr);

	free(campos[0]);
	free(campos[1]);
	free(campos[2]);
	free(campos[3]);
	free(campos[4]);
	free(campos[5]);
	free(campos);

	return p;
}

void persona_destroy(persona* p) {
	free(p->nombre_apellido);
	free(p->region);
	free(p);
}
