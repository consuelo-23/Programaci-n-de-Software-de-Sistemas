#include <stdio.h>
#include <string.h>
#include <pthread.h>

int a=0;


void *thread(void *ptr){
  for (int i=0; i<1000; i++){
    a +=1;

  }
  return NULL;
}

int main(){
  pthread_t thread1, thread2;


  pthread_create(&thread1, NULL, thread, NULL);
  pthread_create(&thread2, NULL, thread, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("a = %d\n", a);
  return 0;


}