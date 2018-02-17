#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
sem_t pro_sem;//生产者的条件变量
sem_t cus_sem;//消费者的条件变量

#define MAX 5 
int arr[MAX];

void* pro_fun(void* arg)
{
    srand(time(NULL)); 		
    int i=0;		
    while(1)
	{
	    sem_wait(&cus_sem);//--条件变量-- 
        arr[i]=rand() %100+1;
		printf("---pro---%d\n",arr[i]);
		sem_post(&pro_sem);//++ 
		i=(i+1)%MAX;
		sleep(rand()%3); 
	} 
} 
void* cus_fun(void* arg)
{
    srand(time(NULL)); 		
	int i=0;	
	while(1) 	
	{
			sem_wait(&pro_sem);//--条件变量-- 
		printf("---cus---%d\n",arr[i]);
		arr[i]=0; 
		sem_post(&cus_sem);//++ 
		i=(i+1)%MAX;
		sleep(rand()%3); 
     }
}  
int main()
{
  pthread_t pro,cus;

  sem_init(&cus_sem,0,MAX); 
  sem_init(&pro_sem,0,0); 
  pthread_create(&pro,NULL,pro_fun,NULL);//生产者
  pthread_create(&cus,NULL,cus_fun,NULL);//生产者

  pthread_join(pro,NULL);
  pthread_join(cus,NULL);

  sem_destroy(&pro_sem); 
  sem_destroy(&cus_sem); 

   return 0;
} 
