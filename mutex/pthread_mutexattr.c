//演示进程间同步
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/mman.h>
#include<string.h>
struct process
{
    int count;
	pthread_mutex_t mutex;
	pthread_mutexattr_t attr;
};
int main()
{
   pid_t pid;
   struct process *p;
   p=mmap(NULL,sizeof(struct process),PROT_WRITE | PROT_READ,MAP_SHARED | MAP_ANONYMOUS,-1,0);//建立匿名映射区 
   if(p==MAP_FAILED)
   {
      perror("use mmap");
	  exit(1); 
   } 
   memset(p,0,sizeof(*p));//初始化映射区 
   pthread_mutexattr_init(&p->attr);//初锁的属性
    pthread_mutexattr_setpshared(&p->attr, PTHREAD_PROCESS_SHARED); //设置锁为进程间使用
   pthread_mutex_init(&p->mutex,&p->attr);//初始化锁
    pid=fork();
	if(pid==0)//子进程
	{ 
		int i;
	    for(i=0;i<10;i++)
		{
		     pthread_mutex_lock(&p->mutex);
			 p->count++;
			 printf("child----count=%d\n",p->count);
			 pthread_mutex_unlock(&p->mutex);
			 sleep(1); 
		} 
	} else if(pid>0)
	{
	   int i;
	   for(i=0;i<10;i++)
	   {
	       pthread_mutex_lock(&p->mutex);
		   p->count+=2;
		   printf("parent----count=%d\n",p->count);
		   pthread_mutex_unlock(&p->mutex);
		   sleep(1); 
	   } 
	} 
	pthread_mutexattr_destroy(&p->attr);
	return 0;
} 
