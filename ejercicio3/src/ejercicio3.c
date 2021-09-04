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
#include <unistd.h>
#include <limits.h>

int main(void) {
	puts("!!!Procesando archivo!!!");

	FILE* archivoEntrada = fopen("./personas.txt", "r+");
	FILE* archivoSalida = fopen("./personasOrdenada.txt", "w+");
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	printf("Directorio de trabajo: %s\n", cwd);

	if (archivoEntrada == NULL) {
		perror("Error al abrir el archivo: ");
		printf("No se pudo abrir el archivo.\nComprueba si el archivo (personas.txt) existe en el path indicado y si tiene los permisos apropiados.\n");
		printf("Si el directorio de trabajo es /Debug (al correrlo en la terminal), podes llamar a la aplicacion desde la carpeta ejercicios_c/ejercicio3, escribiendo Debug/ejercicio3\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
	procesar_archivos(archivoEntrada, archivoSalida);

	fclose(archivoEntrada);
	fclose(archivoSalida);
	//free(archivoEntrada);
	//free(archivoSalida);

	return EXIT_SUCCESS;
}
