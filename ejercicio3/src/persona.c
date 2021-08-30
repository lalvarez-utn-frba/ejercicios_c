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
	p.region = NULL;
	p.nombre_apellido = NULL;

	char** campos = string_split(linea, ";");
	//char* ptr = NULL;

	//strcpy(p.region, campos[0]);
	//strcpy(p.nombre_apellido, campos[1]);
	p.region = campos[0];
	p.nombre_apellido = campos[1];
	p.edad = atoi(campos[2]);
	p.telefono = atoi(campos[3]);
	p.dni = atoi(campos[4]);
	p.saldo = atoi(campos[5]);

    //free(p.region);
    //free(p.nombre_apellido);
	free(campos[1]);
	free(campos[2]);
	free(campos[3]);
	free(campos[4]);
	free(campos[5]);
	free(campos);

	//free(ptr);

	return p;
}

void persona_destroy(persona* p) {
	free(p->nombre_apellido);
	free(p->region);
	free(p);
}
