/*
 * archivo.h
 *
 *  Created on: 22 ago. 2021
 *      Author: utnso
 */

#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	CLOSED,
	OPEN
} t_state;

typedef enum {
	READ,
	WRITE,
	APPEND
} t_mode;

typedef struct archivo {
	char* path;
	t_mode mode;
	t_state state;
	FILE* file;
} t_archivo;

t_archivo* abrir_archivo(char* path, t_mode mode);

void cerrar_archivo(t_archivo* archivo);

char* leer_linea_de_archivo(t_archivo* archivo);



#endif /* ARCHIVO_H_ */
