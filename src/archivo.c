#include "archivoC.h"


archivo abrir_archivo (char* path, modo_lectura modo){ // return 0 OK! ; return -1 ERROR! abriendo el archivo

	archivo nuevo_archivo;
	//nuevo_archivo.ruta = malloc(sizeof(char) * strlen(path));
	nuevo_archivo.ruta = path;
	strcat(nuevo_archivo.ruta, "\0");

	switch(modo){

		case(READ): // CASO READ
			puts("Ruta adentro: ");
			puts(nuevo_archivo.ruta);
			nuevo_archivo.puntero_archivo = fopen(nuevo_archivo.ruta, "r");
			puts("Se abrio archivo");
			break;
		case(WRITE): // CASO WRITE
		nuevo_archivo.puntero_archivo =fopen(nuevo_archivo.ruta, "w");
			break;
		case(APPEND): // CASO APPEND
		nuevo_archivo.puntero_archivo = fopen(nuevo_archivo.ruta, "a");
			break;
	}


	if( nuevo_archivo.puntero_archivo == NULL ){
		if (!nuevo_archivo.puntero_archivo)perror("fopen"); // Tira el error en consola
		printf("No se pudo abrir archivo");
	}
	nuevo_archivo.modo = modo;
	nuevo_archivo.esta_abierto = 1;

	return nuevo_archivo;
}

void cerrar_archivo(archivo* archivo){

	fclose(archivo->puntero_archivo);
}

/*
void leer_lineas(archivo* archivo){

	char* caracteres = "";
	char caracter;

	 if(archivo->puntero_archivo == NULL) {
	      perror("Error in opening file");
	      //return -1;
	   } do {
		   caracter = fgetc(archivo->puntero_archivo);
	      if( feof(archivo->puntero_archivo) ) {
	         break ;
	      }
	      printf("%c", caracter);
	   } while(1);
	  puts("");
	  puts(caracteres);


}
*/

char* leer_linea(archivo archivo, int numero_linea){

	puts("Estoy en leer linea");

	char* linea = 0;
	size_t tamanio = 0;
	ssize_t bytes_leidos = 0;
	int contador = 0;

	while( (bytes_leidos = getline(&linea, &tamanio, archivo.puntero_archivo) ) != -1 &&
			contador < numero_linea){

		contador++;
	}

	   return linea;
}



/*
void append_char( char* s,  char c) {
        int len = strlen(s)
        s[len] = c;
        s[len+1] = '\0';
}
*/

