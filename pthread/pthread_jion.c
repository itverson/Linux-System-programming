#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void* pthread_fun(void* arg)
{ 
	  
  *(int*)arg=100;
  pthread_exit((void*)arg); 
} 
int main() 
{
     pthread_t tid;
	 int *arr=(int*)malloc(sizeof(int));
	 pthread_create(&tid,NULL,pthread_fun,(void*)arr); 
	 pthread_join(tid,(void**)&arr);
	 printf("----------%d\n",*arr); 
   return 0;
} 
