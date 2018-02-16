#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
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
 pthread_t attr;
 int ret;
 int count=0;
 while(1) 
 {
		ret=pthread_create(&attr,NULL,pthread_fun,NULL); 
		if(ret!=0)
		{
		   fprintf(stderr,"use creat  %s",strerror(ret));
		   exit(1); 
		} 	
		printf("%d\n",++count); 
 }		
   return 0;
} 
