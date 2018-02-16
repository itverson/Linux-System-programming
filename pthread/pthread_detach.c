#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void* pthread_fun(void* arg)
{
   int n=3;
   while(n--)
   {
      printf("-------------%d--------\n",n);
	  sleep(1); 
   } 
   return (void*)1;
} 
int main()
{
   pthread_t tid;
   void* ret;
   int err;
   pthread_create(&tid,NULL,pthread_fun,NULL);
   pthread_detach(tid);//线程分离
   while(1) 
   {
		   err=pthread_join(tid,(void**)&ret);
   if(err!=0)
      fprintf(stderr,"use pthread_join   %s\n",strerror(err)); 
    else
	  printf("pthread_join success\n");
	
	sleep(1); 
   }
	  
   return 0;
} 
