/*
 ============================================================================
 Name        : Ejercicio2.c
 Author      : joaco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include "archivoC.h"

int main(void) {

	char* ruta = "/home/utnso/Documentos/Ejercicio2/archivazo.txt";

	archivo nuevo_archivo = abrir_archivo(ruta, READ);

	char* nueva_linea = leer_linea(nuevo_archivo,2);

	cerrar_archivo(&nuevo_archivo);

	free(nueva_linea);

	return 0;//EXIT_SUCCESS;
}
