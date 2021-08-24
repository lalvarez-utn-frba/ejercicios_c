/*
 ============================================================================
 Name        : Ejercicio1.c
 Author      : joaco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "ejercicio.h"
#include"CUnit/Basic.h"

void test_ejercicio_1_1 ();
void test_ejercicio_1_2 ();
void test_ejercicio_1_3 ();

int main (void) {



	CU_initialize_registry(); // Inicializa los registros

	CU_pSuite prueba=CU_add_suite("Suitedeprueba",NULL,NULL); // Crea una suite de prueba
	CU_add_test(prueba,"Pruebo string_concat, para concatenar dos cadenas",test_ejercicio_1_1); // le agrega un test a la suite
	CU_add_test(prueba,"Pruebo string_concat_dinamyc",test_ejercicio_1_2); // le agrega un test a la suite
	CU_add_test(prueba,"Pruebo mail_split",test_ejercicio_1_3); // le agrega un test a la suite

	CU_basic_set_mode(CU_BRM_VERBOSE); // Hace algo... es necesario.
	CU_basic_run_tests(); // Corre los tests
	CU_cleanup_registry(); // Borra la memoria de los tests


	return CU_get_error();

}

void test_ejercicio_1_1 () {


	const char* cadena1 = "Hola";
	const char* cadena2 = "Mundo!";

	puts("TESTEANDO!");
	puts(string_concat(cadena1, cadena2));


	CU_ASSERT_STRING_EQUAL(string_concat(cadena1, cadena2),"HolaMundo!");



}

void test_ejercicio_1_2 () {

	const char* cadena1 = "Hola";
	const char* cadena2 = "Mundo!";


	char** saludo_completo;
	saludo_completo = malloc(sizeof(char**));
	string_concat_dinamyc(cadena1, cadena2, saludo_completo);

	//puts("resultado");
	//puts(*saludo_completo);

	CU_ASSERT_STRING_EQUAL( *saludo_completo ,"HolaMundo!")


	free(saludo_completo);

}

void test_ejercicio_1_3 () {

	char* mailCompleto = "joaquinipar@miDominio.com";
	char** usuario;
	char** dominio;
	usuario= malloc(sizeof(char**));
	dominio = malloc(sizeof(char**));
	//puts(mailCompleto);

	mail_split(mailCompleto, usuario, dominio);

	CU_ASSERT_STRING_EQUAL( *usuario ,"joaquinipar");
	//CU_ASSERT_STRING_EQUAL( *dominio, "miDominio");

}



