/*
 * procesar_archivos.c
 *
 *  Created on: 28 ago. 2021
 *      Author: utnso
 */
#include "procesar_archivos.h"

static bool comparadorPersona(persona*, persona*);

static bool soloMayores(persona*);

static bool soloMayores(persona* p) {
	return p->edad > 18;
}

static void logearPersonasConSaldoMenorACien(t_list* personas);

static void logearPersonasConSaldoMenorACien(t_list* personas) {
	persona* p = NULL;
	t_list_iterator* iterator = list_iterator_create(personas);

	while (list_iterator_has_next(iterator)) {
		p = list_iterator_next(iterator);
		if (p->saldo < 100) {
			printf("%s tiene un saldo de: %d\n", p->nombre_apellido, p->saldo);
		}
	}

	list_iterator_destroy(iterator);
}

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
	return string_from_format("%s | %i | %i | %s | %i", unaPersona->region, unaPersona->edad, unaPersona->dni, unaPersona->nombre_apellido, unaPersona->telefono);
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
}

void procesar_archivos (FILE* archivoEntrada, FILE* archivoSalida) {
	t_list* listaPersonas = leer_archivo_entrada(archivoEntrada);
	list_sort(listaPersonas, (void*) comparadorPersona);

	t_list* personasMayoresOrdenadas = list_filter(listaPersonas, (void*) soloMayores);

	escribir_archivo_salida_personasOrdenadas(archivoSalida, personasMayoresOrdenadas);

	logearPersonasConSaldoMenorACien(listaPersonas);

	list_destroy_and_destroy_elements(listaPersonas, (void*) *persona_destroy);
	list_destroy(personasMayoresOrdenadas);
}
