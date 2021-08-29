/*
 ============================================================================
 Name        : ejercicio3.c
 Author      : Luis Alvarez
 Version     :
 Copyright   : GNU
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "procesar_archivos.h"

int main(void) {
	puts("!!!Procesando archivo!!!");

	FILE* archivoEntrada = fopen("/home/utnso/Projects/ejercicios_c/ejercicio3/src/personas.csv", "r+");
	FILE* archivoSalida = fopen("/home/utnso/Projects/ejercicios_c/ejercicio3/src/personasOrdenado.csv", "w+");

	procesar_archivos(archivoEntrada, archivoSalida);

	fclose(archivoEntrada);
	fclose(archivoSalida);
	//free(archivoEntrada);
	//free(archivoSalida);

	return EXIT_SUCCESS;
}
