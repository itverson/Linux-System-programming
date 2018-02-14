#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
int n=0;int flag=0;
void catch_parent(int num)//父进程收到信号然后打印数字
{
    printf("i am parent pid=%d,  %d\n",getpid(),n);
    flag=1;
	n+=2;
} 
void catch_child(int num)
{
		
   printf("i am child pid=%d,  %d\n",getpid(),n);
   flag=1;
   n+=2;
} 
int main()                      
{
   pid_t pid;
	struct sigaction old;
   pid=fork();
   if(pid>0)//父进程
   {	 
    n=1;
	old.sa_handler=catch_parent;
	sigemptyset(&old.sa_mask);
    old.sa_flags=0; 
	sleep(1); 
	catch_parent(0);
    sigaction(SIGUSR2,&old,NULL);  
    while(1)
	{
			
       if(flag==1)//flag==1说明父进程任务已经完成了
	   {
	      kill(pid,SIGUSR1);
		  flag=0; 		  
	   }
	} 
   } else if(pid==0)
   {
	  n=2;   
     old.sa_handler=catch_child;
	sigemptyset(&old.sa_mask);
   old.sa_flags=0;
   sigaction(SIGUSR1,&old,NULL);
   while(1)
   {
        if(flag==1)
		{
		    kill(getppid(),SIGUSR2);
			flag=1;
		} 
   } 
  } 
   return 0;
} 
