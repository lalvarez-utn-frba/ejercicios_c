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
#include <commons/collections/list.h>

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

char* leer_linea_de_archivo(t_archivo* archivo, int numero_linea);

t_archivo* aplicar_funcion_a_lineas_archivo(t_archivo* archivo, char* (*funcion)(char* linea));

t_archivo* escribir_lista_al_archivo(t_archivo* archivo, t_list* lista, char* (*funcion)(t_list* lista));

#endif /* ARCHIVO_H_ */
