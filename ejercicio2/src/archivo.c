/*
 * archivo.c
 *
 *  Created on: 22 ago. 2021
 *      Author: utnso
 */

#include "archivo.h"

t_archivo* abrir_archivo(char* path, t_mode mode) {
	t_archivo* file;
	file = malloc(sizeof(t_archivo));

	file->path = malloc(sizeof(char) * (strlen(path) + 1));
	strcpy(file->path, path);
	strcat(file->path, "\0");

	file->mode = mode;
	file->state = CLOSED;

	switch (mode) {
	case READ:
		file->file = fopen(path, "r");
		file->state = OPEN;
		break;
	case WRITE:
		file->file = fopen(path, "w");
		file->state = OPEN;
		break;
	case APPEND:
		file->file = fopen(path, "a");
		file->state = OPEN;
		break;
	}

	return file;
}

void cerrar_archivo(t_archivo* archivo) {
	fclose(archivo->file);
	free(archivo->path);
	free(archivo);
}
