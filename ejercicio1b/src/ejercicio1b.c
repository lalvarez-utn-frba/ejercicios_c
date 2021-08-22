/*
 ============================================================================
 Name        : guia_ejercicios1b.c
 Author      : Luis Alvarez
 Version     :
 Copyright   : GNU
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_concat_dinamyc(const char*, const char*, char**);

int main(void) {
	char* b = "Juan Carlos!";
	char* c;

	string_concat_dinamyc("Hola ", b, &c); //c es un puntero, &c es doble indireccion (puntero a un puntero de char), para poder pisar c, porque se pasa por valor caso contrario.

	printf("%s\n", c);
	free(c);
	return EXIT_SUCCESS;
}

/**
 * string_concat_dinmyc
 * @param char* a: string a concatenar
 * @param char* b: string a concatenar
 * @param char** dest: Destino que va a contener la union de a y b. Es una doble indireccion (puntero a un puntero de char{string}). Es asi para poder cambiar el puntero no inicializado por uno inicializado por malloc.
 */
void string_concat_dinamyc(const char* a, const char* b , char** dest ) {
	int sizeOfA = sizeof(char) * strlen(a);
	int sizeOfB = sizeof(char) * strlen(b);

	//malloc devuelve un puntero nuevo con el espacio reservado en memoria, y pisa el puntero no inicializado que recibimos.
    *dest = malloc(sizeOfA + sizeOfB + 1);

    //se copia el contenido de a y b en *dest
    strcat(*dest, a);
	strcat(*dest, b);
}

