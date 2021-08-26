/*
 * archivoC.h
 *
 *  Created on: 25 ago. 2021
 *      Author: utnso
 */

#ifndef ARCHIVOC_H_
#define ARCHIVOC_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum  {READ, WRITE, APPEND} modo_lectura;

typedef struct archivo {

	FILE* puntero_archivo;
	int esta_abierto;
	modo_lectura modo;
	char* ruta;

} archivo;


archivo abrir_archivo (char* path, modo_lectura modo);
void cerrar_archivo(archivo* archivo);


char* leer_linea(archivo archivo, int numero_linea);


#endif /* ARCHIVO_H_ */





