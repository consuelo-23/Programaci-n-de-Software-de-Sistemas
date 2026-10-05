#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>



// declaramos una variable global para ser usada en los hilos
int g = 0;

// funcion ejecutada por los hilos
void *mihilofun(void *vargp)
{
	// guardamos el id del hilo
	int *myid = (int *)vargp;

	// inicializamos una variable local
	 int s = 0;

	// cambiamos la variable local y global
  //	++s; ++g;
  int iter=rand() % 50;

  //incrementamos la variable global en inter
  for(int j=0; j< iter; j++) ++s, ++g;
	// imprimimos ambas variables
	printf("ID Hilo: %d, Local: %d, Global: %d Random:%d\n", abs(*myid), s, g,iter);
}

//crea 5 hilos de manera dimamica y ejecuta la funcion mihilofun
int main()
{
  int numero_hilos=5;
  pthread_t *tid=(pthread_t *)malloc(numero_hilos * sizeof(pthread_t));
	// creamos 5 hilos
	for (int i = 0; i < numero_hilos; i++){
		//pthread_create(&tid, NULL, mihilofun, (void *)&tid);
    int err = pthread_create(&tid[i], NULL, &mihilofun, (void *)&(tid[i]));
    if (err != 0){
        printf("\ncan't create thread :[%s]", strerror(err));
    }
  }
  //esperamos que los hilos terminen
  for(int i=0; i< numero_hilos; ++i) pthread_join(tid[i], NULL);

printf("come back to main\n");
return 0;
}