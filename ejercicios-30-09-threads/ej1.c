#include <stdio.h>
#include <string.h>
#include <pthread.h>

// Definimos una varibale global
int i = 2;

//funcion de inicio de thread
void* foo(void* p){
  printf("valor p = %i\n", * (int*)p);

  // función de salida
  pthread_exit(&i);
}

int main(void){
  // Declaramos el objeto tread y su identificador
  pthread_t id;

  int j = 1;
  //funcion para iniciar el hilo
  pthread_create(&id, NULL, foo, &j);

  int* ptr;

  // funcion que espera a foo y devuelve el valor en ptr
  pthread_join(id, (void**)&ptr);
  printf("Valor recibido desde el hijo: ");
  printf("%i\n", *ptr);
}
