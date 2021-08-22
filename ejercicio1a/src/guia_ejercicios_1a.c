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

	printf("%s\n", c); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

char* string_concat(const char* a, const char* b) {
//	int z[] = {1, 3, 5, 7, 9, 11, 13};

//	printf("sizeof a: %d\n", sizeof(char) * strlen(a));
//	printf("sizeof b: %d\n", sizeof(char) * strlen(b));
	int sizeOfA = sizeof(char) * strlen(a);
	int sizeOfB = sizeof(char) * strlen(b);

	char* newString = malloc(sizeOfA + sizeOfB + 1);

	strcat(newString, a);
	strcat(newString, b);

//	printf("sizeof newString: %d\n", sizeof(char) * strlen(newString));
//	printf("sizeof newString: %d\n", sizeof(newString));
//	printf("sizeof z: %d\n", sizeof(z) / sizeof(int));

	return newString;
}

