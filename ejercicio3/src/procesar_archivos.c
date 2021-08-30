/*
 * procesar_archivos.c
 *
 *  Created on: 28 ago. 2021
 *      Author: utnso
 */
#include "procesar_archivos.h"

static t_list* ordenar_lista_personas(t_list* listaPersonas);
static bool comparadorPersona(persona*, persona*);

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

bool comparadorPersona(persona* p1, persona* p2) {
	char** tmpRegionP1 = NULL;
	char** tmpRegionP2 = NULL;
	int compareResult = false;
	bool result = false;

	string_copy(tmpRegionP1, p1->region);
	string_copy(tmpRegionP2, p2->region);
	string_to_lower(*tmpRegionP1);
	string_to_lower(*tmpRegionP2);

	compareResult = strcmp(*tmpRegionP1, *tmpRegionP2);

	if (compareResult == 0) {
		if (p1->edad < p2->edad) {
			result = true;
		} else if (p1->edad > p2->edad) {
			result = false;
		} else {
			result = true;
		}
	} else if(compareResult < 0) {
		result = true;
	}

	free(*tmpRegionP1);
	free(*tmpRegionP2);

	return result;
}

t_list* ordenar_lista_personas(t_list* listaPersonas) {
	t_list* listaOrdenada = list_sorted(listaPersonas, (void*) comparadorPersona);

	return listaOrdenada;
}

void procesar_archivos (FILE* archivoEntrada, FILE* archivoSalida) {
	t_list* listaPersonas = leer_archivo_entrada(archivoEntrada);
	t_list* listaOrdenada = ordenar_lista_personas(listaPersonas);

	list_destroy_and_destroy_elements(listaPersonas, (void*)*persona_destroy);
}
