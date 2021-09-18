#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

pthread_t hilos[2];
sem_t sem_proveedor;
sem_t sem_consumidor;
int stock_total; // sección crítica

void* comprar_cinco_productos(){

	for(int i = 0; i < 15 ; i++){

		puts("Espero a que se libere sem_proveedor");

		sem_wait(&sem_proveedor); // bloqueo al proveedor mientras disminuyo el stock

		stock_total-=1; // disminuyo una unidad de stock

		printf("%i: Resté una unidad de stock. Stock actual: %i\n", i, stock_total);

		sem_post(&sem_consumidor); // desbloqueo al consumidor ya que realizo su accion

		puts("Libero sem_consumidor");
	}
	return NULL;

}

void* reponer_diez_productos(){

	for(int i = 0; i < 10; i++){

		puts("Espero a que se libere sem_consumidor");

		sem_wait(&sem_consumidor); // bloqueo al consumidor mientras aumento el stock

		stock_total+=1;

		printf("%i:Sume una unidad de stock. Stock actual: %i\n", i ,stock_total);

		sem_post(&sem_proveedor); // desbloqueo al proveedor ya que termino su accion

		puts("Libero sem_proveedor");

	}

	return NULL;
}


int main (){


	int error;

	sem_init(&sem_proveedor,0, 0 ); // inicia desbloqueado

	sem_init(&sem_consumidor,0, 1); // inicia bloqueado

	error = pthread_create(&(hilos[0]), NULL, reponer_diez_productos, NULL);

	error != 0 ? puts("error al crear thread 0") : puts("se creo el thread 0");

	error = pthread_create(&(hilos[1]), NULL, comprar_cinco_productos, NULL);

	error != 0 ? puts("error al crear thread 1") : puts("se creo el thread 1");

	pthread_join(hilos[0], NULL); // espera a que termine el hilo 0
	puts("Termino el hilo 0");
	pthread_join(hilos[1], NULL); // espera a que termine el hilo 1
	puts("termino el hilo 1");
	sem_destroy(&sem_proveedor);
	sem_destroy(&sem_consumidor);

	puts("Destruido!");

	return stock_total;

}
