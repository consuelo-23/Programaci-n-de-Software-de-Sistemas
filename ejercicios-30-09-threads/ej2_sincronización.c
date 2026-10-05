#include <stdio.h>
#include <pthread.h>

int saldo =100;
pthread_mutex_t m;

void *depositar(void *ptr){
  int *p = (int *) ptr;
  int dinero = *p;

  pthread_mutex_lock(&m);
  saldo+= dinero;
  pthread_mutex_unlock(&m);
  return NULL;

}

void *girar(void *ptr){ //que pasa si tenemos 2 threads quieren retirar al mismo tiempo?
  int *p = (int *) ptr;
  int dinero = *p;

  pthread_mutex_lock(&m);
  if(saldo >= dinero){
    saldo -= dinero;
    return NULL;
  }
  else{
    printf("No hay saldo disponible\n");
  }
  pthread_mutex_unlock(&m);

}


int main(){
  pthread_t thread1, thread2;
  pthread_mutex_init(&m,NULL);

  int giro = 50;
  pthread_create(&thread1, NULL, girar, &giro);
  pthread_create(&thread2, NULL, girar, &giro);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("saldo = %d\n", saldo);
  return 0;
}
