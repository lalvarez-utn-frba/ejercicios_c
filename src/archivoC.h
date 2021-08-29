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
#include <commons/collections/list.h>
#include <commons/collections/node.h>
#include <commons/string.h>

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


void destructorDeComidas(t_link_element* elem);

void list_clean_comidas(t_list *self);

void list_destroy_comidas(t_list *self) ;

void llenarLista(t_list* lista);

void aplicar_func_lista_en_file ( t_list* lista, char* (*funcion)( char*), archivo archivo );


void aplicar_funcion_archivo( char* (*funcion)(char*), archivo archivo );

void pasameAMinuscula(char* original);

void append_char( char* s,  char c);



#endif /* ARCHIVO_H_ */





