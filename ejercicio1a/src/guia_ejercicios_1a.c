/*
 ============================================================================
 Name        : guia_ejercicios2.c
 Author      : Luis Alvarez
 Version     :
 Copyright   : GNU
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_concat(const char*, const char*);

int main(void) {
	char* a = "Hola ";
	char* b = "Mundo!";

	char* c = string_concat(a, b);

	printf("%s\n", c);
	free(c);

	return EXIT_SUCCESS;
}

char* string_concat(const char* a, const char* b) {

	int sizeOfA = sizeof(char) * strlen(a);
	int sizeOfB = sizeof(char) * strlen(b);

  	char* newString = malloc( sizeOfA + sizeOfB +1);
	//char* newString = calloc(strlen(a) + strlen(b) +1 ,sizeof(char));

	/*if (newString == NULL) {
	        printf("Memory not allocated.\n");
	 }*/

	strcpy(newString, a);
	strcat(newString, b);
	strcat(newString, "\0");

	return newString;
}

