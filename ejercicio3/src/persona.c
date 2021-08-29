/*
 * persona.c
 *
 *  Created on: 28 ago. 2021
 *      Author: utnso
 */

#include <string.h>
#include "persona.h"

int string_bytes_size(char* string) {
	return sizeof(char) * (strlen(string) + 1);
}

void string_copy(char** dest, char* origin) {
	*dest = calloc(strlen(origin) + 1, sizeof(char));
	strcpy(*dest, origin);
	strcat(*dest, "\0");
}

persona crear_persona_desde_string (char* linea) {
	persona p;
	char** campos = string_split(linea, ";");
	char* ptr = NULL;

	string_copy(&p.region, campos[0]);
	string_copy(&p.nombre_apellido, campos[1]);
	p.edad = strtol(campos[2], &ptr, 10);
	p.telefono = strtol(campos[3], &ptr, 10);
	p.dni = strtol(campos[4], &ptr, 10);
	p.saldo = strtod(campos[5], &ptr);

	free(campos);
	//free(ptr);

	return p;
}

void persona_destroy(persona* p) {
	free(&p->nombre_apellido);
	free(&p->region);
	//free(p);
}
