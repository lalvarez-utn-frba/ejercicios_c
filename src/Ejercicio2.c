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

	//char* ruta = "/home/utnso/Documentos/Ejercicio2/archivazo.txt";

	/*
	archivo nuevo_archivo = abrir_archivo(ruta, READ);

	char* nueva_linea = leer_linea(nuevo_archivo,2);

	cerrar_archivo(&nuevo_archivo);

	free(nueva_linea);
	*/

	/*
	char* nombre = string_new();
	char* saludo = "Hola!!!;";

	strcpy(nombre, "Joaquin");
	strcat(nombre, "\0");

	puts(appendSaludo(nombre, saludo));

*/


	/* prueba de aplicar_funcion_archivo */
	/*
	char* ruta = "/home/utnso/Documentos/Ejercicio2/archivazo.txt";


	archivo nuevo_archivo = abrir_archivo(ruta, READ);


	aplicar_funcion_archivo(&pasameAMinuscula, nuevo_archivo );

	cerrar_archivo(&nuevo_archivo);
	*/


	char* ruta = "/home/utnso/Documentos/Ejercicio2/archivazo.txt";
	archivo nuevo_archivo = abrir_archivo(ruta, APPEND);

	// Prueba de creacion de lista

	t_list* miListaDeComidas = list_create();

	// Ahora quiero crear un elemento para agregar a mi lista :)

	list_add(miListaDeComidas, "PIZZA");
	list_add(miListaDeComidas, "HAMBURGUESA");
	list_add(miListaDeComidas, "ASADO");
	list_add(miListaDeComidas, "ARROZ");
	list_add(miListaDeComidas, "FIDEO");

	aplicar_func_lista_en_file(miListaDeComidas, &string_reverse, nuevo_archivo);
	//list_iterate(miListaDeComidas, &puts);
	puts("hola");

	list_destroy(miListaDeComidas);
	cerrar_archivo(&nuevo_archivo);

	puts("hola");

	return 0;//EXIT_SUCCESS;
}





