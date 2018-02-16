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
   pthread_attr_t  attr;
   void* ret;
   int err;
   pthread_attr_init(&attr);//初始化属性
   pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);//设置分离状态，不分离是PTHREAD_CREATE_JOINABLE   
  // pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);//设置分离状态，不分离是PTHREAD_CREATE_JOINABLE   
   pthread_create(&tid,&attr,pthread_fun,NULL);
   while(1) 
   {
		   err=pthread_join(tid,(void**)&ret);
   if(err!=0)
      fprintf(stderr,"use pthread_join   %s\n",strerror(err)); 
    else
	  printf("pthread_join success\n");
	
	sleep(1); 
   }
	  pthread_attr_destroy(&attr); 
   return 0;
} 
