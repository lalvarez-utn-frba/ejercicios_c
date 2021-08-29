/*
 ============================================================================
 Name        : ejercicio2.c
 Author      : Luis Alvarez
 Version     :
 Copyright   : GNU
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "archivo.h"

void llenar_lista(t_list* lista);
char* toStringMock(void*);

int main(void) {

	t_archivo archivo = abrir_archivo("/home/utnso/prueba.txt", READ);
    char* lineaLeida = leer_linea_de_archivo(archivo, 2);
	printf("el path es: %s\n", archivo.path);
	printf("el estado es: %d\n", archivo.state);
	printf("el modo es: %d\n\n\n", archivo.mode);

	printf("la linea leida es: %s\n", lineaLeida);

	//free(archivo); MAL!
	// no llamar a free directamente, para evitar memory leaks
	// la idea es delegar la destruccion del recurso al TAD
	// si tiene TADs anidados, estos deberan encargarse de liberar sus recursos correspondientes.

	aplicar_funcion_a_lineas_archivo(archivo, *imprimir_por_consola);
	free(lineaLeida);
	cerrar_archivo(&archivo);

	archivo = abrir_archivo("/home/utnso/prueba.txt", APPEND);
	t_list* lista = list_create();
	llenar_lista(lista);
	escribir_lista_al_archivo(archivo, lista, *toStringMock);

	list_destroy(lista);
	cerrar_archivo(&archivo);

	return EXIT_SUCCESS;
}

void llenar_lista(t_list* lista) {
	list_add(lista, "hola\n");
	list_add(lista, "mundo\n");
	list_add(lista, "c\n");
	list_add(lista, "lista\n");
	list_add(lista, "chau\n");
}

char* toStringMock(void* string) {
	return (char*) string;
}
