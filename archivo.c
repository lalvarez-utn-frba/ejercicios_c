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
 *
 * exponer otra operación que dada una lista y una función,
 * itere la lista y escriba sobre el archivo abierto lo
 *  que devuelve dicha función (string).
 *
 */


void destructorDeComidas(t_link_element* elem){

	printf("Destruyendo: %s",(char*) (elem->data) );
	puts( (char*) (elem->data) );
	free(elem->data);
	free(elem);

}

void aplicar_func_lista_en_file ( t_list* lista, char* (*funcion)( char*), archivo archivo ){

	if(archivo.esta_abierto == 1 && archivo.modo == APPEND){

		t_list* nueva_lista; // no malloqueo, se encarga list_map



		nueva_lista = list_map(lista, (void*) funcion); // me devuelve la lista iterada

		puts("hola");

		t_list_iterator* iterador = list_iterator_create(nueva_lista);

		list_iterator_next(iterador);

		while(list_iterator_has_next(iterador)){

			puts((char*) (iterador->element->data));
			fwrite( (char*) (iterador->element->data), sizeof(char), strlen(iterador->element->data), archivo.puntero_archivo);

			list_iterator_next(iterador);
		}



		/*
		t_link_element* sig;
		sig = nueva_lista->head;

		while( sig->next != NULL ){
		//fwrite(nueva_lista->head, sizeof(nueva_lista->head), archivo.puntero_archivo);
			puts((char*) (sig->data));
			fwrite( (char*) (sig->data), sizeof(char), strlen(sig->data), archivo.puntero_archivo);

			sig->data = sig->next->data;
			sig-> next = (sig->next)->next;

			printf("proximo %s:", sig->data);

			if( sig->next == NULL){

				puts((char*) (sig->data));
				fwrite( (char*) (sig->data), sizeof(char), strlen(sig->data), archivo.puntero_archivo);

				}


			}
	*/


		list_destroy_lista_con_contenido(nueva_lista);
		list_iterator_destroy(iterador);
	//list_destroy_and_destroy_elements(&nueva_lista, (void*) destructorDeComidas);
	//list_destroy(nueva_lista); // libero la memoria de nueva_lista ( list_map hizo malloc)
	//free(sig->next);
	//free(sig->data);
	//free(sig);
		}

}

void list_destroy_lista_con_contenido(t_list *self) {
	list_clean_contenidos(self);
	free(self);
}

void list_clean_contenidos(t_list *self) {
	t_link_element* elemento;
	while (self->head != NULL) {
		elemento = self->head;
		self->head = self->head->next;
		free(elemento->data);
		free(elemento);
	}
	self->elements_count = 0;
}

void llenarLista(t_list* lista){

	list_add(lista, "PIZZA");
	list_add(lista, "HAMBURGUESA");
	list_add(lista, "ASADO");
	list_add(lista, "ARROZ");
	list_add(lista, "FIDEO");



}


/*
 *  exponer una operación que reciba una función
 *  y la ejecute por cada línea del archivo
 *
 */

void aplicar_funcion_archivo( char* (*funcion)(char*), archivo archivo){

	puts("Estoy en aplicar_funcion_archivo");

	char* linea = 0;
	size_t tamanio = 0;
	ssize_t bytes_leidos = 0;
	int contador = 0;
	//char* temp = string_new();
	//char* resultado = string_new();

	while( (bytes_leidos = getline(&linea, &tamanio, archivo.puntero_archivo) ) != -1 ){

		/*
		char* saludo = malloc(sizeof(char*));

		strcpy(saludo, "Hola!!!");

		string_append(&linea);

		strcat(linea, "\0");
*/

		funcion(linea);

		//strcat(linea, "\0");

		puts(linea);

		//free(saludo);

		contador++;
	}

	free(linea);

}

void pasameAMinuscula(char* original){


		//string_append(&original, "HOLA!!!");

		//printf("%s", original);

		string_to_lower(original);

	}



void append_char( char* s,  char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}



