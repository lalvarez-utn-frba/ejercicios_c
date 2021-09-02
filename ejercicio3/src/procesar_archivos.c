/*
 * procesar_archivos.c
 *
 *  Created on: 28 ago. 2021
 *      Author: utnso
 */
#include "procesar_archivos.h"

void iteratorListPersonas(persona* unaPersona){
	printf("%s\n", unaPersona->region );
	printf("%d\n", unaPersona->edad);
	printf("%s\n", unaPersona->nombre_apellido);
	printf("%f\n", unaPersona->saldo);
	printf("%d\n", unaPersona->dni);
	printf("%d\n", unaPersona->telefono);
}

static bool comparadorPersona(persona*, persona*);

t_list* leer_archivo_entrada(FILE* archivo) {
	char* lineaLeida=0;
	size_t largoLinea = 0; //getline lee hasta encontrar un \0 o character nulo si el largo es 0.
	ssize_t readResult;
	t_list* listaPersonas = list_create();
	persona* persona;

	while ((readResult = getline(&lineaLeida, &largoLinea, archivo)) != -1) {
		persona = crear_persona_desde_string(lineaLeida);
		list_add(listaPersonas, persona);
	}

	free(lineaLeida);

	return listaPersonas;
}

static bool comparadorPersona(persona* p1, persona* p2) {
	char* tmpRegionP1 = NULL;
	char* tmpRegionP2 = NULL;
	int compareResult = false;
	bool result = false;

	tmpRegionP1 = strdup(p1->region);
	tmpRegionP2 = strdup(p2->region);
	string_to_lower(tmpRegionP1);
	string_to_lower(tmpRegionP2);

	compareResult = strcmp(tmpRegionP1, tmpRegionP2);

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

	free(tmpRegionP1);
	free(tmpRegionP2);

	return result;
}

char* agregar_campo_lineaAEscribir(persona* unaPersona){
	char* linea_a_escribir = NULL;
	//linea_a_escribir = "\0";
	int tamLineaAEscribir = 0;
	//Región | Edad | DNI | Nombre y Apellido (30 chars máximo) | Número telefónico

	int sizeRegion = sizeof(char)*strlen(unaPersona->region);
    linea_a_escribir = malloc(sizeRegion);
    strncpy(linea_a_escribir, unaPersona->region, sizeRegion+1);
	tamLineaAEscribir = sizeRegion;

	char* edad = NULL;
	int lengthEdad = snprintf( NULL, 0, "%d", unaPersona->edad);
	edad = malloc(lengthEdad + 1);
	snprintf(edad, lengthEdad + 1, "%d", unaPersona->edad);
	tamLineaAEscribir = tamLineaAEscribir + lengthEdad;

	char* dni = NULL;
	int lengthDni = snprintf( NULL, 0, "%d", unaPersona->dni);
	dni = malloc(lengthDni + 1 );
	snprintf(dni, lengthDni + 1, "%d", unaPersona->dni);
	tamLineaAEscribir = tamLineaAEscribir + lengthDni;

	char nombre[30];
    snprintf(nombre, 30, "%s", unaPersona->nombre_apellido);
    tamLineaAEscribir = tamLineaAEscribir + 30;

    char* numeroTelefonico= NULL;
	int lengthNumeroTelefonico= snprintf( NULL, 0, "%d", unaPersona->telefono);
	numeroTelefonico = malloc(lengthNumeroTelefonico + 1 );
	snprintf(numeroTelefonico, lengthDni + 1, "%d", unaPersona->dni);
	tamLineaAEscribir = tamLineaAEscribir + lengthNumeroTelefonico + 1 + 4;


    linea_a_escribir = realloc(linea_a_escribir, tamLineaAEscribir);
    strcat(linea_a_escribir, "|");
    strncat(linea_a_escribir, edad , strlen(edad));
    strcat(linea_a_escribir, "|");
    strncat(linea_a_escribir, dni , strlen(dni));
    strcat(linea_a_escribir, "|");
    strncat(linea_a_escribir, nombre , 30);
    strcat(linea_a_escribir, "|");
    strncat(linea_a_escribir, numeroTelefonico , strlen(numeroTelefonico));

    free(edad);
    free(dni);
    //free(unaPersona->nombre_apellido);
    free(numeroTelefonico);
    //free(unaPersona);

	return linea_a_escribir;

}



void escribir_archivo_salida_personasOrdenadas(FILE* archivoSalida, t_list* listaPersonas){

	fseek(archivoSalida, 0, SEEK_END);
	char* linea_a_escribir = NULL;

	t_list_iterator* listIteratorPersonasOrdenadas = list_iterator_create(listaPersonas);

	while(list_iterator_has_next(listIteratorPersonasOrdenadas)) {
		linea_a_escribir = agregar_campo_lineaAEscribir(list_iterator_next(listIteratorPersonasOrdenadas));
		fputs(linea_a_escribir,archivoSalida);
		fputs("\n",archivoSalida);
		fseek(archivoSalida, 0, SEEK_END);
		free(linea_a_escribir);

			}

	list_iterator_destroy(listIteratorPersonasOrdenadas);
	//free(linea_a_escribir);
}

void procesar_archivos (FILE* archivoEntrada, FILE* archivoSalida) {
	t_list* listaPersonas = leer_archivo_entrada(archivoEntrada);
	list_sort(listaPersonas, (void*) comparadorPersona);
	//list_iterate(listaPersonas, (void*)iteratorListPersonas);

	escribir_archivo_salida_personasOrdenadas(archivoSalida, listaPersonas);

	list_destroy_and_destroy_elements(listaPersonas, (void*) *persona_destroy);
}
