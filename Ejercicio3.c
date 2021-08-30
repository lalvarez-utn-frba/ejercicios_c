/*
 ============================================================================
 Name        : Ejercicio3.c
 Author      : joaco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "personas.h"


int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */


	archivo personasEntrada = abrir_archivo("/home/utnso/workspace/Ejercicio3/src/entrada.txt", READ);

	char* outp = leer_lineas(personasEntrada);

	cerrar_archivo(&personasEntrada);


	//free(outp);

	return EXIT_SUCCESS;
}


/*
 *
	Dado un archivo de texto que contiene un conjunto de personas, leerlo, procesarlo y
	generar la salida especificada. Recomendación: Revisar las funciones provistas en
	 la biblioteca commons-library de la cátedra.

	Archivo de entrada:
	Formato => Región; Nombre y Apellido; Edad; Número Telefónico; DNI; Saldo
	Cada renglón representa una persona, cada campo de la persona se encuentra separado
	 por un ‘;’ como delimitador (por lo tanto tienen campos de longitud variable).
	El archivo no sigue ningún orden.


	Archivo de salida:
	Formato => Región | Edad | DNI | Nombre y Apellido (30 chars máximo) | Número telefónico
	Cada renglón representa una persona.
	El archivo debe estar ordenado por Región y Edad.
	Filtrar los menores de edad (< 18 años).
	Loggear las personas cuyo saldo sea menor a 100$.
*
 */
