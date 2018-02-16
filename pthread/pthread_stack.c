#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#define MAX 0x00000001
void* pthread_fun(void* arg)
{
	
		while(1)//
		{
		  ;
		} 
   return NULL; 
} 
int main()
{
 pthread_t tid;
 pthread_attr_t attr;
 int size;
 void *stackaddr;
 int ret;
 int count=0;
 int detach;
 pthread_attr_init(&attr);//初始化
 pthread_attr_getstack(&attr,&stackaddr,&count);//void* 取地址就是void** int取地址就是int*
 pthread_attr_getdetachstate(&attr,&detach);
 if(detach==PTHREAD_CREATE_DETACHED)
		 printf("默认分离状态\n");
 else
	printf("默认不分离状态\n");
 printf("默认地址空间为 %0x",stackaddr); 
 while(1) 
 {
		stackaddr=NULL; 
        stackaddr=malloc(MAX);//申请空间
		if(stackaddr==NULL)
		{
		   perror("use malloc");
		   exit(1); 
		} 
		pthread_attr_setstack(&attr,stackaddr,MAX);//设置线程栈的大小 
		ret=pthread_create(&tid,&attr,pthread_fun,NULL); //创建设置后的线程栈的大小
		if(ret!=0)
		{
		   fprintf(stderr,"use creat  %s",strerror(ret));
		   exit(1); 
		} 	
		printf("%d\n",++count); 
 }		
   return 0;
} 
