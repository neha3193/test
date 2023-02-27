#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
  #include <semaphore.h>

sem_t sem;
void* start (void *i)
{
	sem_wait(&sem);
	printf("hello:%d\n", *(int*)i);
	sem_post(&sem);
}

int main()
{
	int i;
	pthread_t t[8];
	sem_init(&sem, 0, 1);
	for(i=0;i<8;i++){
	pthread_create(&t[i],NULL, &start,(void*)&i);
	printf("i=%d\n",i);
  }
	printf("finish\n");
	for(i=0;i<8;i++){
	printf("i=%d\n",i);
	pthread_join(&t[i], NULL);
}
}

