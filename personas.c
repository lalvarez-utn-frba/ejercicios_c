/*
 * personas.c
 *
 *  Created on: 29 ago. 2021
 *      Author: utnso
 */

#include "personas.h"

char* leer_lineas(archivo archivoPersonas){

	puts("Estoy en leer lineas");

	if(archivoPersonas.esta_abierto == 1 && archivoPersonas.modo == READ){

	archivo salida; //

	salida = abrir_archivo("/home/utnso/workspace/Ejercicio3/personasSalida.txt", APPEND);

	char** lineas = NULL;
	char* linea = string_new();
	size_t tamanio = 0;
	ssize_t bytes_leidos = 0;
	int contador = 0;

	char* pais = NULL;
	char* nombreApellido = NULL;
	char* edad = NULL;
	char* numeroTelefono = NULL;
	char* documento = NULL;
	char* monto = NULL;

	char* concatenacion = NULL;
	size_t total = 0;
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

		total = 4 * strlen("|") + strlen(pais) + strlen(nombreApellido) + strlen(numeroTelefono) + strlen(edad) + strlen(documento) + strlen(monto) + 1;

		concatenacion = malloc(sizeof(char) * total );

		puts(pais);
		puts(nombreApellido);
		puts(edad);
		puts(numeroTelefono);
		puts(documento);
		puts(monto);


		/*
		 *  string_append_with_format(&string, "%s %s %d", "Hello", "world", 23);
            should_string(string) be equal to("Hello world 23");
		 */

		string_append_with_format(&concatenacion, "%s;%s;%s;%s;%s;%s;", pais,
																		nombreApellido,
																		edad,
																		numeroTelefono,
																		documento,
																		monto);



		//fwrite( concatenacion, sizeof(char), strlen(concatenacion)+1, salida.puntero_archivo);
		//fwrite( concatenacion, strlen(concatenacion)+1, 1, salida.puntero_archivo);
		fputs(concatenacion, salida.puntero_archivo);

		free(concatenacion);
		total=0;
		contador++;
		}//fin while


			free(pais);
			free(nombreApellido);
			free(edad);
			free(numeroTelefono);
			free(documento);
			free(monto);





		cerrar_archivo(&salida);

	}// fin if



	   return "PRUEBA!";
}
