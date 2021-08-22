/*
 ============================================================================
 Name        : ejercicio2.c
 Author      : Luis Alvarez
 Version     :
 Copyright   : GNU
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "archivo.h"

int main(void) {
	t_archivo* archivo = abrir_archivo("/home/utnso/prueba.txt", READ);
	printf("el path es: %s\n", archivo->path);
	printf("el estado es: %d\n", archivo->state);
	printf("el modo es: %d\n", archivo->mode);
	//free(archivo); MAL!
	// no llamar a free directamente, para evitar memory leaks
	// la idea es delegar la destruccion del recurso al TAD
	// si tiene TADs anidados, estos deberan encargarse de liberar sus recursos correspondientes.
	cerrar_archivo(archivo);

	return EXIT_SUCCESS;
}
