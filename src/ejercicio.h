#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* string_concat(const char*, const char*);
size_t memoria_total_concat(const char* cadena1,const char* cadena2);
void string_concat_dinamyc( char*,  char*, char**);
void mail_split( char* mail,  char** user,  char** dominio);
void append_char( char* s,  char c) ;
