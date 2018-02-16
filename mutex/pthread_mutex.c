#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t mutex;
void* pthread_fun(void* arg)
{
		srand(time(NULL));
    while(1) 
	{   
		pthread_mutex_lock(&mutex); 	
			printf("hello ");
	   sleep(rand()%3); 
        printf("world\n");
		pthread_mutex_unlock(&mutex); 
		sleep(rand()%3);
		
	}
	return NULL;
} 
int main()
{
   pthread_t tid;
		   srand(time(NULL)); 
   pthread_mutex_init(&mutex,NULL); 		   
   pthread_create(&tid,NULL,pthread_fun,NULL);
   while(1) 
   {
		   pthread_mutex_lock(&mutex);//上锁  
		   printf("HELLO ");
          sleep(rand()%3);
         printf("WORLD\n");
		 pthread_mutex_unlock(&mutex); 
         sleep(rand()%3); 
   }
   pthread_mutex_destroy(&mutex); 
    return 0;
} 
