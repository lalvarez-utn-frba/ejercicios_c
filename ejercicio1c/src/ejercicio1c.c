/*
 ============================================================================
 Name        : ejercicio1c.c
 Author      : Luis Alvarez
 Version     :
 Copyright   : GNU
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*   Separa el mail en un usuario y un dominio.
*   Ejemplo:
*   char* mail = "ritchie@ansic.com.ar";
*   char* user;
*   char* dominio;
*   mail_split(mail, &user, &dominio);
*   =>
*   user = "ritchie"
*   dominio = "ansic.com.ar"
*/
void mail_split(const char* mail, char** user, char** dominio);


int main(void) {
	char* mail = "ritchie@ansic.com.ar";
	char* user;
	char* dominio;

	mail_split(mail, &user, &dominio); //ver ejercicio anterior por que se pasa la doble indireccion (&)

	printf("el usuario es: %s\n", user);
	printf("el dominio es: %s\n", dominio);

	free(user);
	free(dominio);

	return EXIT_SUCCESS;
}

/**
 * mail_split: buscamos la posicion del caracter @, copiamos desde la posicion siguiente con strcpy (este copia el string hasta encontrar UN \0 y no lo incluye, por eso se agrega con strcat a domain)
 * 				luego copiamos con strncpy, desde el inicio de mail, hasta el largo de user.
 */
void mail_split(const char* mail, char** user, char** dominio) {
	int arroba = '@';
	int mailStringLength = strlen(mail);
	char* ptDominio;
	int userStringLength;
	int domainStringLength;

	ptDominio = strchr(mail, arroba) + 1; // strchr busca la posicion donde aparece por primera vez el caracter del 2do param. Sumamos 1 para obtener el char siguiente.
	domainStringLength = strlen(ptDominio); // calcula el largo del dominio (cant de chars)
	userStringLength = mailStringLength - domainStringLength - 1; // se resta el arroba (-1)

	// copiar el dominio a una nueva posicion de memoria
	*dominio = malloc(sizeof(char) * (domainStringLength + 1)); // se reserva memoria para la cantidad de chars en el dominio + el null character \0.
	strcpy(*dominio, ptDominio); // se copia el contenido de ptDominio a dominio.
	strcat(*dominio, "\0");

	// copiar el usuario a una nueva posicion de memoria
	*user = malloc(sizeof(char) * (userStringLength + 1));
	strncpy(*user, mail, userStringLength);
	strcat(*user, "\0");


}
