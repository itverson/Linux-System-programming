#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
void* pthread_fun(void *arg)
{
   int i=(int)arg; 		 
   printf("i am %d pthrad id=%lu   process id=%d\n",i+1,pthread_self(),getpid());
   return NULL;
} 
int main()
{
  pthread_t tid;
  int i;
  for(i=0;i<10;i++) 
{
		int ret=pthread_create(&tid,NULL,pthread_fun,(void*)i);
  if(ret!=0)//等于0成功
  {
     fprintf(stderr,"errno pthread_create%s",strerror(ret));
	 exit(1); 
  }
  sleep(1); 
}

   return 0;
} 
