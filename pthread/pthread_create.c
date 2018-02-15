#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void* pthread_fun(void *arg)
{
   printf("pthrad id=%lu   process id=%d\n",pthread_self(),getpid());
   return NULL;
} 
int main()
{
  pthread_t tid;
  printf("main1 pthrad id=%lu   process id=%d\n",pthread_self(),getpid());
  int ret=pthread_create(&tid,NULL,pthread_fun,NULL);
  if(ret!=0)//等于0成功
  {
     printf("errno pthread_create");
	 exit(1); 
  } 
  sleep(1); 
   printf("main2 pthrad id=%lu   process id=%d\n",pthread_self(),getpid());
   return 0;
} 
