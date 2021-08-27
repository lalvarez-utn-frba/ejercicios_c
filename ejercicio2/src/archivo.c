/*
 * archivo.c
 *
 *  Created on: 22 ago. 2021
 *      Author: utnso
 */

#include "archivo.h"

t_archivo abrir_archivo(char* path, t_mode mode) {

	t_archivo file;

	file.path = malloc(sizeof(char) * (strlen(path) + 1));
	strcpy(file.path, path);
	strcat(file.path, "\0");

	file.mode = mode;
	file.state = CLOSED;

	switch (mode) {
	case READ:
		file.file = fopen(path, "r");
		file.state = OPEN;
		break;
	case WRITE:
		file.file = fopen(path, "w");
		file.state = OPEN;
		break;
	case APPEND:
		file.file = fopen(path, "a");
		file.state = OPEN;
		break;
	case READ_WRITE:
		file.file = fopen(path, "r+");
		file.state = OPEN;
		break;
	}

	return file;
}

void cerrar_archivo(t_archivo* archivo) {
	fclose(archivo->file);
	free(archivo->path);
}

/**
 * Lee el numero de linea pasado por parametro de archivo, se asume que el archivo esta abierto
 */
char* leer_linea_de_archivo(t_archivo archivo, int numero_linea) {
	char* lineaLeida=0;
	size_t largoLinea = 0; //getline lee hasta encontrar un \0 o character nulo si el largo es 0.
	ssize_t readResult;
	const char* NOT_FOUND = "NOT FOUND";

	int lineaActual = 0;

	while ((readResult = getline(&lineaLeida, &largoLinea, archivo.file)) != -1 && lineaActual <= numero_linea) {
		if (lineaActual == numero_linea) {
			break;
		}
		lineaActual++;
	}

	// rebobinamos el vhs
	fseek(archivo.file, 0, SEEK_SET);

	// se paso del tamanio de archivo, asi que hay que limpiar la ultima linea leida y retornar el error
	// hay que corregir el manejo de errores, pero ¯\_(ツ)_/¯
	if (lineaActual < numero_linea) {
		free(lineaLeida);
		lineaLeida = malloc(sizeof(char) * (strlen(NOT_FOUND) + 1));
		strcpy(lineaLeida, NOT_FOUND);
		return lineaLeida;
	}

	strcat(lineaLeida, "\0");
	return lineaLeida;
}

void imprimir_por_consola(char* unaLinea){
	printf("Linea leida: %s\n", unaLinea);
}

void aplicar_funcion_a_lineas_archivo(t_archivo archivo, void (*funcion)(char* linea)){
	size_t largoLinea=0;
	ssize_t readResult;
	char* lineaLeida =0;
	int lineaActual = 0;
	while ((readResult = getline(&lineaLeida, &largoLinea, archivo.file)) != -1) {
		strcat(lineaLeida, "\0");
		funcion(lineaLeida);
		lineaActual++;
	}
	free(lineaLeida);
}

void escribir_string_al_archivo(t_archivo archivo, char* cadena) {
	//fseek(archivo.file, 0, SEEK_END);
	fputs(cadena, archivo.file);
}

void escribir_lista_al_archivo(t_archivo archivo, t_list* lista, char* (*funcion)(t_link_element* element)){
	char* stringAEscribir = NULL;
	t_list_iterator* listIterator = list_iterator_create(lista);

	while(list_iterator_has_next(listIterator)) {
		t_link_element* listElement = list_iterator_next(listIterator);
		stringAEscribir = (char*) funcion(listElement);
		escribir_string_al_archivo(archivo, stringAEscribir);
		free(stringAEscribir);
	}
}
