#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int count;
pthread_rwlock_t rwlock;
void* read_fun(void* arg)
{
   while(1)
   {
      pthread_rwlock_rdlock(&rwlock);
	  printf("tid=%lu------read count=%d\n",pthread_self(),count);
	  pthread_rwlock_unlock(&rwlock); 
	  sleep(1); 
   } 
   return NULL;
} 
void* write_fun(void* arg)
{
    while(1)
	{
	   pthread_rwlock_wrlock(&rwlock);
	   count++;
	   printf("tid=%lu--------write count=%d\n",pthread_self(),count); 
	   pthread_rwlock_unlock(&rwlock);
	   sleep(2); 
	} 
} 
int main()
{
	pthread_t tid[8]; 	
	int i;
    
    pthread_rwlock_init(&rwlock,NULL);
	for(i=0;i<3;i++)
	{
	   pthread_create(&tid[i],NULL,write_fun,NULL);//创建子进程
	} 
    for(i=0;i<5;i++)
	{  
	   pthread_create(&tid[i+3],NULL,read_fun,NULL);//创建子进程
	} 
	for(i=0;i<8;i++)
	{
	  pthread_join(tid[i],NULL); 
	} 
	pthread_rwlock_destroy(&rwlock); 
   return 0;
} 
