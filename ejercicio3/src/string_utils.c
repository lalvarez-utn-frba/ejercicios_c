/*
 * string_utils.c
 *
 *  Created on: 28 ago. 2021
 *      Author: utnso
 */

#include "string_utils.h"


int string_bytes_size(char* string) {
	return sizeof(char) * (strlen(string) + 1);
}

void string_copy(char** dest, char* origin) {
	*dest = malloc((strlen(origin) + 1) * sizeof(char));
	strcpy(*dest, origin);
	strcat(*dest, "\0");
}
