/*
 * procesar_archivos.c
 *
 *  Created on: 28 ago. 2021
 *      Author: utnso
 */
#include "procesar_archivos.h"

t_list* leer_archivo_entrada(FILE* archivo) {
	char* lineaLeida=0;
	size_t largoLinea = 0; //getline lee hasta encontrar un \0 o character nulo si el largo es 0.
	ssize_t readResult;
	t_list* listaPersonas = list_create();

	while ((readResult = getline(&lineaLeida, &largoLinea, archivo)) != -1) {
		persona persona = crear_persona_desde_string(lineaLeida);
		list_add(listaPersonas, &persona);
	}

	free(lineaLeida);

	return listaPersonas;
}

void procesar_archivos (FILE* archivoEntrada, FILE* archivoSalida) {
	t_list* listaPersonas = leer_archivo_entrada(archivoEntrada);
	t_list* listaOrdenada = ordenar_lista_personas(listaPersonas);

	list_destroy_and_destroy_elements(listaPersonas, (void*)*persona_destroy);
}
