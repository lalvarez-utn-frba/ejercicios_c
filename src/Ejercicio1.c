/*
 ============================================================================
 Name        : Ejercicio1.c
 Author      : joaco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* string_concat(const char*, const char*);
size_t memoria_total_concat(const char* cadena1,const char* cadena2);
void string_concat_dinamyc(const char*, const char*, char**);
void mail_split(const char* mail, char** user, char** dominio);
void append_char(char* s, char c) ;

int main (void) {

	/*
	puts("Hola\n");

	// backlash
	char str1[20];
	char str2[20];
	strcpy (str1,"To be "); // deberia darme 7
	strcpy (str2,"or not to be");
	//strncat (str1, str2, 6);

	puts("Hola\n");
	//printf("%d" ,strlen(str1));
	puts("\n");
	*/

	const char* cadena1 = "Hola";
	const char* cadena2 = "Mundo!";
	/*
	char* concatenado;

	concatenado = string_concat( cadena1, cadena2 );


	free(concatenado);
	*/

	// EJERCICIO 2

	char** saludo_completo;
	saludo_completo = malloc(sizeof(char**));
	string_concat_dinamyc(cadena1, cadena2, saludo_completo);

	puts("resultado");
	puts(*saludo_completo);

	free(saludo_completo);

	// EJERCICIO 3

	char* mailCompleto = "joaquinipar@miDominio.com";
	char** usuario;
	char** dominio;
	usuario= malloc(sizeof(char**));
	dominio = malloc(sizeof(char**));
	puts(mailCompleto);

	mail_split(mailCompleto, usuario, dominio);

	puts("pude salir");
	puts(*usuario);
	puts(*dominio);


	return 0;

}

char* string_concat(const char* cadena1, const char* cadena2){


	//yo al concatenar cadena1 y cadena2, no tengo que "matarlos",
	//solo creo una variable que apunte a una direccion de memoria nueva
	puts("entre a la funcion string_concat\n");
	puts(cadena1);
	puts(cadena2);

	int tamanio1 = strlen(cadena1); //+ 1 ; AL PRIMERO NO LE CUENTO EL NULL TERMINATOR, AL SEGUNDO SI!
	int tamanio2 = strlen(cadena2) +1;

	size_t tamanio_total;
	//printf("%d\n", tamanio1);
	//printf("%d\n", tamanio2);
	//puts("\n");
	//puts("tamanio en bytes de un char\n");
	//printf("%lu", sizeof(char));
	//puts("\n");

	size_t tamanio1_bytes = tamanio1 * (sizeof(char));
	size_t tamanio2_bytes = tamanio2 * (sizeof(char));


	//puts("bytes de tamanio1\n");

	//printf("%lu\n", tamanio1_bytes);
	//printf("%lu\n", tamanio2_bytes);

	//puts("Ahora vamos con el tamanio total\n");

	tamanio_total = tamanio1_bytes + tamanio2_bytes ; // creo que va el +1 ya que tiene que concatenarse el /0_
	//printf("%lu\n", tamanio_total);
	//char* resultado = malloc()

	char* concatenacion = malloc(tamanio_total);

	//printf("direccion primera: %p", concatenacion);

	memcpy(concatenacion, cadena1, tamanio1_bytes);

	//puts("\n");

	//printf("dir memoria de final cadena1 %p\n",concatenacion+tamanio1_bytes);

	//printf("voy a concatenar desde %p\n",concatenacion+tamanio1);

	memcpy(concatenacion+tamanio1, cadena2, tamanio2_bytes); //memcpy(dir_ultimo_caracter, cadena2, tamanio2_bytes);

	// H,O,L,A

	//puts("resultado de la concatenacion:\n");

	//printf("%s",concatenacion);

	//puts("\n");

	return concatenacion;// bancame

} // mempcpy puede servir para concatenaciones, ya que devuelve la dir de mem

size_t memoria_total_concat(const char* cadena1,const char* cadena2){ // Incluye el '\n'

	int tamanio1 = strlen(cadena1); //+ 1 ; AL PRIMERO NO LE CUENTO EL NULL TERMINATOR, AL SEGUNDO SI!
	int tamanio2 = strlen(cadena2) +1;

	size_t tamanio1_bytes = tamanio1 * (sizeof(char));
	size_t tamanio2_bytes = tamanio2 * (sizeof(char));

	return tamanio1_bytes + tamanio2_bytes;

}

void string_concat_dinamyc(const char* cadena1, const char* cadena2, char** cadenafinal){

	//Asigna en el tercer parámetro, la concatenación
	//de los primeros dos Strings


	//cadenafinal = malloc(sizeof(char**));

	char* concatenacionTemp = malloc(memoria_total_concat(cadena1, cadena2));
	memcpy(concatenacionTemp, string_concat(cadena1, cadena2),memoria_total_concat(cadena1, cadena2)) ;

	//puts("concatenacion temporal!");
	//printf("%s\n",concatenacionTemp);
	//printf("%p\n",concatenacionTemp);
	//printf("%p\n",&concatenacionTemp);
	//memcpy(cadenafinal,concatenancionTemp,sizeof(char**));

	memcpy(cadenafinal, &concatenacionTemp , sizeof(char**) );

	//printf("%p\n", cadenafinal);
	//printf("%s\n", *cadenafinal);

	//free(concatenacionTemp);
}

void mail_split(const char* mail, char** user, char** dominio){

	// El user y dominio ya me vienen inicializados

	int i=0;
	int flag_arroba = 0;
	int flag_punto = 0;

	char* usuario = "";

	char* userCharTemp = malloc(sizeof(char) * strlen(user) );
	char* dominioCharTemp = malloc(sizeof(char) * strlen(dominio) );
	//puts(mail);

	while( *(mail+i) != '\0'){

		//puts("hola");
		printf("%c\n", *(mail+i) );

		switch(*(mail+i)){

		case('@'):
			flag_arroba = 1;
			break;
		case('.'):
			flag_punto = 1;
			break;
		default:
			if( flag_arroba == 0){
				append_char(userCharTemp, *(mail+i));
			}
			else if( flag_punto == 0 && flag_arroba == 1){
				append_char(dominioCharTemp, *(mail+i));
			}
			else{
				// error

				}

			}
		i++;

		} // end while


		strcpy(user, userCharTemp);
		strcpy(dominio, dominioCharTemp);

		//puts(userCharTemp);
		//puts(dominioCharTemp);

		free(userCharTemp);
		free(dominioCharTemp);


	}



void append_char(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}


