/*
 * personas.c
 *
 *  Created on: 29 ago. 2021
 *      Author: utnso
 */

#include "personas.h"


char* generarArchivoSalidaOrdenado(char* ruta){

	puts("Estoy en leer lineas");

	archivo archivoPersonas = abrir_archivo(ruta, READ);

	if(archivoPersonas.esta_abierto == 1 && archivoPersonas.modo == READ){

	archivo salida; //

	salida = abrir_archivo("/home/utnso/workspace/Ejercicio3/personasSalida.txt", WRITE);

	t_list* listaPersonas = list_create();

	persona* nueva_persona = NULL;

	char** lineas = NULL;
	char* linea = NULL;
	size_t tamanio = 0;
	ssize_t bytes_leidos = 0;
	int contador = 0;

	char* pais = NULL;
	char* nombreApellido = NULL;
	char* edad = NULL;
	char* numeroTelefono = NULL;
	char* documento = NULL;
	char* monto = NULL;

	char* concatenacion;
	size_t total = 0;

	char nombreApellidoTemp[30] = "";


/*
	concatenacion = string_new();
	pais = string_new();
	nombreApellido = string_new();
			edad = string_new();
			numeroTelefono = string_new();
			documento = string_new();
			monto = string_new();
*/
	while( (bytes_leidos = getline(&linea, &tamanio, archivoPersonas.puntero_archivo) ) != -1 ){


		lineas = string_split(linea, ";");


		pais = malloc(sizeof(char) * (strlen(lineas[0]) +1) );
		strcpy(pais,lineas[0]);
		strcat(pais, "\0");

		nombreApellido = malloc(sizeof(char) * (strlen(lineas[1]) +1) );
		strcpy(nombreApellido, lineas[1]);
		strcat(nombreApellido, "\0");

		edad = malloc(sizeof(char) * (strlen(lineas[2]) +1) );
		strcpy(edad, lineas[2]);
		strcat(edad, "\0");

		numeroTelefono = malloc(sizeof(char) * (strlen(lineas[3]) +1) );
		strcpy(numeroTelefono, lineas[3]);
		strcat(numeroTelefono, "\0");

		documento = malloc(sizeof(char) * (strlen(lineas[4]) +1) );
		strcpy(documento, lineas[4]);
		strcat(documento, "\0");

		monto = malloc(sizeof(char) * (strlen(lineas[5]) +1) );
		strcpy(monto, lineas[5]);
		strcat(monto, "\0");


		//strncpy(nombreApellidoTemp , nombreApellido, strnlen(nombreApellido, 30));

		nueva_persona = malloc( sizeof(persona) );

		nueva_persona->region = malloc(sizeof(char) * (strlen(pais) +1) );

		nueva_persona->numeroTelefono = malloc( sizeof(char) * (strlen(numeroTelefono)+1) );

		char * tem = string_duplicate(pais); // aca malloquea

		strcpy(nueva_persona->region, tem );
		strcat(nueva_persona->region, "\0");

		strncpy(nueva_persona->nombreApellido, nombreApellido, strnlen(nombreApellido, 30)); //esto se puede mejorar, mirar el final de la cadena

		nueva_persona->edad = atoi(edad);

		strcpy(nueva_persona->numeroTelefono, string_duplicate(numeroTelefono)); // aca malloquea
		strcat(nueva_persona->numeroTelefono, "\0");

		nueva_persona -> documento = atoi(documento);

		nueva_persona->monto = atoi(monto);

		list_add(listaPersonas, nueva_persona);

		// TODO ORDENAR LISTA!!!

		// EJEMPLO DE FUNCION  COMPARATOR

		/*
		 * static bool _ayudantes_menor(t_person *joven, t_person *menos_joven) {
    return joven->age <= menos_joven->age;
}
		 *
		 */





		total =  4 * strlen("|") + strlen(pais) + strlen(nombreApellido) + strlen(numeroTelefono) + strlen(edad) + strlen(documento) + strlen(monto) + 1;

		concatenacion = malloc(sizeof(char) * total );
		strcpy(concatenacion, "\0");

		puts(pais);
		puts(nombreApellido);
		puts(edad);
		puts(numeroTelefono);
		puts(documento);
		puts(monto);

		string_append_with_format(&concatenacion, "%s|%s|%s|%s|%s|%s|", pais,
																		nombreApellido,
																		edad,
																		numeroTelefono,
																		documento,
																		monto);

		string_append(&concatenacion, "\n");

		//fwrite( concatenacion, sizeof(char), strlen(concatenacion)+1, salida.puntero_archivo);
		//fwrite( concatenacion, strlen(concatenacion)+1, 1, salida.puntero_archivo);

		// AL FPUTS LO VOY A TENER QUE MOVER A AFUERA, ACA DENTRO YO ME ENCARGO DE CARGAR LA LISTA Y AFUERA ESCRIBO EL ARCHIVO

		//fputs(concatenacion, salida.puntero_archivo);

		free(concatenacion);

		free(pais);
		free(nombreApellido);
		free(edad);
		free(numeroTelefono);
		free(documento);
		free(monto);


		free(lineas[0]);
		free(lineas[1]);
		free(lineas[2]);
		free(lineas[3]);
		free(lineas[4]);
		free(lineas[5]);
		free(lineas[6]);


		free(lineas);

		//free(nueva_persona->numeroTelefono);
		//free(nueva_persona->region);              Ahora que estoy guardando en la lista, no lo tengo que liberar aca
		//free(nueva_persona);



		total=0;
		contador++;

		}//fin while



		list_sort(listaPersonas, &comparadorRegionEdad);

		puts("holaaaa");

		cerrar_archivo(&archivoPersonas);

		total =  4 * strlen("|") + strlen(pais) + strlen(nombreApellido) + strlen(numeroTelefono) + strlen(edad) + strlen(documento) + strlen(monto) + 1;

		/*
		concatenacion = NULL;
		concatenacion = malloc(sizeof(char) * total );

		strcpy(concatenacion, "\0");
*/

		char* regionSalida=NULL;
		char* nombreApellidoSalida = NULL;
		int edadSalida;
		char* numeroTelefonoSalida = NULL;
		int documentoSalida;
		int montoSalida;



		archivoPersonas = abrir_archivo(ruta, READ);


		t_list_iterator* iterador_personas = list_iterator_create(listaPersonas);

		list_iterator_next(iterador_personas);


		while(list_iterator_has_next(iterador_personas)){

			concatenacion = string_new();

			regionSalida = strdup(((persona*)(iterador_personas->element->data))->region);
			nombreApellidoSalida = strdup(((persona*)(iterador_personas->element->data))->nombreApellido);
			edadSalida = ((persona*)(iterador_personas->element->data))->edad;
			numeroTelefonoSalida = strdup(((persona*)(iterador_personas->element->data))->numeroTelefono);
			documentoSalida = ((persona*)(iterador_personas->element->data))->documento;
			montoSalida = ((persona*)(iterador_personas->element->data))->monto;


			string_append_with_format(&concatenacion, "%s|%s|%i|%s|%i|%i|", regionSalida,
																			nombreApellidoSalida,
																			edadSalida,
																			numeroTelefonoSalida,
																			documentoSalida,
																			montoSalida);

			string_append(&concatenacion, "\n");


			fputs(concatenacion, salida.puntero_archivo);


			list_iterator_next(iterador_personas);

			free(regionSalida);
			free(nombreApellidoSalida);
			free(numeroTelefonoSalida);
			free(concatenacion);

			if(!list_iterator_has_next(iterador_personas)){

				concatenacion = string_new();

				regionSalida = strdup(((persona*)(iterador_personas->element->data))->region);
				nombreApellidoSalida = strdup(((persona*)(iterador_personas->element->data))->nombreApellido);
				edadSalida = ((persona*)(iterador_personas->element->data))->edad;
				numeroTelefonoSalida = strdup(((persona*)(iterador_personas->element->data))->numeroTelefono);
				documentoSalida = ((persona*)(iterador_personas->element->data))->documento;
				montoSalida = ((persona*)(iterador_personas->element->data))->monto;


				string_append_with_format(&concatenacion, "%s|%s|%i|%s|%i|%i|", regionSalida,
																				nombreApellidoSalida,
																				edadSalida,
																				numeroTelefonoSalida,
																				documentoSalida,
																				montoSalida);

				string_append(&concatenacion, "\n");

				fputs(concatenacion, salida.puntero_archivo);

				free(regionSalida);
						free(nombreApellidoSalida);
						free(numeroTelefonoSalida);
						free(concatenacion);

			}




		}







		list_iterator_destroy(iterador_personas);

		cerrar_archivo(&archivoPersonas);

		free(linea);

		// TODO list_free(listaPersonas);


		cerrar_archivo(&salida);


	}// fin if


		puts("hlaaa");


	   return "PRUEBA!";
}




bool comparadorRegionEdad(persona* persona1, persona* persona2){


	char* regionPersona1= NULL;
	char* regionPersona2 = NULL;
	bool resultado = false;

	regionPersona1 = strdup(persona1->region);
	regionPersona2 = strdup(persona2->region);

	int cmp_resultado = strcmp(regionPersona1, regionPersona2);

	if( cmp_resultado == 0){

		if (persona1->edad < persona2->edad) {
			resultado = true;
		} else if (persona1->edad > persona2->edad) {
			resultado = false;
		} else {
			resultado = true;
		}
	} else if(cmp_resultado < 0) {
		resultado = true;
	}


	return resultado;

}

